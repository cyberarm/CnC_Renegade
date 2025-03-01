//
// Created by cyberarm on 2/28/25.
//

#include <commando_engine.h>
#include <window.h>


int main(int argc, char *argv[])
{
    atexit(SDL_Quit);

    auto *m_window = new CommandoEngine::Window();
    m_window->show();
}
