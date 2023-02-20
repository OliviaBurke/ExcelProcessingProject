#include <motion_motion.hpp>

// includes

namespace motion
{

int Motion::test2(const int num) const noexcept
{
    return num * num;
}


int Motion::test3(const int num) noexcept
{
    anotherNum += 1;
    return anotherNum + num;
}

}

