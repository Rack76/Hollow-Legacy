#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>

namespace HollowEngine
{
    template <typename T>
    class Singleton
    {
    public:
        static T* getInstance()
        {
            static std::unique_ptr<T> instance = std::make_unique<T>();
            return instance.get();
        }

    protected:
        Singleton()                    = default;
        Singleton(const Singleton<T>&) = default;
    };
}  // namespace HollowEngine

#endif
