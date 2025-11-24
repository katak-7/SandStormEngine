#ifndef SANDSTORMENGINE_ENGINE_H
#define SANDSTORMENGINE_ENGINE_H

#include <memory>
#include <string>
#include <vector>

#include "System/system.h"

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

private:
    void init() const;
    void update();
    void shutdown() const;

    std::vector<std::unique_ptr<ISystem>> m_systems;
    std::string m_name{};
    bool m_running{true};
};

template<DerivedFromISystem T>
void Engine::registerSystem() {
    m_systems.push_back(std::make_unique<T>());
}

#endif //SANDSTORMENGINE_ENGINE_H
