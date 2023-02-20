motion_source = files('motion_motion.cpp')

motion_static_library = static_library('motion_static', motion_source,
                                        cpp_args : cpp_flags, 
                                        dependencies: [cli11_core_dep, 
                                                       imgui_dep, 
                                                       opengl_dep, 
                                                       thread_dep,
                                                       libdl_dep,
                                                       spdlog_dep,
                                                       fmt_dep])

executable('motion', 
           'motion.m.cpp',  
           link_with : motion_static_library,
           link_args: ['-lglfw'],
           install: true,
           dependencies: [cli11_core_dep, 
                          imgui_dep, 
                          opengl_dep, 
                          thread_dep,
                          libdl_dep,
                          spdlog_dep,
                          fmt_dep])
