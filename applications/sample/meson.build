sample_source = files('sample_sample.cpp')

sample_static_library = static_library('sample_static', 
                                        sample_source,
                                        cpp_args : cpp_flags, 
                                        dependencies: [dep_list])

executable('sample', 
           'sample.m.cpp', 
           cpp_args : cpp_flags,
           link_with : sample_static_library,
           install: true)
