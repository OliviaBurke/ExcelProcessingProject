#include <pybind11/pybind11.h>
#include <SDL2_image.h>
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
    __global__ void pixel_to_ascii(int *r, int *g, int *b) {

        // Thread index
        int i = threadIdx.x + blockIdx.x * blockDim.x;

        float c_linear, c_srgb;
        int gray_index;
        char out;
        
        // Standard linear combination
        c_linear = RED_WEIGHT*(r/255.) + GREEN_WEIGHT*(g/255.) + BLUE_WEIGHT*(b/255.);
        
        // If gray level is very dark, use linear scaling
        if (c_linear <= CONVERSION_THRESHOLD)
            c_srgb = BELOW_THRESHOLD_SCALAR * c_linear;

        // Non linear scaling to adjust for gamma exposure
        else:
            c_srgb = ABOVE_THRESHOLD_SCALAR * powf(c_linear,ABOVE_THRESHOLD_EXPONENT) + ABOVE_THRESHOLD_OFFSET;
        
        // Scale c_srgb to the gray levels while handling an edge case of c_srgb = 1
        gray_index = (int) fmin(c_srgb * gray_levels, gray_levels - 1.)

        // Final character representing the gray level of the RGB pixel
        out = gray_level_lookup[gray_index]

    }

    std::tuple<int, int, int> get_image_size(const std::string &filename) {

        // SDL2 reads image using char*
        SDL_Surface* image = IMG_LOAD(filename.c_str())

        // Get the image dimensions
        int img_width, img_height, img_channels;
        // img_width = 
        // img_height = 
        // img_channels = 

        return (img_width, img_height, img_channels);

    }

    PYBIND11_MODULE(cudascii, m) {
        m.doc() = "pybind11 cimg example plugin"; // optional module docstring

        m.def("get_image_size", &get_image_size, "A function that reads an image and returns its dimensions");
    }

}
