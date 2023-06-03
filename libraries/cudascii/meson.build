cudascii_source = files('cudascii_dummy.cpp')

cudascii_include = include_directories('.')

lib_cudascii_dep_list = [cli11_core_dep,
                    spdlog_dep,
                    pybind11_dep,
                    libvips_dep,
                    py_dep]

py_installation.extension_module('cudascii',
    sources : cudascii_source, 
    dependencies : lib_cudascii_dep_list,
    link_language : 'cpp',
        override_options: [
            'cpp_rtti=true',
            'cython_version=3',
        ]
)