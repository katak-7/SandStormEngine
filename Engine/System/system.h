#ifndef SANDSTORMENGINE_SYSTEM_H
#define SANDSTORMENGINE_SYSTEM_H

class ISystem {
    public:
    virtual ~ISystem() {}
    virtual void Initialize() = 0;
    virtual void Update() = 0;
    virtual void Shutdown() = 0;
};

#endif //SANDSTORMENGINE_SYSTEM_H