#ifndef SANDSTORMENGINE_ENGINE_H
#define SANDSTORMENGINE_ENGINE_H

#include <memory>
#include <string>
#include <vector>

#include "system.h"

template <typename T>
concept DerivedFromISystem = std::is_base_of_v<ISystem, T>;

class Engine {
public:
    explicit Engine(std::string&& name) : m_name(name) {};
    Engine(const Engine &) = delete;
    Engine &operator=(const Engine &) = delete;
    ~Engine() = default;

    void run();

    template <DerivedFromISystem  T>
    void registerSystem();
    static bool m_running;
private:
    void init();
    void update();
    void shutdown() const;

    std::vector<std::unique_ptr<ISystem>> m_systems;
    std::string m_name{};
};

template<DerivedFromISystem T>
void Engine::registerSystem() {
    m_systems.push_back(std::make_unique<T>());
}

#endif //SANDSTORMENGINE_ENGINE_H
