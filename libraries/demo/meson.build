demo_source = files('demo_dummy.cpp')

demo_include = include_directories('.')

lib_demo_dep_list = [cli11_core_dep,
                    spdlog_dep,
                    pybind11_dep,
                    py_dep]

py_installation.extension_module('demo',
    sources : demo_source, 
    dependencies : lib_demo_dep_list,
    link_language : 'cpp',
        override_options: [
            'cpp_rtti=true',
            'cython_version=3',
        ]
)

# lib_static_demo = static_library('demo',
#                             demo_source,
#                             cpp_args : cpp_flags_no_warn, 
#                             install: false,
#                             dependencies: lib_demo_dep_list)

# lib_static_demo_dep = declare_dependency(link_with: lib_static_demo,
#                                            include_directories: demo_include,
#                                            dependencies: lib_demo_dep_list)