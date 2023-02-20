service_source = files('service_service.cpp', 'service_cli_data.cpp')

service_include = include_directories('.')

lib_static_service = static_library('service',
                            service_source,
                            cpp_args : cpp_flags, 
                            install: false,
                            dependencies: [cli11_core_dep,
                                           spdlog_dep])

lib_static_service_dep = declare_dependency(link_with: lib_static_service,
                                           include_directories: service_include,
                                           dependencies: [cli11_core_dep,
                                                          spdlog_dep])