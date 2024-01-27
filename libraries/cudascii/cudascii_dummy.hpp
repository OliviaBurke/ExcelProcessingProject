#include <pybind11/pybind11.h>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>

namespace cudascii {

    // Algorithm Parameterization
    // const std::string gray_levels_fine = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~i!lI;:,\"^`. ";
    const std::string gray_level_lookup = "@%#*+=-:. ";
    const int gray_levels = 10;
    const float RED_WEIGHT = 0.2126;
    const float GREEN_WEIGHT = 0.7152;
    const float BLUE_WEIGHT = 0.0722;
    const float CONVERSION_THRESHOLD = 0.0031308;
    const float BELOW_THRESHOLD_SCALAR = 12.92;
    const float ABOVE_THRESHOLD_SCALAR = 1.055;
    const float ABOVE_THRESHOLD_EXPONENT = 1/2.4;
    const float ABOVE_THRESHOLD_OFFSET = -0.055;

    // Cuda kernel function mapping an RGB pixel to a gray level char
    // __global__ void pixel_to_ascii(int *r, int *g, int *b);

    // std::tuple<int, int, int> get_image_size(const std::string &filename);

    PYBIND11_MODULE(cudascii, m) {
        m.doc() = "pybind11 cimg example plugin"; // optional module docstring

        m.def("get_image_size", &get_image_size, "A function that reads an image and returns its dimensions");
    }

}
