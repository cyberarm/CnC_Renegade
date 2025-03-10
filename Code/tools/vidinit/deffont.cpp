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

/* $Header: /G/Tools/vidinit/deffont.cpp 1     4/17/00 5:40p Phil_g3 $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : G                                                            *
 *                                                                                             *
 *                    File Name : DEFFONT.CPP                                                  *
 *                                                                                             *
 *                   Programmer : Scott Kenneth Bowen                                          *
 *                                                                                             *
 *                   Start Date : 01/24/00                                                     *
 *                                                                                             *
 *                  Last Update : February 2, 2000 [SKB]                                       *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   *Load_Font_Data -- Load up font data from a file.                                         *
 *   Load_Default_Font_Data -- Loads up the data for the default fonts.                        *
 *   Release_Default_Font_Data -- Free up the font data stuff.                                 *
 *   *Build_Font_Palette_From_Ramp -- Create a font palette given a 0.0 - 1.0 value            *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

////////////////////////////////////////////////////////////////////////////////////////////////////
// Include files ///////////////////////////////////////////////////////////////////////////////////

#include "defpal.h"
#include "stdafx.h"
#include <wwfont.h>
////////////////////////////////////////////////////////////////////////////////////////////////////
// Local Defines ///////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
// Static Data /////////////////////////////////////////////////////////////////////////////////////

// Define a default font for the program in case one has been loaded from disk.
#pragma warning(disable : 4305 4309)
char DefaultFontData[] = {
    242, 22, 0,   5,  14,  0,  20,  0,  216, 1,  186, 2,  46,  21, 18,  16, 0,   225, 11,  10,
    186, 2,  214, 2,  186, 2,  3,   3,  186, 2,  186, 2,  186, 2,  186, 2,  186, 2,   186, 2,
    186, 2,  186, 2,  186, 2,  186, 2,  186, 2,  186, 2,  27,  3,  72,  3,  186, 2,   186, 2,
    186, 2,  186, 2,  186, 2,  186, 2,  117, 3,  162, 3,  186, 2,  186, 2,  186, 2,   186, 2,
    117, 3,  162, 3,  207, 3,  207, 3,  225, 3,  186, 2,  237, 3,  17,  4,  62,  4,   98,  4,
    113, 4,  140, 4,  167, 4,  202, 4,  230, 4,  245, 4,  254, 4,  10,  5,  50,  5,   86,  5,
    113, 5,  149, 5,  185, 5,  221, 5,  1,   6,  37,  6,  73,  6,  109, 6,  145, 6,   169, 6,
    196, 6,  232, 6,  252, 6,  32,  7,  68,  7,  113, 7,  149, 7,  185, 7,  221, 7,   1,   8,
    37,  8,  73,  8,  109, 8,  145, 8,  163, 8,  199, 8,  235, 8,  15,  9,  60,  9,   50,  5,
    96,  9,  132, 9,  168, 9,  204, 9,  240, 9,  20,  10, 56,  10, 92,  10, 137, 10,  173, 10,
    209, 10, 245, 10, 16,  11, 56,  11, 83,  11, 103, 11, 118, 11, 133, 11, 161, 11,  197, 11,
    225, 11, 5,   12, 33,  12, 69,  12, 105, 12, 141, 12, 159, 12, 189, 12, 145, 8,   225, 12,
    4,   13, 32,  13, 60,  13, 96,  13, 132, 13, 160, 13, 188, 13, 215, 13, 243, 13,  15,  14,
    50,  14, 78,  14, 114, 14, 142, 14, 169, 14, 187, 14, 214, 14, 239, 14, 23,  15,  67,  15,
    103, 15, 139, 15, 175, 15, 211, 15, 247, 15, 27,  16, 59,  16, 95,  16, 131, 16,  167, 16,
    194, 16, 221, 16, 248, 16, 28,  17, 64,  17, 100, 17, 135, 17, 180, 17, 216, 17,  252, 17,
    28,  18, 64,  18, 100, 18, 144, 18, 180, 18, 216, 18, 252, 18, 32,  19, 77,  19,  117, 19,
    167, 19, 203, 19, 230, 19, 10,  20, 46,  20, 82,  20, 127, 20, 163, 20, 191, 20,  0,   0,
    0,   0,  0,   0,  0,   0,  141, 12, 0,   0,  0,   0,  0,   0,  0,   0,  0,   0,   0,   0,
    0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,   0,   0,
    0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,   0,   0,
    0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  227, 20, 0,   0,   0,   0,
    0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,   0,   0,
    0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  6,   21, 8,   10, 8,   8,  8,   8,   8,   8,
    8,   8,  8,   8,  8,   8,  8,   8,  10,  10, 8,   8,  8,   8,  8,   8,  10,  10,  8,   8,
    8,   8,  10,  10, 6,   4,  6,   8,  8,   10, 7,   5,  6,   6,  9,   8,  5,   6,   5,   9,
    8,   6,  8,   8,  8,   8,  8,   8,  8,   8,  5,   5,  7,   7,  7,   7,  10,  8,   8,   8,
    8,   7,  7,   8,  8,   4,  7,   8,  7,   10, 8,   8,  8,   8,  8,   8,  8,   8,   8,   10,
    8,   8,  8,   6,  9,   6,  8,   10, 6,   8,  8,   8,  8,   8,  7,   8,  8,   4,   6,   7,
    4,   10, 8,   8,  8,   8,  8,   8,  6,   8,  8,   10, 8,   8,  8,   6,  4,   6,   9,   9,
    8,   8,  8,   8,  8,   8,  8,   8,  8,   8,  8,   6,  6,   5,  8,   8,  7,   10,  10,  8,
    8,   8,  8,   8,  8,   8,  8,   7,  8,   9,  8,   9,  8,   5,  8,   8,  8,   9,   8,   8,
    8,   0,  0,   0,  0,   4,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,   0,   0,
    0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,   0,   10,
    0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   0,  0,   8,   48,  51,
    51,  0,  51,  33, 33,  3,  19,  17, 17,  2,  35,  33, 33,  2,  19,  17, 17,  2,   35,  33,
    33,  2,  48,  34, 34,  0,  48,  51, 51,  3,  0,   51, 17,  17, 50,  51, 19,  34,  34,  17,
    17,  19, 2,   48, 34,  34, 19,  2,  0,   0,  0,   19, 2,   0,  0,   0,  19,  50,  51,  51,
    51,  19, 17,  17, 17,  17, 35,  34, 34,  34, 34,  0,  0,   51, 3,   0,  48,  19,  2,   51,
    51,  33, 2,   19, 18,  34, 0,   35, 33,  2,  0,   48, 34,  0,  0,   0,  48,  51,  0,   0,
    0,   48, 33,  3,  0,   0,  48,  17, 50,  0,  51,  51, 17,  33, 3,   19, 17,  17,  17,  2,
    35,  34, 17,  33, 2,   0,  48,  17, 34,  0,  0,   48, 33,  2,  0,   0,  48,  34,  0,   0,
    0,   48, 51,  0,  0,   0,  51,  33, 0,   0,  48,  19, 33,  0,  0,   51, 17,  33,  51,  3,
    19,  17, 17,  17, 2,   35, 17,  33, 34,  2,  48,  18, 33,  0,  0,   0,  35,  33,  0,   0,
    0,   48, 34,  0,  0,   0,  48,  51, 0,   0,  0,   51, 33,  3,  0,   48, 19,  17,  50,  0,
    51,  17, 17,  33, 3,   19, 17,  17, 17,  2,  51,  51, 33,  34, 2,   0,  48,  33,  0,   0,
    0,   48, 33,  0,  0,   0,  48,  34, 0,   0,  0,   48, 51,  0,  0,   0,  48,  33,  0,   0,
    0,   48, 33,  0,  0,   51, 51,  33, 51,  3,  19,  17, 17,  17, 2,   35, 17,  17,  33,  2,
    48,  18, 17,  34, 0,   0,  35,  33, 2,   0,  0,   48, 34,  0,  0,   51, 3,   19,  2,   19,
    2,   19, 2,   19, 2,   19, 2,   35, 2,   19, 2,   35, 2,   51, 51,  3,  19,  18,  2,   19,
    18,  2,  35,  34, 2,   0,  51,  3,  0,   48, 19,  50, 3,   51, 17,  17, 2,   19,  18,  34,
    2,   35, 17,  33, 3,   51, 18,  18, 2,   19, 17,  33, 2,   35, 18,  34, 0,   0,   35,  2,
    0,   48, 51,  0,  51,  3,  51,  33, 51,  19, 2,   19, 18,  50, 33,  2,  35,  33,  18,  34,
    0,   48, 34,  33, 50,  0,  48,  19, 34,  33, 3,   51, 33,  18, 18,  2,  19,  34,  35,  33,
    2,   35, 2,   48, 34,  0,  48,  51, 0,   0,  51,  33, 3,   0,  19,  18, 2,   0,   19,  18,
    2,   0,  35,  33, 50,  0,  19,  18, 33,  0,  19,  18, 34,  0,  35,  17, 33,  0,   48,  34,
    34,  0,  48,  51, 0,   51, 33,  0,  19,  33, 0,   19, 34,  0,  35,  2,  0,   0,   51,  3,
    48,  19, 2,   51, 33,  2,  19,  34, 0,   19, 2,   0,  19,  50, 0,   35, 33,  3,   48,  18,
    2,   0,  35,  2,  51,  3,  0,   19, 50,  0,  35,  33, 3,   48, 18,  2,  0,   19,  2,   48,
    19,  2,  51,  33, 2,   19, 34,  0,  35,  2,  0,   48, 51,  51, 3,   0,  48,  33,  19,  2,
    0,   51, 18,  33, 50,  0,  19,  17, 17,  33, 0,   35, 18,  33, 34,  0,  48,  33,  18,  2,
    0,   48, 34,  35, 2,   0,  0,   51, 3,   0,  0,   19, 2,   0,  51,  19, 50,  3,   19,  17,
    17,  2,  35,  18, 34,  2,  0,   19, 2,   0,  0,   35, 2,   0,  51,  51, 0,   19,  33,  0,
    19,  33, 0,   19, 34,  0,  35,  2,  0,   51, 51,  3,  19,  17, 2,   35, 34,  2,   51,  51,
    0,   19, 33,  0,  19,  33, 0,   35, 34,  0,  0,   0,  48,  51, 0,   0,  0,   51,  33,  0,
    0,   48, 19,  34, 0,   0,  51,  33, 2,   0,  48,  19, 34,  0,  0,   51, 33,  2,   0,   0,
    19,  34, 0,   0,  0,   35, 2,   0,  0,   0,  48,  51, 51,  0,  51,  17, 33,  3,   19,  34,
    18,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  50, 19,  2,   35,  17,
    33,  2,  48,  34, 34,  0,  48,  51, 0,   51, 33,  0,  19,  33, 0,   35, 33,  0,   48,  33,
    0,   48, 33,  0,  51,  33, 3,   19, 17,  2,  35,  34, 2,   48, 51,  51, 0,   51,  17,  33,
    3,   19, 34,  18, 2,   35, 50,  19, 2,   48, 19,  33, 2,   51, 33,  34, 0,   19,  34,  51,
    3,   19, 17,  17, 2,   35, 34,  34, 2,   48, 51,  51, 0,   51, 17,  33, 3,   19,  34,  18,
    2,   35, 50,  19, 2,   0,  19,  33, 2,   51, 35,  18, 2,   19, 50,  19, 2,   35,  17,  33,
    2,   48, 34,  34, 0,   0,  48,  51, 3,   0,  51,  17, 2,   48, 19,  18, 2,   51,  33,  18,
    2,   19, 34,  19, 2,   19, 17,  17, 2,   35, 34,  18, 2,   0,  0,   19, 2,   0,   0,   35,
    2,   51, 51,  51, 3,   19, 17,  17, 2,   19, 34,  34, 2,   19, 50,  51, 0,   19,  17,  33,
    3,   35, 34,  18, 2,   19, 50,  19, 2,   35, 17,  33, 2,   48, 34,  34, 0,   48,  51,  51,
    0,   51, 17,  33, 3,   19, 34,  18, 2,   19, 50,  35, 2,   19, 17,  33, 3,   19,  34,  18,
    2,   19, 50,  19, 2,   35, 17,  33, 2,   48, 34,  34, 0,   51, 51,  51, 3,   19,  17,  17,
    2,   35, 34,  18, 2,   0,  48,  33, 2,   0,  51,  33, 0,   0,  19,  34, 0,   0,   19,  2,
    0,   0,  19,  2,  0,   0,  35,  2,  0,   48, 51,  51, 0,   51, 17,  33, 3,   19,  34,  18,
    2,   19, 50,  19, 2,   35, 17,  33, 2,   19, 34,  18, 2,   19, 50,  19, 2,   35,  17,  33,
    2,   48, 34,  34, 0,   48, 51,  51, 0,   51, 17,  33, 3,   19, 34,  18, 2,   19,  50,  19,
    2,   35, 17,  17, 2,   51, 34,  18, 2,   19, 50,  19, 2,   35, 17,  33, 2,   48,  34,  34,
    0,   51, 51,  0,  19,  33, 0,   19, 33,  0,  35,  34, 0,   51, 51,  0,  19,  33,  0,   19,
    33,  0,  35,  34, 0,   51, 51,  0,  19,  33, 0,   19, 33,  0,  35,  34, 0,   51,  51,  0,
    19,  33, 0,   19, 33,  0,  19,  34, 0,   35, 2,   0,  0,   48, 51,  0,  0,   51,  33,  0,
    48,  19, 34,  0,  51,  33, 2,   0,  19,  34, 0,   0,  35,  33, 3,   0,  48,  18,  50,  0,
    0,   35, 33,  0,  0,   48, 34,  0,  51,  51, 51,  0,  19,  17, 33,  0,  35,  34,  34,  0,
    19,  17, 33,  0,  35,  34, 34,  0,  51,  3,  0,   0,  19,  50, 0,   0,  35,  33,  3,   0,
    48,  18, 50,  0,  0,   35, 33,  0,  48,  19, 34,  0,  51,  33, 2,   0,  19,  34,  0,   0,
    35,  2,  0,   0,  48,  51, 3,   0,  51,  17, 50,  0,  19,  34, 33,  0,  35,  50,  33,  0,
    48,  19, 34,  0,  48,  33, 2,   0,  48,  34, 0,   0,  48,  33, 0,   0,  48,  34,  0,   0,
    0,   51, 51,  51, 0,   48, 19,  17, 33,  3,  51,  33, 34,  18, 2,   19, 34,  17,  18,  2,
    19,  18, 18,  18, 2,   19, 34,  17, 33,  2,  35,  33, 34,  34, 0,   48, 18,  17,  33,  0,
    0,   35, 34,  34, 0,   0,  51,  3,  0,   48, 19,  50, 0,   51, 33,  33, 3,   19,  34,  18,
    2,   19, 50,  19, 2,   19, 17,  17, 2,   19, 34,  18, 2,   19, 2,   19, 2,   35,  2,   35,
    2,   51, 51,  51, 0,   19, 17,  33, 3,   19, 34,  18, 2,   19, 50,  19, 2,   19,  17,  33,
    2,   19, 34,  18, 2,   19, 50,  19, 2,   19, 17,  33, 2,   35, 34,  34, 0,   48,  51,  51,
    0,   51, 17,  33, 3,   19, 34,  18, 2,   19, 2,   35, 2,   19, 2,   0,  0,   19,  2,   51,
    3,   19, 50,  19, 2,   35, 17,  33, 2,   48, 34,  34, 0,   51, 51,  51, 0,   19,  17,  33,
    3,   19, 34,  18, 2,   19, 2,   19, 2,   19, 2,   19, 2,   19, 2,   19, 2,   19,  50,  19,
    2,   19, 17,  33, 2,   35, 34,  34, 0,   51, 51,  51, 0,   19, 17,  33, 0,   19,  34,  34,
    0,   19, 50,  3,  0,   19, 17,  2,  0,   19, 34,  2,  0,   19, 50,  51, 0,   19,  17,  33,
    0,   35, 34,  34, 0,   51, 51,  51, 0,   19, 17,  33, 0,   19, 34,  34, 0,   19,  50,  3,
    0,   19, 17,  2,  0,   19, 34,  2,  0,   19, 2,   0,  0,   19, 2,   0,  0,   35,  2,   0,
    0,   48, 51,  51, 0,   51, 17,  33, 3,   19, 34,  18, 2,   19, 50,  35, 2,   19,  50,  17,
    2,   19, 50,  18, 2,   19, 50,  19, 2,   35, 17,  33, 2,   48, 34,  34, 0,   51,  3,   51,
    3,   19, 2,   19, 2,   19, 2,   19, 2,   19, 50,  19, 2,   19, 17,  17, 2,   19,  34,  18,
    2,   19, 2,   19, 2,   19, 2,   19, 2,   35, 2,   35, 2,   51, 3,   19, 2,   19,  2,   19,
    2,   19, 2,   19, 2,   19, 2,   19, 2,   35, 2,   0,  48,  51, 0,   0,  48,  33,  0,   0,
    48,  33, 0,   0,  48,  33, 0,   0,  48,  33, 0,   51, 51,  33, 0,   19, 50,  33,  0,   35,
    17,  34, 0,   32, 34,  2,  0,   51, 3,   51, 3,   19, 2,   19, 2,   19, 50,  19,  2,   19,
    50,  33, 2,   19, 17,  34, 0,   19, 34,  33, 3,   19, 34,  18, 2,   19, 2,   19,  2,   35,
    2,   35, 2,   51, 3,   0,  0,   19, 2,   0,  0,   19, 2,   0,  0,   19, 2,   0,   0,   19,
    2,   0,  0,   19, 2,   0,  0,   19, 50,  51, 0,   19, 17,  33, 0,   35, 34,  34,  0,   51,
    3,   0,  51,  3,  19,  50, 48,  19, 2,   19, 33,  51, 17,  2,  19,  18, 18,  18,  2,   19,
    34,  33, 18,  2,  19,  50, 34,  19, 2,   19, 2,   0,  19,  2,  19,  2,  0,   19,  2,   35,
    2,   0,  35,  2,  51,  3,  51,  3,  19,  50, 19,  2,  19,  33, 19,  2,  19,  33,  19,  2,
    19,  18, 18,  2,  19,  34, 17,  2,  19,  50, 17,  2,  19,  50, 18,  2,  35,  2,   35,  2,
    51,  51, 51,  0,  19,  17, 33,  3,  19,  34, 18,  2,  19,  50, 19,  2,  19,  17,  33,  2,
    19,  34, 34,  0,  19,  2,  0,   0,  19,  2,  0,   0,  35,  2,  0,   0,  48,  51,  51,  0,
    51,  17, 33,  3,  19,  34, 18,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  50,  19,  2,
    19,  50, 33,  2,  35,  17, 18,  2,  48,  34, 34,  2,  51,  51, 51,  0,  19,  17,  33,  3,
    19,  34, 18,  2,  19,  50, 19,  2,  19,  17, 33,  2,  19,  34, 18,  2,  19,  2,   19,  2,
    19,  2,  19,  2,  35,  2,  35,  2,  48,  51, 51,  0,  51,  17, 33,  3,  19,  34,  18,  2,
    19,  50, 35,  2,  35,  17, 33,  3,  51,  34, 18,  2,  19,  50, 19,  2,  35,  17,  33,  2,
    48,  34, 34,  0,  51,  51, 51,  3,  19,  17, 17,  2,  35,  18, 34,  2,  0,   19,  2,   0,
    0,   19, 2,   0,  0,   19, 2,   0,  0,   19, 2,   0,  0,   19, 2,   0,  0,   35,  2,   0,
    51,  3,  51,  3,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,   19,  2,
    19,  2,  19,  2,  19,  50, 19,  2,  35,  17, 33,  2,  48,  34, 34,  0,  51,  3,   51,  3,
    19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  50,  19,  2,
    35,  33, 33,  2,  48,  18, 34,  0,  0,   35, 2,   0,  51,  3,  0,   51, 3,   19,  2,   0,
    19,  2,  19,  2,  0,   19, 2,   19, 50,  51, 19,  2,  19,  50, 33,  19, 2,   19,  18,  18,
    18,  2,  19,  33, 34,  17, 2,   19, 34,  48, 18,  2,  35,  2,  0,   35, 2,   51,  3,   51,
    3,   19, 2,   19, 2,   19, 50,  19, 2,   35, 33,  33, 2,   48, 18,  34, 0,   51,  33,  33,
    3,   19, 34,  18, 2,   19, 2,   19, 2,   35, 2,   35, 2,   51, 3,   51, 3,   19,  2,   19,
    2,   19, 50,  19, 2,   35, 33,  33, 2,   48, 18,  34, 0,   0,  19,  2,  0,   0,   19,  2,
    0,   0,  19,  2,  0,   0,  35,  2,  0,   51, 51,  51, 3,   19, 17,  17, 2,   35,  34,  18,
    2,   0,  51,  33, 2,   48, 19,  34, 0,   51, 33,  2,  0,   19, 34,  51, 3,   19,  17,  17,
    2,   35, 34,  34, 2,   51, 51,  3,  19,  17, 2,   19, 34,  2,  19,  2,  0,   19,  2,   0,
    19,  2,  0,   19, 50,  3,  19,  17, 2,   35, 34,  2,  51,  3,  0,   0,  0,   19,  50,  0,
    0,   0,  35,  33, 3,   0,  0,   48, 18,  50, 0,   0,  0,   35, 33,  3,  0,   0,   48,  18,
    50,  0,  0,   0,  35,  33, 0,   0,  0,   48, 34,  0,  51,  51, 3,   19, 17,  2,   35,  18,
    2,   0,  19,  2,  0,   19, 2,   0,  19,  2,  51,  19, 2,   19, 17,  2,  35,  34,  2,   0,
    51,  3,  0,   48, 19,  50, 0,   51, 33,  33, 3,   19, 34,  18, 2,   35, 2,   35,  2,   51,
    51,  51, 51,  3,  19,  17, 17,  17, 2,   35, 34,  34, 34,  2,  51,  3,  0,   19,  50,  0,
    35,  33, 3,   48, 18,  2,  0,   35, 2,   48, 51,  51, 0,   48, 17,  33, 3,   48,  34,  18,
    2,   51, 17,  17, 2,   19, 34,  18, 2,   35, 17,  17, 2,   48, 34,  34, 2,   51,  3,   0,
    0,   19, 2,   0,  0,   19, 50,  51, 0,   19, 17,  33, 3,   19, 34,  18, 2,   19,  2,   19,
    2,   19, 50,  19, 2,   19, 17,  33, 2,   35, 34,  34, 0,   48, 51,  51, 0,   51,  17,  33,
    3,   19, 34,  18, 2,   19, 2,   35, 2,   19, 50,  19, 2,   35, 17,  33, 2,   48,  34,  34,
    0,   0,  0,   51, 3,   0,  0,   19, 2,   48, 51,  19, 2,   51, 17,  17, 2,   19,  34,  18,
    2,   19, 2,   19, 2,   19, 50,  19, 2,   35, 17,  17, 2,   48, 34,  34, 2,   48,  51,  51,
    0,   51, 17,  33, 3,   19, 34,  18, 2,   19, 17,  17, 2,   19, 34,  34, 2,   35,  17,  17,
    2,   48, 34,  34, 2,   0,  51,  51, 0,   48, 19,  33, 0,   48, 33,  34, 0,   51,  33,  3,
    0,   19, 17,  2,  0,   35, 33,  2,  0,   48, 33,  0,  0,   48, 33,  0,  0,   48,  34,  0,
    0,   48, 51,  51, 3,   51, 17,  17, 2,   19, 34,  18, 2,   19, 2,   19, 2,   19,  50,  19,
    2,   35, 17,  17, 2,   48, 34,  18, 2,   19, 17,  33, 2,   35, 34,  34, 0,   51,  3,   0,
    0,   19, 2,   0,  0,   19, 50,  51, 0,   19, 17,  33, 3,   19, 34,  18, 2,   19,  2,   19,
    2,   19, 2,   19, 2,   19, 2,   19, 2,   35, 2,   35, 2,   51, 3,   19, 2,   35,  2,   19,
    2,   19, 2,   19, 2,   19, 2,   19, 2,   35, 2,   0,  51,  3,  0,   19, 2,   0,   35,  2,
    0,   19, 2,   0,  19,  2,  0,   19, 2,   0,  19,  2,  51,  19, 2,   19, 33,  2,   35,  34,
    0,   51, 3,   0,  0,   19, 2,   0,  0,   19, 50,  51, 0,   19, 50,  33, 0,   19,  18,  34,
    0,   19, 33,  2,  0,   19, 18,  50, 0,   19, 34,  33, 0,   35, 50,  34, 0,   51,  51,  51,
    51,  0,  19,  17, 18,  33, 3,   19, 34,  33, 18,  2,  19,  50, 33,  19, 2,   19,  50,  33,
    19,  2,  19,  50, 33,  19, 2,   35, 50,  34, 35,  2,  51,  51, 51,  0,  19,  17,  33,  3,
    19,  34, 18,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  35,  2,   35,  2,
    48,  51, 51,  0,  51,  17, 33,  3,  19,  34, 18,  2,  19,  2,  19,  2,  19,  50,  19,  2,
    35,  17, 33,  2,  48,  34, 34,  0,  51,  51, 51,  0,  19,  17, 33,  3,  19,  34,  18,  2,
    19,  2,  19,  2,  19,  50, 19,  2,  19,  17, 33,  2,  19,  34, 34,  0,  19,  2,   0,   0,
    35,  2,  0,   0,  48,  51, 51,  3,  51,  17, 17,  2,  19,  34, 18,  2,  19,  2,   19,  2,
    19,  50, 19,  2,  35,  17, 17,  2,  48,  34, 18,  2,  0,   0,  19,  2,  0,   0,   35,  2,
    51,  51, 51,  0,  19,  17, 33,  3,  19,  34, 18,  2,  19,  50, 35,  2,  19,  2,   0,   0,
    19,  2,  0,   0,  35,  2,  0,   0,  48,  51, 51,  3,  51,  17, 17,  2,  19,  34,  34,  2,
    35,  17, 33,  3,  51,  34, 18,  2,  19,  17, 33,  2,  35,  34, 34,  0,  48,  51,  0,   48,
    33,  0,  51,  33, 3,   19, 17,  2,  35,  33, 2,   48, 33,  0,  48,  33, 0,   48,  33,  0,
    48,  34, 0,   51, 3,   51, 3,   19, 2,   19, 2,   19, 2,   19, 2,   19, 2,   19,  2,   19,
    50,  19, 2,   35, 17,  17, 2,   48, 34,  34, 2,   51, 3,   51, 3,   19, 2,   19,  2,   19,
    50,  19, 2,   35, 33,  33, 2,   48, 33,  33, 0,   48, 18,  34, 0,   0,  35,  2,   0,   51,
    51,  51, 51,  3,  19,  50, 33,  19, 2,   19, 50,  33, 19,  2,  19,  50, 33,  19,  2,   19,
    50,  33, 19,  2,  35,  17, 18,  33, 2,   48, 34,  34, 34,  0,  51,  3,  51,  3,   19,  50,
    19,  2,  35,  33, 33,  2,  48,  18, 34,  0,  51,  33, 33,  3,  19,  34, 18,  2,   35,  2,
    35,  2,  51,  3,  51,  3,  19,  2,  19,  2,  19,  2,  19,  2,  19,  50, 19,  2,   35,  33,
    19,  2,  48,  18, 17,  2,  48,  35, 18,  2,  48,  17, 33,  2,  48,  34, 34,  0,   51,  51,
    51,  3,  19,  17, 17,  2,  35,  34, 33,  2,  48,  19, 34,  0,  51,  33, 50,  3,   19,  17,
    17,  2,  35,  34, 34,  2,  0,   51, 3,   48, 19,  2,  48,  33, 2,   51, 33,  0,   19,  34,
    0,   35, 33,  0,  48,  33, 3,   48, 18,  2,  0,   35, 2,   51, 3,   19, 2,   19,  2,   19,
    2,   35, 2,   19, 2,   19, 2,   19, 2,   35, 2,   51, 3,   0,  19,  50, 0,   35,  33,  0,
    48,  33, 3,   48, 18,  2,  48,  33, 2,   51, 33,  0,  19,  34, 0,   35, 2,   0,   48,  51,
    3,   0,  0,   51, 17,  50, 0,   0,  19,  34, 33,  51, 0,   35, 50,  18, 33,  0,   0,   0,
    35,  34, 0,   51, 51,  51, 51,  0,  17,  17, 17,  33, 0,   34, 34,  34, 33,  0,   0,   0,
    48,  33, 0,   0,  0,   48, 33,  0,  51,  51, 51,  33, 0,   17, 17,  17, 33,  0,   34,  34,
    34,  34, 0,   48, 51,  51, 0,   51, 17,  33, 3,   19, 34,  18, 2,   19, 2,   35,  2,   19,
    2,   0,  0,   19, 2,   51, 3,   19, 50,  19, 2,   35, 17,  33, 2,   48, 18,  34,  0,   48,
    17,  2,  0,   48, 34,  2,  0,   51, 3,   51, 3,   19, 2,   19, 2,   35, 2,   35,  2,   19,
    2,   19, 2,   19, 2,   19, 2,   19, 2,   19, 2,   19, 50,  19, 2,   35, 17,  17,  2,   48,
    34,  34, 2,   48, 19,  2,  0,   48, 33,  2,  0,   48, 34,  51, 0,   51, 17,  33,  3,   19,
    34,  18, 2,   19, 17,  17, 2,   19, 34,  34, 3,   35, 17,  17, 2,   48, 34,  34,  2,   48,
    19,  33, 3,   48, 33,  18, 2,   48, 34,  35, 2,   48, 17,  33, 3,   48, 34,  18,  2,   51,
    17,  17, 2,   19, 34,  18, 2,   35, 17,  17, 2,   48, 34,  34, 2,   48, 51,  51,  3,   48,
    33,  19, 2,   48, 34,  35, 2,   48, 17,  33, 3,   48, 34,  18, 2,   51, 17,  17,  2,   19,
    34,  18, 2,   35, 17,  17, 2,   48, 34,  34, 2,   0,  19,  50, 0,   0,  35,  33,  0,   0,
    51,  34, 0,   48, 17,  33, 3,   48, 34,  18, 2,   51, 17,  17, 2,   19, 34,  18,  2,   35,
    17,  17, 2,   48, 34,  34, 2,   48, 51,  3,  0,   48, 17,  2,  0,   48, 34,  2,   0,   48,
    17,  33, 3,   48, 34,  18, 2,   51, 17,  17, 2,   19, 34,  18, 2,   35, 17,  17,  2,   48,
    34,  34, 2,   48, 51,  51, 0,   51, 17,  33, 3,   19, 34,  18, 2,   19, 50,  35,  2,   19,
    50,  19, 2,   35, 17,  33, 2,   48, 18,  34, 0,   0,  35,  2,  0,   48, 19,  33,  3,   48,
    33,  18, 2,   48, 34,  35, 2,   51, 17,  33, 3,   19, 34,  18, 2,   19, 17,  17,  2,   19,
    34,  34, 3,   35, 17,  17, 2,   48, 34,  34, 2,   48, 51,  51, 3,   48, 33,  19,  2,   48,
    34,  35, 2,   51, 17,  33, 3,   19, 34,  18, 2,   19, 17,  17, 2,   19, 34,  34,  3,   35,
    17,  17, 2,   48, 34,  34, 2,   0,  19,  50, 0,   0,  35,  33, 0,   0,  51,  50,  0,   51,
    17,  33, 3,   19, 34,  18, 2,   19, 17,  17, 2,   19, 34,  34, 3,   35, 17,  17,  2,   48,
    34,  34, 2,   51, 51,  3,  19,  18, 2,   35, 35,  2,  48,  33, 0,   48, 33,  0,   48,  33,
    0,   48, 33,  0,  48,  33, 0,   48, 34,  0,  51,  33, 3,   19, 18,  2,  35,  35,  2,   48,
    33,  0,  48,  33, 0,   48, 33,  0,  48,  33, 0,   48, 33,  0,  48,  34, 0,   19,  50,  0,
    35,  33, 0,   48, 50,  0,  48,  33, 0,   48, 33,  0,  48,  33, 0,   48, 33,  0,   48,  33,
    0,   48, 34,  0,  19,  50, 19,  2,  35,  19, 34,  2,  51,  33, 33,  3,  19,  34,  18,  2,
    19,  50, 19,  2,  19,  17, 17,  2,  19,  34, 18,  2,  19,  2,  19,  2,  35,  2,   35,  2,
    48,  17, 33,  0,  48,  34, 50,  0,  51,  17, 33,  3,  19,  34, 18,  2,  19,  50,  19,  2,
    19,  17, 17,  2,  19,  34, 18,  2,  19,  2,  19,  2,  35,  2,  35,  2,  0,   51,  33,  0,
    51,  19, 50,  0,  19,  17, 33,  0,  19,  34, 34,  0,  19,  17, 2,   0,  19,  34,  2,   0,
    19,  50, 51,  0,  19,  17, 33,  0,  35,  34, 34,  0,  51,  51, 51,  51, 3,   19,  17,  18,
    17,  2,  35,  34, 33,  18, 2,   19, 17,  17, 17,  2,  19,  34, 33,  34, 3,   19,  17,  18,
    17,  2,  35,  34, 35,  34, 2,   0,  51,  51, 51,  51, 48,  19, 17,  17, 33,  48,  17,  18,
    34,  33, 48,  33, 19,  50, 34,  51, 33,  19, 33,  0,  19,  17, 17,  34, 51,  19,  34,  18,
    50,  33, 19,  2,  19,  17, 33,  35, 2,   35, 34,  34, 48,  19, 50,  0,  48,  33,  33,  0,
    48,  34, 34,  0,  51,  17, 33,  3,  19,  34, 18,  2,  19,  2,  19,  2,  19,  50,  19,  2,
    35,  17, 33,  2,  48,  34, 34,  0,  51,  51, 51,  0,  19,  50, 33,  0,  35,  50,  34,  0,
    51,  17, 33,  3,  19,  34, 18,  2,  19,  2,  19,  2,  19,  50, 19,  2,  35,  17,  33,  2,
    48,  34, 34,  0,  48,  33, 3,   0,  48,  18, 50,  0,  51,  17, 33,  3,  19,  34,  18,  2,
    19,  2,  19,  2,  19,  50, 19,  2,  35,  17, 33,  2,  48,  34, 34,  0,  48,  19,  50,  0,
    48,  33, 33,  0,  51,  34, 34,  0,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,   19,  2,
    19,  50, 19,  2,  35,  17, 17,  2,  48,  34, 34,  2,  48,  33, 3,   0,  48,  18,  50,  0,
    51,  35, 50,  0,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  50,  19,  2,
    35,  17, 17,  2,  48,  34, 34,  2,  48,  51, 51,  0,  48,  33, 33,  0,  51,  34,  34,  0,
    19,  2,  19,  2,  19,  2,  19,  2,  19,  50, 19,  2,  35,  33, 19,  2,  48,  18,  17,  2,
    48,  35, 18,  2,  48,  17, 33,  2,  48,  34, 34,  0,  19,  50, 19,  2,  35,  17,  33,  3,
    19,  34, 18,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  50,  19,  2,
    35,  17, 33,  2,  48,  34, 34,  0,  19,  2,  19,  2,  35,  3,  35,  3,  19,  2,   19,  2,
    19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  50, 19,  2,  35,  17,  33,  2,
    48,  34, 34,  0,  0,   51, 3,   0,  48,  19, 2,   0,  51,  17, 50,  0,  19,  34,  33,  0,
    19,  50, 50,  0,  19,  50, 33,  0,  35,  17, 34,  0,  48,  18, 2,   0,  0,   35,  2,   0,
    48,  19, 33,  3,  48,  33, 18,  2,  51,  33, 35,  2,  19,  17, 33,  0,  35,  33,  34,  0,
    48,  33, 51,  3,  51,  33, 19,  2,  19,  17, 33,  2,  35,  34, 34,  0,  48,  33,  51,  33,
    0,   48, 18,  18, 34,  0,  0,   35, 33,  3,  0,   0,  19,  17, 2,   0,  0,   35,  33,  3,
    0,   0,  19,  17, 2,   0,  0,   35, 33,  2,  0,   0,  48,  33, 0,   0,  0,   48,  34,  0,
    0,   51, 51,  51, 0,   19, 17,  33, 3,   19, 34,  18, 2,   19, 50,  19, 2,   19,  17,  33,
    2,   19, 34,  33, 0,   19, 50,  33, 3,   19, 18,  17, 2,   35, 35,  33, 2,   0,   48,  34,
    0,   0,  48,  51, 3,   0,  0,   51, 17,  50, 0,   0,  19,  34, 33,  0,  48,  19,  50,  34,
    0,   48, 17,  33, 0,   0,  48,  18, 34,  0,  0,   0,  19,  2,  0,   0,  51,  19,  2,   0,
    0,   19, 33,  2,  0,   0,  35,  34, 0,   0,  0,   0,  51,  33, 0,   0,  19,  34,  0,   0,
    35,  50, 0,   48, 17,  33, 3,   48, 34,  18, 2,   51, 17,  17, 2,   19, 34,  18,  2,   35,
    17,  17, 2,   48, 34,  34, 2,   51, 33,  0,  19,  34, 0,   35, 2,   0,  19,  2,   0,   19,
    2,   0,  19,  2,  0,   19, 2,   0,  19,  2,  0,   35, 2,   0,  48,  19, 2,   0,   48,  33,
    2,   0,  48,  34, 3,   0,  51,  17, 33,  3,  19,  34, 18,  2,  19,  2,  19,  2,   19,  50,
    19,  2,  35,  17, 33,  2,  48,  34, 34,  0,  48,  19, 2,   0,  48,  33, 2,   0,   51,  34,
    51,  0,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  50, 19,  2,   35,  17,
    17,  2,  48,  34, 34,  2,  19,  33, 19,  2,  35,  18, 33,  2,  51,  35, 34,  0,   19,  17,
    33,  3,  19,  34, 18,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,  19,  2,   35,  2,
    35,  2,  48,  19, 50,  3,  0,   48, 33,  17, 50,  0,  48,  33, 34,  33, 0,   48,  17,  50,
    33,  0,  48,  33, 33,  33, 0,   48, 33,  18, 33,  0,  48,  33, 35,  33, 0,   48,  33,  48,
    33,  0,  48,  34, 48,  34, 0,   48, 51,  51, 0,   48, 17,  33, 3,   48, 34,  18,  2,   51,
    17,  17, 2,   19, 34,  18, 2,   35, 17,  17, 2,   48, 34,  34, 2,   19, 17,  17,  2,   35,
    34,  34, 2,   48, 51,  51, 0,   51, 17,  33, 3,   19, 34,  18, 2,   35, 17,  33,  2,   51,
    34,  34, 3,   19, 17,  17, 2,   35, 34,  34, 2,   0,  48,  51, 0,   0,  48,  33,  0,   0,
    48,  34, 0,   0,  51,  33, 0,   48, 19,  34, 0,   48, 33,  50, 3,   48, 33,  19,  2,   48,
    18,  33, 2,   0,  35,  34, 0,   48, 51,  51, 51,  3,  51,  17, 33,  17, 50,  19,  34,  18,
    34,  33, 19,  2,  19,  17, 33,  19, 50,  19, 34,  34, 35,  17, 33,  17, 33,  48,  34,  34,
    34,  34, 48,  51, 51,  0,  51,  17, 33,  3,  19,  34, 18,  2,  19,  18, 33,  2,   19,  34,
    18,  2,  19,  2,  19,  2,  19,  50, 19,  2,  19,  18, 33,  2,  19,  34, 34,  0,   35,  2,
    0,   0,  1,   7,  0,   9,  1,   7,  2,   6,  1,   7,  1,   7,  1,   7,  1,   7,   1,   7,
    1,   7,  1,   7,  1,   7,  1,   7,  1,   7,  1,   7,  1,   7,  0,   9,  0,   9,   1,   7,
    1,   7,  1,   7,  1,   7,  1,   7,  1,   7,  0,   9,  0,   9,  1,   7,  1,   7,   1,   7,
    1,   7,  0,   9,  0,   9,  11,  0,  0,   9,  0,   4,  1,   7,  0,   9,  0,   9,   0,   9,
    0,   5,  0,   9,  0,   9,  0,   7,  0,   7,  5,   5,  3,   3,  5,   4,  1,   8,   0,   9,
    0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,   1,   8,
    1,   9,  0,   9,  2,   5,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,   0,   9,
    0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,   0,   9,
    0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,   0,   9,
    0,   9,  0,   9,  0,   9,  1,   8,  0,   9,  0,   5,  6,   3,  0,   5,  2,   7,   0,   9,
    2,   7,  0,   9,  2,   7,  0,   9,  2,   9,  0,   9,  0,   9,  0,   10, 0,   9,   0,   9,
    2,   7,  2,   7,  2,   7,  2,   9,  2,   9,  2,   7,  2,   7,  0,   9,  2,   7,   2,   7,
    2,   7,  2,   7,  2,   9,  2,   7,  0,   9,  0,   9,  0,   9,  0,   5,  1,   8,   0,   11,
    0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  2,   8,  0,   9,  0,   9,   0,   9,
    0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  2,   7,  0,   9,  0,   9,   0,   9,
    1,   8,  0,   9,  0,   9,  0,   11, 0,   9,  0,   9,  1,   9,  0,   9,  0,   9,   0,   10,
    0,   10, 0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  0,   9,  1,   7,   0,   9,
    11,  0,  11,  0,  11,  0,  11,  0,  0,   9,  11,  0,  11,  0,  11,  0,  11,  0,   11,  0,
    11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,   11,  0,
    11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,   11,  0,
    11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  4,   7,   11,  0,
    11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,   11,  0,
    11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  11,  0,  1,   10,
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Global Data /////////////////////////////////////////////////////////////////////////////////////

WWFontClass DefaultFont(DefaultFontData);
