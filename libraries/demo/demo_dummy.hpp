#include <pybind11/pybind11.h>

namespace demo {

    int add(const int i, const int j) {
        return i + j;
    }

    PYBIND11_MODULE(demo, m) {
        m.doc() = "pybind11 demo plugin"; // optional module docstring

        m.def("add", &add, "A function that adds two numbers");
    }

}
