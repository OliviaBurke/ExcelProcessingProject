#include <pybind11/pybind11.h>

#include <cstdlib>

namespace cudascii {

    // Cuda kernel function mapping an RGB pixel to a gray level char
    void pixel_to_ascii(unsigned char *out, unsigned char r, unsigned char g, unsigned char b);
    void set_high(unsigned char *out);
    
    bool test_cuda();
    std::tuple<int, int, int> get_image_size(const std::string &filename);

    PYBIND11_MODULE(cudascii, m) {
        m.doc() = "pybind11 cimg example plugin"; // optional module docstring

        m.def("get_image_size", &get_image_size, "A function that reads an image and returns its dimensions");

        m.def("test_cuda", &test_cuda, "A function to test cuda setting a vector");
    }

}
