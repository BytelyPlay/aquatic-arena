module;
#include <thread>

#include <GLFW/glfw3.h>
#include <memory>
#include <sys/types.h>

export module OpenGLRenderingEngine;
import Logger;
import Vecs;
import AquaticRendering;
import RenderableContainerAccessor;

export class OpenGLRenderingEngine : public AquaticRendering
{
    constexpr static int OPENGL_MAJOR_VERSION = 4;
    constexpr static int OPENGL_MINOR_VERSION = 6;
public:
    OpenGLRenderingEngine();
public:
    /**
     * Initializes everything and begins the rendering loop.
     * @return Whether it was successful or not.
     */
    bool init(
        std::shared_ptr<const RenderableContainerAccessor> accessor,
        const uint& width, const uint& height,
        const std::string& title
    ) override;
    /**
     * Shuts down the engine
     */
    void shutdown() override;
public:
    /**
     * Gets the background color that will be rendered in the background.
     *
     * @return The background color that is being rendered.
     */
    Vecs::Vec4f getBackgroundColor() override;

    /**
     * Sets the background color to something.
     * @param backgroundColor The background color
     */
    void setBackgroundColor(Vecs::Vec4f backgroundColor) override;
private:
    bool initGLFW();
    bool initGlad();
    bool initOpenGL();

    bool initAll(int windowWidth, int windowHeight, const std::string& windowTitle);
private:
    void renderFrame(std::shared_ptr<const RenderableContainerAccessor> accessor);
    void initRenderingLoop(std::shared_ptr<const RenderableContainerAccessor> accessor);
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
public:
    Logger& log = Logger::getInstance();

    /*
    TODO: Allow the user to use custom shaders.
    Add some kind of method to change the shaders.
    */

    /**
     * In this Vec4 X = R, Y = G, Z = B, W = A
     */
    Vecs::Vec4f backgroundColor = {.x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f};
public:
    OpenGLRenderingEngine(const OpenGLRenderingEngine&) = delete;
    OpenGLRenderingEngine(OpenGLRenderingEngine&&) = delete;

    OpenGLRenderingEngine operator=(const OpenGLRenderingEngine&) = delete;
    OpenGLRenderingEngine operator=(OpenGLRenderingEngine&&) = delete;
};
