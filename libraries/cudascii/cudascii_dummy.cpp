#include <cudascii_dummy.hpp>

#include <cuda_runtime.h>
#include <cimg_cimg.hpp>

namespace cudascii {

    void pixel_to_ascii(int *r, int *g, int *b);

    std::tuple<int, int, int> get_image_size(const std::string &filename) {

        // Load Image using CImg
        cimg_library::CImg<unsigned char> src(filename.c_str());

        // Get the image dimensions
        int width = src.width();
        int height = src.height();
        int depth = src.depth();

        return {width, height, depth};

    }

    // KEEP THIS FOR LATER!!!
    // std::tuple<int, int, int> image_to_ascii(const std::string &filename) {

    //     // Load Image using CImg
    //     cimg_library::CImg<unsigned char> src(filename);

    //     // Get the image dimensions
    //     int width = src.width();
    //     int height = src.height();
    //     int depth = src.depth();

    //     // Assess how much memory is needed for image
    //     const unsigned int N = width*height*depth;
    //     const unsigned int bytes = N * sizeof(char);

    //     // Allocate GPU memory
    //     int *d_a;
    //     cudaMalloc((char**)&d_a, bytes);

    //     // Copy the image from host (CPU) to device (GPU)
    //     cudaMemcpy(d_a, src, bytes, cudaMemcpyHostToDevice);

    //     // Call the pixel_to_ascii code here

    //     // Copy the ascii array from device (GPU) to host (CPU)
    //     cudaMemcpy(h_a, d_a, bytes, cudaMemcpyDeviceToHost);

    //     // Don't forget to free memory!!!!

    // }
    
}
