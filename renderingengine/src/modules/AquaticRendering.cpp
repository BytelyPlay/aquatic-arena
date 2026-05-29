module;
#include <cassert>
#include <condition_variable>

#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include <thread>

#include "glm/vec4.hpp"

module AquaticRendering;
import Logger;

// PUBLIC
bool AquaticRendering::init(
    int windowWidth, int windowHeight, std::string& windowTitle
)
{
    std::condition_variable cv;
    std::mutex cvMutex;

    std::unique_lock lock(cvMutex);

    renderThread = std::thread([
        this,
        windowWidth, windowHeight, &windowTitle,
        &cv
    ]()
    {
        if (!initAll(
            windowWidth, windowHeight, windowTitle
        ))
        {
            log.warn("Couldn't fully initialize everything.");
            cv.notify_all();
            return;
        }
        initRenderingLoop();
        initialized = true;
        cv.notify_all();
    });
    cv.wait(lock);
    return initialized;
}

void AquaticRendering::stopRendering()
{
    glfwDestroyWindow(window);

    shouldRender = false;
    initialized = false;
    window = nullptr;
}

// PUBLIC
AquaticRendering::AquaticRendering()
= default;
// PRIVATE
bool AquaticRendering::initGLFW()
{
    if (glfwInit())
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,
            OPENGL_MAJOR_VERSION);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,
            OPENGL_MINOR_VERSION);

        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        log.info("GLFW successfully initialized");
        return true;
    } else
    {
        log.error("Couldn't initialize GLFW.");
        return false;
    }
}

bool AquaticRendering::initGlad()
{
    if (!gladLoadGL(glfwGetProcAddress))
    {
        log.error("Couldn't load glad.");
        return false;
    } else
    {
        log.info("Glad loaded successfully.");
        return true;
    }
}

bool AquaticRendering::initOpenGL()
{
    log.info("OpenGL Successfully initialized.");
    return true;
}

bool AquaticRendering::initAll(
    int windowWidth, int windowHeight,
    std::string& windowTitle
)
{
    return initGLFW() && createWindowAndSetupContext(
            windowWidth, windowHeight,
            windowTitle, nullptr,
            nullptr
          ) && initGlad() && initOpenGL();
}

// PRIVATE
void AquaticRendering::initRenderingLoop()
{
    while (true)
    {
        if (!shouldRender) break;
        renderFrame();
    }
    glfwMakeContextCurrent(nullptr);
}
// PRIVATE
void AquaticRendering::renderFrame()
{
    // This is just a temporary placeholder.
    glfwPollEvents();

    glClearColor(
        backgroundColor.x,
        backgroundColor.y,
        backgroundColor.z,
        backgroundColor.w
    );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwSwapBuffers(window);
}

// PRIVATE
bool AquaticRendering::createWindowAndSetupContext(
    int width, int height,
    std::string title,
    GLFWmonitor* monitor, GLFWwindow* share
)
{
    window = glfwCreateWindow(
        width, height,
        title.c_str(),
        monitor, share
    );
    if (!window)
    {
        log.error("Failed to create window.");
        return false;
    }
    glfwMakeContextCurrent(window);
    return true;
}

// PRIVATE
// PUBLIC

