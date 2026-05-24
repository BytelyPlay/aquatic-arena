module;
#include <condition_variable>
#include <thread>

#include "GLFW/glfw3.h"

export module AquaticRendering;

/**
 * This class, is the class you need to start with, to begin using this library.
 */
export class AquaticRendering
{
public:
    /**
     * Initialize all prerequisites.
     * @return Whether it was successful or not.
     */
    bool init();
    /**
     * Begins rendering.
     * @return Whether it was successful or not.
     */
    bool initRendering();
    void stopRendering();
public:
    /**
     * Constructor for AquaticRendering.
     */
    AquaticRendering();
private:
    void initRenderingLoop();
private:
    std::thread renderThread;
    std::atomic_bool shouldRender = true;

    GLFWwindow* window;
    bool initialized = false;
public:
    AquaticRendering(const AquaticRendering&) = delete;
    AquaticRendering(AquaticRendering&&) = delete;

    AquaticRendering operator=(const AquaticRendering&) = delete;
    AquaticRendering operator=(AquaticRendering&&) = delete;
};
