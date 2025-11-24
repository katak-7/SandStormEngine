#include "system_render.h"

#include <iostream>
\
#include "engine.h"

Render_System::Render_System() {
    std::cout << "Render System Constructor" << std::endl;
}

void Render_System::Initialize() {
    std::cout << "Render System Initialized" << std::endl;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return; // Initialization failed
    }

    // Create a window
    m_window = SDL_CreateWindow("SDL2 Example",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          800, 600,
                                          SDL_WINDOW_SHOWN);
    if (m_window== nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr) {
        std::cerr << "Renderer could not be created!" << std::endl;
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }
}

void Render_System::Update() {
    std::cout << "Render System Update" << std::endl;
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            Engine::m_running = false; // Control the exit from the main loop
        }
    }

    SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 255); // Set the clear color (black)
    SDL_RenderClear(m_renderer);                      // Clear the window

    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 255); // Set the clear color (white)
    SDL_RenderFillRect(m_renderer,new SDL_Rect(100, 100, 200, 150)); //
    SDL_RenderPresent(m_renderer);                    // Show the window contents
    SDL_Delay(16);
}

void Render_System::Shutdown() {
    std::cout << "Render System Shutdown" << std::endl;
    SDL_DestroyWindow(m_window); // Clean up the window
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit(); // Clean up SDL subsystems
}
