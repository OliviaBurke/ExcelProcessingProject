#include <pybind11/pybind11.h>
#include <vips/vips8>

namespace cudascii {

    std::tuple<int, int, int> get_image_size(const std::string &filename) {

        VImage img = VImage::new_from_file(filename,
            VImage::option ()->set ("access", VIPS_ACCESS_SEQUENTIAL));

        int img_width = img.width();
        int img_height = img.height();
        int img_channels = img.bands(); // Bands?

        vips_shutdown();

        return (img_width, img_height, img_channels);
    }

    PYBIND11_MODULE(cudascii, m) {
        m.doc() = "pybind11 vips example plugin"; // optional module docstring

        m.def("get_image_size", &get_image_size, "A function that reads an image and returns its dimensions");
    }

}
