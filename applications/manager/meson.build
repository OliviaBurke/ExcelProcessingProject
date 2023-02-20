manager_source = files('manager_manager.cpp')

manager_static_library = static_library('manager_static', 
                                        manager_source,
                                        cpp_args : cpp_flags, 
                                        dependencies: [cli11_core_dep,
                                                       imgui_dep, 
                                                       opengl_dep, 
                                                       thread_dep,
                                                       libdl_dep,
                                                       spdlog_dep,
                                                       fmt_dep,
                                                       lib_static_service_dep,
                                                       sdl2_dep,
                                                       scope_guard_dep,
                                                       ut_dep])

executable('manager', 
           'manager.m.cpp',  
           link_with : manager_static_library,
           link_args: ['-lglfw'],
           install: true,
           dependencies: [cli11_core_dep, 
                          imgui_dep, 
                          opengl_dep, 
                          thread_dep,
                          libdl_dep,
                          spdlog_dep,
                          fmt_dep,
                          lib_static_service_dep,
                          sdl2_dep,
                          scope_guard_dep,
                          ut_dep])

