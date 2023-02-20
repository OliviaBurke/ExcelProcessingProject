project('securitysystem', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20', 'prefer_static=true'])  

cpp_flags = ['-Werror',
             '-Wshadow', 
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
             '-Wredundant-move']

# statically link libstdc++ (https://mesonbuild.com/Creating-Linux-binaries.html#building-and-installing)
add_global_link_arguments(['-fuse-ld=gold', '-static-libstdc++'], language: 'cpp')

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

# dependencies (system)

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
# boost_dep = dependency('boost')

# dependencies (third party)
# requires a 'meson wrap install <name of library>' before the below scripting will work

scope_guard_dep = declare_dependency(include_directories: 'libraries/third-party/scopeguard/')

# nlohmann_json
nlohmann_json_proj = subproject('nlohmann_json')
nlohmann_json_dep = nlohmann_json_proj.get_variable('nlohmann_json_dep')

# cli11
cli11_proj = subproject('cli11')
cli11_core_dep = cli11_proj.get_variable('CLI11_dep')

# fmt
fmt_proj = subproject('fmt')
fmt_dep = fmt_proj.get_variable('fmt_dep')

# spdlog
spdlog_proj = subproject('spdlog')
spdlog_dep = spdlog_proj.get_variable('spdlog_dep')

# libspng
libspng_proj = subproject('libspng')
libspng_dep = libspng_proj.get_variable('spng_dep')

subdir('libraries')

subdir('applications')
