/*
**	Command & Conquer Renegade(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "loadbmp.h"

LoadBmp::LoadBmp()
{
    BitmapHandle_ = nullptr;
    PalHandle_ = nullptr;
}

LoadBmp::~LoadBmp()
{
    // free resources
    DeleteObject(BitmapHandle_);
    DeleteObject(PalHandle_);
}

//
//  Load a specified bitmap for later display on a window
//
bit8 LoadBmp::init(char* filename, HWND hwnd)
{
    int i;
    HANDLE hBitmapFile;
    DWORD dwRead;
    BITMAPFILEHEADER bitmapHeader;
    BITMAPINFOHEADER bitmapInfoHeader;
    LPLOGPALETTE lpLogPalette;
    char* palData;
    HGLOBAL hmem2;
    LPVOID lpvBits;
    HDC hdc;
    HPALETTE select;
    UINT realize;
    RECT rect;

    // Set the member for future reference
    WindowHandle_ = hwnd;

    // Retrieve a handle identifying the file.
    hBitmapFile = CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, (LPSECURITY_ATTRIBUTES)nullptr,
                             OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, (HANDLE)nullptr);

    // Exit early if the file failed to open
    if (hBitmapFile == INVALID_HANDLE_VALUE) {
        return (FALSE);
    }

    // Retrieve the BITMAPFILEHEADER structure.
    ReadFile(hBitmapFile, &bitmapHeader, sizeof(BITMAPFILEHEADER), &dwRead, (LPOVERLAPPED)nullptr);

    // Retrieve the BITMAPFILEHEADER structure.
    ReadFile(hBitmapFile, &bitmapInfoHeader, sizeof(BITMAPINFOHEADER), &dwRead, (LPOVERLAPPED)nullptr);

    // Allocate memory for the BITMAPINFO structure.
    HGLOBAL infoHeaderMem = GlobalAlloc(
        GHND, sizeof(BITMAPINFOHEADER) + ((1 << bitmapInfoHeader.biBitCount) * sizeof(RGBQUAD)));

    LPBITMAPINFO lpHeaderMem = (LPBITMAPINFO)GlobalLock(infoHeaderMem);

    // Load BITMAPINFOHEADER into the BITMAPINFO structure.
    lpHeaderMem->bmiHeader.biSize = bitmapInfoHeader.biSize;
    lpHeaderMem->bmiHeader.biWidth = bitmapInfoHeader.biWidth;
    lpHeaderMem->bmiHeader.biHeight = bitmapInfoHeader.biHeight;
    lpHeaderMem->bmiHeader.biPlanes = bitmapInfoHeader.biPlanes;
    lpHeaderMem->bmiHeader.biBitCount = bitmapInfoHeader.biBitCount;
    lpHeaderMem->bmiHeader.biCompression = bitmapInfoHeader.biCompression;
    lpHeaderMem->bmiHeader.biSizeImage = bitmapInfoHeader.biSizeImage;
    lpHeaderMem->bmiHeader.biXPelsPerMeter = bitmapInfoHeader.biXPelsPerMeter;
    lpHeaderMem->bmiHeader.biYPelsPerMeter = bitmapInfoHeader.biYPelsPerMeter;
    lpHeaderMem->bmiHeader.biClrUsed = bitmapInfoHeader.biClrUsed;
    lpHeaderMem->bmiHeader.biClrImportant = bitmapInfoHeader.biClrImportant;

    // Retrieve the color table.
    // 1 << bitmapInfoHeader.biBitCount == 2 ^ bitmapInfoHeader.biBitCount
    ReadFile(hBitmapFile, lpHeaderMem->bmiColors,
             ((1 << bitmapInfoHeader.biBitCount) * sizeof(RGBQUAD)), &dwRead, (LPOVERLAPPED)nullptr);

    lpLogPalette = (LPLOGPALETTE) new char[(sizeof(LOGPALETTE) + sizeof(PALETTEENTRY) * 256)];
    lpLogPalette->palVersion = 0x300;
    lpLogPalette->palNumEntries = 256;

    palData = (char*)lpHeaderMem->bmiColors;

    for (i = 0; i < 256; i++) {
        lpLogPalette->palPalEntry[i].peRed = *palData++;
        lpLogPalette->palPalEntry[i].peGreen = *palData++;
        lpLogPalette->palPalEntry[i].peBlue = *palData++;
        lpLogPalette->palPalEntry[i].peFlags = *palData++;
    }
    PalHandle_ = CreatePalette(lpLogPalette);
    delete (lpLogPalette);

    // Allocate memory for the required number of bytes.
    hmem2 = GlobalAlloc(GHND, (bitmapHeader.bfSize - bitmapHeader.bfOffBits));

    lpvBits = GlobalLock(hmem2);

    // Retrieve the bitmap data.
    ReadFile(hBitmapFile, lpvBits, (bitmapHeader.bfSize - bitmapHeader.bfOffBits), &dwRead,
             (LPOVERLAPPED)nullptr);

    // Create a bitmap from the data stored in the .BMP file.
    hdc = GetDC(hwnd);
    select = SelectPalette(hdc, PalHandle_, 0);
    if (select == nullptr) {
        return (FALSE);
    }
    realize = RealizePalette(hdc);
    if (realize == GDI_ERROR) {
        return (FALSE);
    }
    BitmapHandle_
        = CreateDIBitmap(hdc, &bitmapInfoHeader, CBM_INIT, lpvBits, lpHeaderMem, DIB_RGB_COLORS);
    ReleaseDC(hwnd, hdc);

    if (BitmapHandle_ == nullptr) {
        return (FALSE);
    }

    // Unlock the global memory objects and close the .BMP file.
    GlobalUnlock(infoHeaderMem);
    GlobalUnlock(hmem2);
    CloseHandle(hBitmapFile);

    if (BitmapHandle_ == nullptr) {
        return (FALSE);
    }

    // Inform windows the window needs to be repainted
    GetClientRect(hwnd, &rect);
    InvalidateRect(hwnd, &rect, TRUE);
    UpdateWindow(hwnd);

    return (TRUE);
}

bit8 LoadBmp::drawBmp(void)
{
    // Paint the window (and draw the bitmap).

    PAINTSTRUCT ps;
    HDC hdc;
    char string[128];

    if (BitmapHandle_ == nullptr) {
        return (FALSE);
    }

    InvalidateRect(WindowHandle_, nullptr, FALSE); // keep windows from screwing up the
                                                //  redrawing (as much).
    hdc = BeginPaint(WindowHandle_, &ps);

    // Do palette stuff
    HPALETTE select = SelectPalette(ps.hdc, PalHandle_, 0);
    if (select == nullptr) {
        sprintf(string, "Select Pal Fail: %d", GetLastError());
        MessageBox(nullptr, string, "OK", MB_OK);
    }
    UINT realize = RealizePalette(ps.hdc);
    if (realize == GDI_ERROR) {
        sprintf(string, "Realize Pal Fail: %d", GetLastError());
        MessageBox(nullptr, string, "OK", MB_OK);
    }

    HDC hdcMem = CreateCompatibleDC(ps.hdc);
    SelectObject(hdcMem, BitmapHandle_);
    BITMAP bm;
    GetObject(BitmapHandle_, sizeof(BITMAP), (LPSTR)&bm);

    /// for non-stretching version
    ///////BitBlt(ps.hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);

    RECT clientRect;
    GetClientRect(WindowHandle_, &clientRect);
    SetStretchBltMode(ps.hdc, COLORONCOLOR);
    StretchBlt(ps.hdc, 0, 0, clientRect.right, clientRect.bottom, hdcMem, 0, 0, bm.bmWidth,
               bm.bmHeight, SRCCOPY);

    DeleteDC(hdcMem);
    EndPaint(WindowHandle_, &ps);
    return (TRUE);
}
