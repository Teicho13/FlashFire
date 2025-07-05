#pragma once
namespace FF
{
    class scene
    {
    public:
        virtual ~scene() = default;
        virtual void Init() = 0;
        virtual void Tick(const float deltaTime) = 0;
        virtual void ShutDown() = 0;
        virtual void Render() = 0;
    };
}
