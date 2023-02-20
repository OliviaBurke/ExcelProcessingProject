#ifndef MOTION_MOTION
#define MOTION_MOTION

// includes

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace motion 
{

class Motion
{
    public:

        Motion()
        {
            // this is a constructor 
        }

        /**
         * @brief test 1
         * 
         * @param num generic number
         * @return int returns the argument passed in
         */
        [[nodiscard]] inline int test1(const int num) const noexcept
        {
            return num;
        }

        [[nodiscard]] int test2(const int num) const noexcept;

        [[nodiscard]] int test3(const int num) noexcept;

        inline void testSanitizer() const noexcept
        {
            char *s = reinterpret_cast<char*>(std::malloc(100));
            std::strcpy(s, "Hello world!");
            printf("string is: %s\n", s);
        }

    private:

        int anotherNum {0};

};

}


#endif