#include <sample_sample.hpp>

#include <iostream>

#include <cimg_cimg.hpp>

namespace sample {

Sample::Sample()
{
    // https://stackoverflow.com/questions/3291923/how-to-get-rgb-value-by-cimg
    cimg_library::CImg<unsigned char> src("/build/applications/sample/assets/kitten-000017380158_Smaller.jpg");
    int width = src.width();
    int height = src.height();
    std::cout << width << "x" << height << std::endl;
    for (int r = 0; r < height; r++)
        for (int c = 0; c < width; c++)
            std::cout << "(" << r << "," << c << ") ="
                 << " R" << static_cast<int>(src(c, r, 0, 0)) << " G" << static_cast<int>(src(c, r, 0, 1)) << " B"
                 << static_cast<int>(src(c, r, 0, 2)) << std::endl;
}

}  // namespace sample