#include <iostream>
#include "Engine/engine.h"
#include "Engine/system_render.h"

int main() {
    Engine SSE("SandStormEngine");
    SSE.registerSystem<Render_System>();
    SSE.run();
}
