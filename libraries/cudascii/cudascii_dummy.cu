#include <cuda_runtime.h>

#include <cmath>
#include <string>

namespace {
// Algorithm Parameterization
// const std::string gray_levels_fine =
// "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~i!lI;:,\"^`. ";
const constexpr char* gray_level_lookup{"@%#*+=-:. "};
const constexpr int gray_levels = 10;
const constexpr float RED_WEIGHT = 0.2126;
const constexpr float GREEN_WEIGHT = 0.7152;
const constexpr float BLUE_WEIGHT = 0.0722;
const constexpr float CONVERSION_THRESHOLD = 0.0031308;
const constexpr float BELOW_THRESHOLD_SCALAR = 12.92;
const constexpr float ABOVE_THRESHOLD_SCALAR = 1.055;
const constexpr float ABOVE_THRESHOLD_EXPONENT = 1 / 2.4;
const constexpr float ABOVE_THRESHOLD_OFFSET = -0.055;
}  // namespace

namespace cudascii {

    __global__ void pixel_to_ascii(unsigned char *r, unsigned char *g, unsigned char *b) {

        // Thread index
        int i = threadIdx.x + blockIdx.x * blockDim.x;

        float c_linear, c_srgb;
        int gray_index;
        unsigned char out;
        
        // Standard linear combination
        c_linear = RED_WEIGHT*(r/255.) + GREEN_WEIGHT*(g/255.) + BLUE_WEIGHT*(b/255.);
        
        // If gray level is very dark, use linear scaling
        if (c_linear <= CONVERSION_THRESHOLD)
            c_srgb = BELOW_THRESHOLD_SCALAR * c_linear;

        // Non linear scaling to adjust for gamma exposure
        else
            c_srgb = ABOVE_THRESHOLD_SCALAR * powf(c_linear,ABOVE_THRESHOLD_EXPONENT) + ABOVE_THRESHOLD_OFFSET;
        
        // Scale c_srgb to the gray levels while handling an edge case of c_srgb = 1
        gray_index = (int) fmin(c_srgb * gray_levels, gray_levels - 1.);

        // Final character representing the gray level of the RGB pixel
        out = gray_level_lookup[gray_index];

    }
}