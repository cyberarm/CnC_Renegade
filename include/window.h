//
// Created by cyberarm on 2/28/25.
//

#pragma once
#include <commando_engine.h>

namespace CommandoEngine
{
    class Window {
        public:
            Window();
            ~Window();
            void show();
            void update(Uint64 delta_time_ns);
            void render();
            void close();
        private:
            void tick();
            void initialize();
            void initialize_sdl_video();
            void initialize_sdl_audio();
            void initialize_sdl_gamepad();
            void initialize_game();
            void drain_sdl_events();
            static void SDLCALL open_game_folder_callback(void *userdata, const char * const *filelist, int filter);

            SDL_Window* m_window = nullptr;
            SDL_Renderer* m_renderer = nullptr;
            SDL_FRect m_screen_rect{ 0, 0, 800, 600 };
            Uint64 m_current_delta_time_ns = 0;
            Uint64 m_last_tick_ns = 0;
            Uint64 m_time_before_tick_ns = 0;
            bool m_window_closing = false;

            bool m_modal_shown = false;

            // FIXME: The window must not know or care directly about files, just windowing and rendering
            bool m_game_folder_located = false;
            const char* m_game_folder_path = nullptr;

            SDL_Storage *m_storage = nullptr;
    };
}
