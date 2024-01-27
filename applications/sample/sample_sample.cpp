#include <sample_sample.hpp>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"
#pragma GCC diagnostic ignored "-Wold-style-cast"
#include <selene/img_io/IO.hpp>
#include <selene/img_io/jpeg/Read.hpp>
#pragma GCC diagnostic pop

namespace sample {

    Sample::Sample(){
        sln::DynImage img_data = sln::read_image(sln::FileReader("/home/aschwartz/Downloads/kitten.jpg"));
    }

}