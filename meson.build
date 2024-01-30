project('securitysystem', 'cpp',
  version : '0.1',
  default_options : [
                     #'b_lto_mode=default', 
                     #'b_lto_threads=0', 
                     #'b_lto=true', 
                     'warning_level=3', 
                     'cpp_std=c++2a', 
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

dep_list = []

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
dep_list += opengl_dep

# threads
thread_dep = dependency('threads')
dep_list += thread_dep

# dl
# https://github.com/ReneNyffenegger/gcc-create-library/blob/master/src/meson.build
cpp = meson.get_compiler('cpp')
libdl_dep = cpp.find_library('dl')
dep_list += libdl_dep

# boost
# headers live in /usr/include/boost/ and libraries live in /usr/lib/x86_64-linux-gnu/
boost_dep = dependency('boost')
dep_list += boost_dep

# python dependency handler
pymod = import('python')
py_installation = pymod.find_installation('python3.11') # /usr/include/python3.11/Python.h
py_dep = py_installation.dependency()
dep_list += py_dep


###############################################################################################
# wrap dependencies
# requires a 'meson wrap install <name of library>' before the below scripting will work

# regarding "werror" flag: https://mesonbuild.com/Release-notes-for-0-54-0.html#per-subproject-default_library-and-werror-options
# subprojects have warnings but this family of libraries and projects should not have warnings

scope_guard_dep = declare_dependency(include_directories: 'libraries/third-party/scopeguard/')
dep_list += scope_guard_dep

# nlohmann_json
nlohmann_json_proj = subproject('nlohmann_json', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
nlohmann_json_dep = nlohmann_json_proj.get_variable('nlohmann_json_dep')
dep_list += nlohmann_json_dep

# cli11
cli11_proj = subproject('cli11', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
cli11_core_dep = cli11_proj.get_variable('CLI11_dep')
dep_list += cli11_core_dep

# fmt
fmt_proj = subproject('fmt', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
fmt_dep = fmt_proj.get_variable('fmt_dep')
dep_list += fmt_dep

# spdlog
spdlog_proj = subproject('spdlog', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
spdlog_dep = spdlog_proj.get_variable('spdlog_dep')
dep_list += spdlog_dep

# pybind11
pybind11_proj = subproject('pybind11', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
pybind11_dep = pybind11_proj.get_variable('pybind11_dep')
dep_list += pybind11_dep

# libpng
libpng_proj = subproject('libpng', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
libpng_dep = libpng_proj.get_variable('libpng_dep')
dep_list += libpng_dep

# libjpeg
libjpeg_turbo_proj = subproject('libjpeg-turbo', default_options: ['default_library=static',  'warning_level=0', 'werror=false'])
libjpeg_turbo_dep = libjpeg_turbo_proj.get_variable('jpeg_dep')
dep_list += libjpeg_turbo_dep

# selene

selene_deps = []

libselene_img_io_png_dep = cpp.find_library('selene_img_io_png', 
                                  dirs: ['/usr/lib/x86_64-linux-gnu/'], 
                                  has_headers: ['/usr/include/build/selene/selene_config.hpp'],
                                  header_include_directories: include_directories('/usr/include/selene/img_io/png/', '/usr/include/build/selene/'), 
                                  required: true, 
                                  static: true)
selene_deps += libselene_img_io_png_dep

libselene_img_io_jpeg_dep = cpp.find_library('selene_img_io_jpeg', 
                                  dirs: ['/usr/lib/x86_64-linux-gnu/'], 
                                  has_headers: ['/usr/include/build/selene/selene_config.hpp'],
                                  header_include_directories: include_directories('/usr/include/selene/img_io/jpeg/', '/usr/include/build/selene/'), 
                                  required: true, 
                                  static: true)
selene_deps += libselene_img_io_jpeg_dep

libselene_base_dep = cpp.find_library('selene_base', 
                                  has_headers: ['/usr/include/build/selene/selene_config.hpp'],
                                  dirs: ['/usr/lib/x86_64-linux-gnu/'], 
                                  header_include_directories: include_directories('/usr/include/selene/base/', '/usr/include/build/selene/'), 
                                  required: true, 
                                  static: true)
selene_deps += libselene_base_dep

libselene_base_io_dep = cpp.find_library('selene_base_io', 
                                  has_headers: ['/usr/include/build/selene/selene_config.hpp'],
                                  dirs: ['/usr/lib/x86_64-linux-gnu/'], 
                                  header_include_directories: include_directories('/usr/include/selene/base/io', '/usr/include/build/selene/'), 
                                  required: true, 
                                  static: true)
selene_deps += libselene_base_io_dep

# libselene_img_io_tiff_dep = cpp.find_library('selene_img_io_tiff', 
#                                   has_headers: ['/usr/include/build/selene/selene_config.hpp'],
#                                   dirs: ['/usr/lib/x86_64-linux-gnu/'], 
#                                   header_include_directories: include_directories('/usr/include/selene/img_io/tiff/', '/usr/include/build/selene/'), 
#                                   required: true, 
#                                   static: true)
# selene_deps += libselene_img_io_tiff_dep

libselene_img_io_dep = cpp.find_library('selene_img_io', 
                                  has_headers: ['/usr/include/build/selene/selene_config.hpp'],
                                  dirs: ['/usr/lib/x86_64-linux-gnu/'], 
                                  header_include_directories: include_directories('/usr/include/selene/img_io', '/usr/include/build/selene/'), 
                                  required: true, 
                                  static: true)
selene_deps += libselene_img_io_dep

selene_img_dep = cpp.find_library('selene_img', 
                                  has_headers: ['/usr/include/build/selene/selene_config.hpp'],
                                  dirs: ['/usr/lib/x86_64-linux-gnu/'], 
                                  header_include_directories: include_directories('/usr/include/selene/img', '/usr/include/build/selene/'), 
                                  required: true, 
                                  static: true)
selene_deps += selene_img_dep

selene_img_ops_dep = cpp.find_library('selene_img_ops', 
                                  has_headers: ['/usr/include/build/selene/selene_config.hpp'],
                                  dirs: ['/usr/lib/x86_64-linux-gnu/'], 
                                  header_include_directories: include_directories('/usr/include/selene/img_ops', '/usr/include/build/selene/'), 
                                  required: true, 
                                  static: true)
selene_deps += selene_img_ops_dep

dep_list += selene_deps

# cuda_dep = dependency('cuda', version : '>=10', modules : ['cublas'])

###############################################################################################
# now, binary build targets and libraries

subdir('libraries')

subdir('applications')
