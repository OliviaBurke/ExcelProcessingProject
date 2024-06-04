# restapi_source = files('restapi_server.cpp', 
#                                   'restapi_restapi.cpp')

# restapi_static_library = static_library('restapi_static', 
#                                         restapi_source,
#                                         cpp_args : cpp_flags, 
#                                         dependencies: [dep_list])

executable('restapi', 
           'restapi.m.cpp', 
           cpp_args : cpp_flags,
        #    link_with : restapi_static_library,
           dependencies: [lib_static_httplib_dep, spdlog_dep],
           install: true)
