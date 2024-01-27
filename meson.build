project('securitysystem', 'cpp',
  version : '0.1',
  default_options : [
                     #'b_lto_mode=default', 
                     #'b_lto_threads=0', 
                     #'b_lto=true', 
                     'warning_level=3', 
                     'cpp_std=c++20', 
                     'prefer_static=true', 
                     'b_staticpic=true', 
                     'werror=true',
                     ])  

cpp_flags = [ '-Wshadow', 
              '-Wold-style-cast', 
              '-Wunused', 
              '-Woverloaded-virtual', 
              '-Wduplicated-cond', 
              '-Wduplicated-branches', 
              '-Wlogical-op', 
              '-Wnull-dereference', 
              '-Wuseless-cast', 
              '-Wdouble-promotion', 
              '-Wformat=2', 
              '-Wuninitialized',
              '-Wpessimizing-move',
              '-Wredundant-move', 
              ]

# statically link libstdc++ (https://mesonbuild.com/Creating-Linux-binaries.html#building-and-installing)
add_project_arguments(['-fuse-ld=gold', '-static-libstdc++'], language: 'cpp')

if meson.current_build_dir().contains('debugsan')
  message('debugsan build type in use')
elif meson.current_build_dir().contains('debug')
  message('debug build type in use')
  add_project_link_arguments(['-DDEBUG', '-ggdb'], language: 'cpp')
elif meson.current_build_dir().contains('release')
  message('release build type in use')
elif meson.current_build_dir().contains('coverage')
  message('coverage build type in use')
endif


###############################################################################################
# dependencies (system, in this case, a container)

# opengl
# https://github.com/Abdullah-AlAttar/OpenGL_meson/blob/master/meson.build
opengl_dep = dependency('gl')

# threads
thread_dep = dependency('threads')

# dl
# https://github.com/ReneNyffenegger/gcc-create-library/blob/master/src/meson.build
cpp = meson.get_compiler('cpp')
libdl_dep = cpp.find_library('dl')

# boost
# headers live in /usr/include/boost/ and libraries live in /usr/lib/x86_64-linux-gnu/
boost_dep = dependency('boost')

# python dependency handler
pymod = import('python')
py_installation = pymod.find_installation('python3.11') # /usr/include/python3.11/Python.h
py_dep = py_installation.dependency()


###############################################################################################
# wrap dependencies
# requires a 'meson wrap install <name of library>' before the below scripting will work

# regarding "werror" flag: https://mesonbuild.com/Release-notes-for-0-54-0.html#per-subproject-default_library-and-werror-options
# subprojects have warnings but this family of libraries and projects should not have warnings

scope_guard_dep = declare_dependency(include_directories: 'libraries/third-party/scopeguard/')

# nlohmann_json
nlohmann_json_proj = subproject('nlohmann_json', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
nlohmann_json_dep = nlohmann_json_proj.get_variable('nlohmann_json_dep')

# cli11
cli11_proj = subproject('cli11', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
cli11_core_dep = cli11_proj.get_variable('CLI11_dep')

# fmt
fmt_proj = subproject('fmt', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
fmt_dep = fmt_proj.get_variable('fmt_dep')

# spdlog
spdlog_proj = subproject('spdlog', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
spdlog_dep = spdlog_proj.get_variable('spdlog_dep')

# pybind11
pybind11_proj = subproject('pybind11', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
pybind11_dep = pybind11_proj.get_variable('pybind11_dep')

# libpng
libpng_proj = subproject('libpng', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
libpng_dep = libpng_proj.get_variable('libpng_dep')

# libjpeg
libjpeg_turbo_proj = subproject('libjpeg-turbo', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
libjpeg_turbo_dep = libjpeg_turbo_proj.get_variable('jpeg_dep')

# selene (image manipulation)
# for providing dependency info to CMake: https://github.com/mesonbuild/meson/issues/12067
# General example: https://github.com/openbmc/bmcweb/blob/master/meson.build#L284
# cmake = import('cmake')
# cmake_opts = cmake.subproject_options()

# # if meson.current_build_dir().contains('debug')
# #   cmake_opts.add_cmake_defines({ 
# #                                 'CMAKE_POSITION_INDEPENDENT_CODE': true, 
# #                                 # 'BUILD_SHARED_LIBS': 'OFF', 
# #                                 # 'ENABLE_LIB_ONLY': true,
# #                                 'SELENE_USE_LIBTIFF': 'OFF',
# #                                 'SELENE_USE_LIBJPEG': 'ON',
# #                                 'SELENE_USE_LIBPNG': 'ON',
# #                                 'CMAKE_BUILD_TYPE': 'Debug'})
# # else
# #   cmake_opts.add_cmake_defines({ 
# #                                 'CMAKE_POSITION_INDEPENDENT_CODE': true, 
# #                                 # 'BUILD_SHARED_LIBS': 'OFF', 
# #                                 # 'ENABLE_LIB_ONLY': true,
# #                                 'SELENE_USE_LIBTIFF': 'OFF',
# #                                 'SELENE_USE_LIBJPEG': 'ON',
# #                                 'SELENE_USE_LIBPNG': 'ON',
# #                                 'CMAKE_BUILD_TYPE': 'Release'})
# # endif

# cmake_opts.append_compile_args('cpp', '-w') # silence warnings
# selene_proj = cmake.subproject('selene', options: cmake_opts)
# selene_dep = selene_proj.dependency('selene')

# cuda_dep = dependency('cuda', version : '>=10', modules : ['cublas'])

###############################################################################################
# now, binary build targets and libraries

subdir('libraries')

subdir('applications')
