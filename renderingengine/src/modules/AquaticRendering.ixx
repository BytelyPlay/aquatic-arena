module;
#include <thread>

#include "GLFW/glfw3.h"

export module AquaticRendering;
import Logger;
import Vecs;

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
public:
    Vecs::Vec4f getBackgroundColor();
    void setBackgroundColor(Vecs::Vec4f backgroundColor);
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
    /*
    TODO: Allow the user to use custom shaders.
    Add some kind of method to change the shaders.
    */
    /**
     * In this Vec4 X = R, Y = G, Z = B, W = A
     */
    Vecs::Vec4f backgroundColor = {0.0f, 0.0f, 0.0f, 0.0f};
public:
    AquaticRendering(const AquaticRendering&) = delete;
    AquaticRendering(AquaticRendering&&) = delete;

    AquaticRendering operator=(const AquaticRendering&) = delete;
    AquaticRendering operator=(AquaticRendering&&) = delete;
};
