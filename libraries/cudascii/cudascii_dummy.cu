#include <cuda_runtime.h>

namespace cudascii {

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
        gray_index = (int) fmin(c_srgb * gray_levels, gray_levels - 1.);

        // Final character representing the gray level of the RGB pixel
        out = gray_level_lookup[gray_index];

    }

}
