#include <manager_manager.hpp>

// includes

namespace manager
{

int Manager::test2(const int num) const noexcept
{
    return num * num;
}


int Manager::test3(const int num) noexcept
{
    anotherNum += 1;
    return anotherNum + num;
}

}

