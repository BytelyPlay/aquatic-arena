module;
#include <condition_variable>
#include <thread>

#include "GLFW/glfw3.h"

export module AquaticRendering;
import Logger;

/**
 * This class, is the class you need to start with, to begin using this library.
 */
export class AquaticRendering
{
    constexpr static int OPENGL_MAJOR_VERSION = 4;
    constexpr static int OPENGL_MINOR_VERSION = 6;
public:
    /**
     * Initializes everything and begins the rendering loop.
     * @return Whether it was successful or not.
     */
    bool init(int windowWidth, int windowHeight, std::string& windowTitle);
    /**
     * Resets everything completely, you have to call init again.
     */
    void stopRendering();
public:
    /**
     * Constructor for AquaticRendering.
     */
    AquaticRendering();
private:
    bool initGLFW();
    bool initGlad();
    bool initOpenGL();

    bool initAll(int windowWidth, int windowHeight, std::string& windowTitle);
private:
    void renderFrame();
    void initRenderingLoop();
private:
    bool createWindowAndSetupContext(
        int width, int height,
        std::string title,
        GLFWmonitor* monitor, GLFWwindow* share
    );
private:
    std::thread renderThread;
    std::atomic_bool shouldRender = true;

    GLFWwindow* window = nullptr;
    bool initialized = false;

    Logger& log = Logger::getInstance();
public:
    AquaticRendering(const AquaticRendering&) = delete;
    AquaticRendering(AquaticRendering&&) = delete;

    AquaticRendering operator=(const AquaticRendering&) = delete;
    AquaticRendering operator=(AquaticRendering&&) = delete;
};
