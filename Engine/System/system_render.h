#ifndef SANDSTORMENGINE_SYSTEM_RENDER_H
#define SANDSTORMENGINE_SYSTEM_RENDER_H
#include "system.h"

class Render_System : public ISystem {
public:
    Render_System();

    void Initialize() override;
    void Update() override;
    void Shutdown() override;
};
#endif //SANDSTORMENGINE_SYSTEM_RENDER_H
