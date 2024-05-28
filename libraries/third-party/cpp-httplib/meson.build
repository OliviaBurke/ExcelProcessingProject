httplib_source = files('httplib_httplib.cpp')

httplib_include = include_directories('.')

lib_static_httplib = static_library('httplib',
                            httplib_source,
                            cpp_args : cpp_flags, 
                            dependencies: [cpp_httplib_dep],
                            install: false)

lib_static_httplib_dep = declare_dependency(link_with: lib_static_httplib,
                                           include_directories: httplib_include,
                                            dependencies: [cpp_httplib_dep])