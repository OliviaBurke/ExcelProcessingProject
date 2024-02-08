#include <cudascii_dummy.hpp>

#include <cuda_runtime.h>
#include <cimg_cimg.hpp>

namespace cudascii {

    void pixel_to_ascii(int *r, int *g, int *b);

    std::tuple<int, int, int> get_image_size(const std::string &filename) {

        // Load Image using CImg
        cimg_library::CImg<unsigned char> src(filename.c_str());

        // Get the image dimensions
        const int width = src.width();
        const int height = src.height();
        const int channels = src.spectrum();

        return {width, height, channels};

    }

    std::string image_to_ascii(const std::string &filename) {

        // Load Image using CImg
        cimg_library::CImg<unsigned char> src(filename.c_str());

        // Get the image dimensions
        const int width = src.width();
        const int height = src.height();
        const int channels = src.spectrum();

        // Assess how much memory is needed for image
        const unsigned int N = width*height*channels;
        const unsigned int bytes = N * sizeof(unsigned char);

        // Allocate GPU memory
        int *d_a;
        cudaMalloc((unsigned char**)&d_a, bytes);

        // Copy the image from host (CPU) to device (GPU)
        cudaMemcpy(d_a, src, bytes, cudaMemcpyHostToDevice);

        // Call the pixel_to_ascii code here
        

        // Copy the ascii array from device (GPU) to host (CPU)
        // cudaMemcpy(h_a, d_a, bytes, cudaMemcpyDeviceToHost);

        // Don't forget to free memory!!!!
        cudaFree(d_a);

        return "hey";

    }
    
}
