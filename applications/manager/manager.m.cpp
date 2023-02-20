#include <manager_manager.hpp>

#include <service_service.hpp>

#include <GLFW/glfw3.h> // will drag system OpenGL headers

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <spdlog/spdlog.h>

#include <iostream>
#include <memory>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    std::unique_ptr<service::Service> manager{std::make_unique<manager::Manager>(argc, argv, "asdf")};
}
