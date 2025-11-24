//
// Created by katak on 24/11/25.
//

#include "engine.h"
#include <iostream>

void Engine::run() {
    std::cout << m_name << " is running" << std::endl;
    init();
    update();
    shutdown();
}

void Engine::init() const {
    std::cout << m_name << " is initializing" << std::endl;
    for ( auto& system : m_systems ) {
        system->Initialize();
    }
}

void Engine::update() {
    while (m_running) {
        std::cout << m_name << " is in update loop" << std::endl;
        for ( auto& system : m_systems ) {
            system->Update();
        }
        m_running = false;
    }
}

void Engine::shutdown() const {
    std::cout << m_name << " is shutting down" << std::endl;
    for ( auto& system : m_systems ) {
        system->Shutdown();
    }
}
