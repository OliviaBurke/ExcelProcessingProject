#include <demo_dummy.hpp>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"
#pragma GCC diagnostic ignored "-Wold-style-cast"
#include <selene/img_io/IO.hpp>
#include <selene/img_io/jpeg/Read.hpp>
#pragma GCC diagnostic pop

namespace demo
{

    int add(const int i, const int j)
    {
        return i + j;
    }

}
