module;
#include <GLFW/glfw3.h>

module AquaticRendering;
import Logger;

// PUBLIC
bool AquaticRendering::init()
{
    if (glfwInit())
        Logger::getInstance().info("GLFW successfully initialized");
    else
    {
        Logger::getInstance().error("Couldn't initialize GLFW.");
        return false;
    }
    initialized = true;
    return true;
}

bool AquaticRendering::initRendering()
{
    if (!initialized) return false;
    renderThread = std::thread([this]()
    {
        initRenderingLoop();
    });
    renderThread.detach();

    return true;
}

void AquaticRendering::stopRendering()
{
    shouldRender = false;
}

// PUBLIC
AquaticRendering::AquaticRendering()
= default;

// PRIVATE
void AquaticRendering::initRenderingLoop()
{
    while (true)
    {
        if (!shouldRender) return;
    }
}

// PRIVATE
// PUBLIC

