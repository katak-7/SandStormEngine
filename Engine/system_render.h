#ifndef SANDSTORMENGINE_SYSTEM_RENDER_H
#define SANDSTORMENGINE_SYSTEM_RENDER_H
#include <SDL2/SDL.h>
#include "system.h"

class Render_System : public ISystem {
public:
    Render_System();

    void Initialize() override;
    void Update() override;
    void Shutdown() override;
private:
    SDL_Window* m_window{};
    SDL_Renderer* m_renderer{};
};
#endif //SANDSTORMENGINE_SYSTEM_RENDER_H
