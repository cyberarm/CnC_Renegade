//
// Created by cyberarm on 2/28/25.
//

#include <window.h>

CommandoEngine::Window::Window()
{
    initialize();
}

CommandoEngine::Window::~Window()
{
    SDL_free((void*)m_game_folder_path);

    SDL_Quit();
}

void CommandoEngine::Window::show()
{
    char window_title[512] = "";
    sprintf(window_title, "Commando Engine v%s", COMMANDO_ENGINE_VERSION);
    if (!SDL_CreateWindowAndRenderer(window_title, 800, 600, SDL_WINDOW_RESIZABLE, &m_window, &m_renderer))
    {
        SDL_Log("SDL_CreateWindowAndRenderer failed: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_SetWindowPosition(m_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_SetWindowSurfaceVSync(m_window, true);
    // SDL_MaximizeWindow(m_window);
    // SDL_SetWindowFullscreen(m_window, true);

    m_last_tick_ns = SDL_GetTicksNS();

    while (!m_window_closing)
    {
        tick();

        Uint64 tick_time_ns = (SDL_GetTicksNS() - m_time_before_tick_ns);
        Uint64 sleep_time_ns = cmdo_update_interval_ns - tick_time_ns;
        if (sleep_time_ns > 0)
            SDL_DelayPrecise(sleep_time_ns);

        m_time_before_tick_ns = SDL_GetTicksNS();
    }
}

void CommandoEngine::Window::tick()
{
    m_current_delta_time_ns = SDL_GetTicksNS() - m_last_tick_ns;
    m_last_tick_ns = SDL_GetTicksNS();

    drain_sdl_events();
    update(m_current_delta_time_ns);
    render();
}

void CommandoEngine::Window::update(Uint64 delta_time_ns)
{
    if (!m_game_folder_located && !m_modal_shown) {
        m_modal_shown = true;

        SDL_Log("HELLO123");
        SDL_ShowOpenFolderDialog(open_game_folder_callback, this, m_window, nullptr, false);
    }
}

void CommandoEngine::Window::render()
{
    SDL_Rect rect;
    SDL_GetWindowSafeArea(m_window, &rect);
    m_screen_rect.x = rect.x;
    m_screen_rect.y = rect.y;
    m_screen_rect.w = rect.w;
    m_screen_rect.h = rect.h;

    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    SDL_SetRenderDrawColor(m_renderer, 36, 31, 49, 255);
    SDL_RenderFillRect(m_renderer, &m_screen_rect);

    SDL_SetRenderDrawColor(m_renderer, 255, 190, 111, 255);
    if (!SDL_RenderDebugTextFormat(m_renderer, 10, 10, "COMMANDO ENGINE v%s | %lums\n", COMMANDO_ENGINE_VERSION, m_current_delta_time_ns / 1000000))
        SDL_Log("SDL_RenderDebugTextFormat failed: %s\n", SDL_GetError());
    if (!SDL_RenderDebugTextFormat(m_renderer, 10, 10 + 16, "Renegade Path: %s\n", m_game_folder_path))
        SDL_Log("SDL_RenderDebugTextFormat failed: %s\n", SDL_GetError());
    if (!SDL_RenderDebugTextFormat(m_renderer, 10, 10 + 16 + 16, "STATUS: game files located: %s\n",m_game_folder_located ? "true" : "false"))
        SDL_Log("SDL_RenderDebugTextFormat failed: %s\n", SDL_GetError());

    SDL_RenderPresent(m_renderer);
}

void CommandoEngine::Window::initialize()
{
    initialize_sdl_video();
    initialize_sdl_audio();
    initialize_sdl_gamepad();

    initialize_game();
}

void CommandoEngine::Window::initialize_sdl_video()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        // FIXME: Show error, if we can.
        SDL_Log("SDL_INIT_VIDEO failed: %s\n", SDL_GetError());
    }
}

void CommandoEngine::Window::initialize_sdl_audio()
{
    if (!SDL_Init(SDL_INIT_AUDIO))
    {
        SDL_Log("SDL_INIT_AUDIO failed: %s\n", SDL_GetError());
    }
}

void CommandoEngine::Window::initialize_sdl_gamepad()
{
    if (!SDL_Init(SDL_INIT_GAMEPAD))
    {
        SDL_Log("SDL_INIT_GAMEPAD failed: %s\n", SDL_GetError());
    }
}

void CommandoEngine::Window::initialize_game()
{
    // TODO: auto detect game folder/files and prompt for game folder it not foundified
    m_storage = SDL_OpenFileStorage(m_game_folder_path ? m_game_folder_path : SDL_GetBasePath());
    Uint64 file_size = 0;
    if (SDL_GetStorageFileSize(m_storage, "Data/always.dat", &file_size) && file_size > 0)
        m_game_folder_located = true;

    if (!m_game_folder_located) {
        SDL_free(m_storage);
        m_storage = nullptr;
    }
}

void CommandoEngine::Window::drain_sdl_events()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
        {
            m_window_closing = true;
            break;
        }
        }
    }
}

void CommandoEngine::Window::open_game_folder_callback(void *userdata, const char * const *filelist, int filter)
{
    bool cancelled = false;
    if (!filelist) {
        SDL_Log("An error occurred: %s", SDL_GetError());
        cancelled = true;
    } else if (!*filelist) {
        SDL_Log("The user did not select any file.");
        SDL_Log("Most likely, the dialog was canceled.");
        cancelled = true;
    }

    if (userdata) {
        Window *window = static_cast<Window *>(userdata);

        if (!cancelled) {
            while (*filelist) {
                SDL_Log("Full path to selected file: '%s'", *filelist);

                window->m_game_folder_path = SDL_strdup(*filelist);
                break;

                // Fixme?
                filelist++;
            }

            window->initialize_game();
        }

        window->m_modal_shown = false;
    }
}