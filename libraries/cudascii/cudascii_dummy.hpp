#include <pybind11/pybind11.h>

#include <cstdlib>

namespace cudascii {

    // Cuda kernel function mapping an RGB pixel to a gray level char
    void pixel_to_ascii(int *r, int *g, int *b);

    std::tuple<int, int, int> get_image_size(const std::string &filename);

    PYBIND11_MODULE(cudascii, m) {
        m.doc() = "pybind11 cimg example plugin"; // optional module docstring

        m.def("get_image_size", &get_image_size, "A function that reads an image and returns its dimensions");
    }

}
