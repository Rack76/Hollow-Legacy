#include "GameEngine/util/NameAllocator.h"
#include <limits>
#include <iostream>

int HollowEngine::NameAllocator::getName()
{
    if (restoredNames.size() == 0)
    {
        if (firstUnusedName != maxCount)
        {
            allocatedNames.insert({ firstUnusedName , firstUnusedName });
            return firstUnusedName++;
        }
        else
        {
            std::cerr << "name not allocated : max count reached";
            return -1;
        }
    }
    else
    {
        auto it = restoredNames.begin();
        int returnValue = it->first;
        restoredNames.erase(returnValue);
        allocatedNames.insert({ returnValue, returnValue });
        return returnValue;
    }
}

void HollowEngine::NameAllocator::returnName(int name)
{
    if (allocatedNames.find(name) != allocatedNames.end())
    {
        allocatedNames.erase(name);
        restoredNames.insert({ name, name });
    }
    else
        std::cerr << "name not returned : name not allocated";
}

bool HollowEngine::NameAllocator::isReserved(int name) {
    if (allocatedNames.find(name) != allocatedNames.end())
        return true;
    return false;
}

bool HollowEngine::NameAllocator::noNameReserved()
{
    return allocatedNames.size() == 0;
}

void HollowEngine::NameAllocator::setMaxCount(int _maxCount) {
    maxCount = maxCount;
}

int HollowEngine::NameAllocator::lastNameReserved()
{
    if (allocatedNames.size() == 0)
        return -1;
    return std::prev(allocatedNames.end())->first;
}

std::unordered_map<int, int>& HollowEngine::NameAllocator::data()
{
    return allocatedNames;
}
