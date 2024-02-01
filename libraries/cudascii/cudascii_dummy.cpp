#include <cudascii_dummy.hpp>

#include <cuda_runtime.h>
#include <cimg_cimg.hpp>

namespace cudascii {

    void pixel_to_ascii(int *r, int *g, int *b);

    std::tuple<int, int, int> get_image_size(const std::string &filename) {

        // Load Image using CImg
        cimg_library::CImg<unsigned char> src(filename);

        // Get the image dimensions
        int width = src.width();
        int height = src.height();
        int channels = src.channels();

        return {img_width, img_height, img_channels};

    }

}
