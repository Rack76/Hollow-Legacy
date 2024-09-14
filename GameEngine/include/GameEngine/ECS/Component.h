#ifndef COMPONENT_H
#define COMPONENT_H

namespace HollowEngine
{

    class Component
    {
    public:
        virtual void onCreation() {

        }

        int entityId = -1;
    };
}  // namespace HollowEngine

#endif