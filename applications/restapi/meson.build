restapi_source = files('restapi_server.cpp', 
                                  'restapi_restapi.cpp')

restapi_static_library = static_library('restapi_static', 
                                        restapi_source,
                                        cpp_args : cpp_flags, 
                                        dependencies: [dep_list, dependency('libpistache')])

executable('restapi', 
           'restapi.m.cpp', 
           cpp_args : cpp_flags,
           link_with : restapi_static_library,
           install: true)
