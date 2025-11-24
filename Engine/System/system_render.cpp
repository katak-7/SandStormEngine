#include "system_render.h"

#include <iostream>

Render_System::Render_System() {
    std::cout << "Render System Constructor" << std::endl;
}

void Render_System::Initialize() {
    std::cout << "Render System Initialized" << std::endl;
}

void Render_System::Update() {
    std::cout << "Render System Update" << std::endl;
}

void Render_System::Shutdown() {
    std::cout << "Render System Shutdown" << std::endl;
}
