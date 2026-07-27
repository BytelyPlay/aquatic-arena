module;
#include <condition_variable>

#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include <thread>

module OpenGLRenderingEngine;
import Logger;
import Vecs;
import RenderableSnapshot;

// PUBLIC
OpenGLRenderingEngine::OpenGLRenderingEngine()
= default;

// PUBLIC
bool OpenGLRenderingEngine::init(
    std::shared_ptr<const RenderableContainerAccessor> accessor,
    const uint& width, const uint& height,
    const std::string& title
)
{
    std::condition_variable cv;
    std::mutex cvMutex;

    std::unique_lock lock(cvMutex);

    renderThread = std::thread([
        this,
        width, height, &title,
        &cv, accessor
        ]()
    {
        if (!initAll(
            width, height, title
        ))
        {
            log.warn("Couldn't fully initialize everything.");
            cv.notify_all();
            return;
        }
        initRenderingLoop(accessor);

        initialized = true;
        cv.notify_all();
    });
    cv.wait(lock);
    return initialized;
}

void OpenGLRenderingEngine::shutdown()
{
    shouldRender = false;

    glfwDestroyWindow(window);

    initialized = false;
    window = nullptr;
}

// PUBLIC
Vecs::Vec4f OpenGLRenderingEngine::getBackgroundColor()
{
    return this->backgroundColor;
}

void OpenGLRenderingEngine::setBackgroundColor(Vecs::Vec4f backgroundColor)
{
    this->backgroundColor = backgroundColor;
}

// PRIVATE
bool OpenGLRenderingEngine::initGLFW()
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

bool OpenGLRenderingEngine::initGlad()
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

bool OpenGLRenderingEngine::initOpenGL()
{
    log.info("OpenGL Successfully initialized.");
    return true;
}

bool OpenGLRenderingEngine::initAll(
    int windowWidth, int windowHeight,
    const std::string& windowTitle
)
{
    return initGLFW() && createWindowAndSetupContext(
            windowWidth, windowHeight,
            windowTitle, nullptr,
            nullptr
          ) && initGlad() && initOpenGL();
}

// PRIVATE
void OpenGLRenderingEngine::initRenderingLoop(
    std::shared_ptr<const RenderableContainerAccessor> accessor
)
{
    while (true)
    {
        if (!shouldRender) break;
        renderFrame(accessor);
    }
    glfwMakeContextCurrent(nullptr);
}
// PRIVATE
void OpenGLRenderingEngine::renderFrame(
    const std::shared_ptr<const RenderableContainerAccessor> accessor
)
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

    std::vector<RenderableSnapshot> snapshots = accessor->getContainerSnapshot();

    for (const RenderableSnapshot& snapshot : snapshots)
    {
        snapshot.model
    }

    glfwSwapBuffers(window);
}

// PRIVATE
bool OpenGLRenderingEngine::createWindowAndSetupContext(
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

