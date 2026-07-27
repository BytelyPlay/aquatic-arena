module;
#include <memory>

export module AquaticRendering;
import Renderable;
import RenderableContainerAccessor;
import Vecs;

export class AquaticRendering
{
protected:
    /**
     * Construct AquaticRendering.
     */
    AquaticRendering();
public:
    /**
     * Begins the render loop.
     * Returns once it begins rendering on another thread.
     *
     * @return Whether it was successful or not.
     */
    virtual bool init(
        std::shared_ptr<const RenderableContainerAccessor> accessor,
        const uint& width, const uint& height,
        const std::string& title
    ) = 0;

    /**
     * Stops rendering and closes the window.
     * This instance cannot be reused after this is called.
     * Please call this before letting this go out of scope or freeing its memory.
     */
    virtual void shutdown() = 0;
public:
    /**
     * Sets the color of the background.
     * There should be an assert
     * just in case the developer set the background color
     * before initializing the engine.
     *
     * @param rgba The background color (RGBA correspondingly) in the 0-1 format
     */
    virtual void setBackgroundColor(Vecs::Vec4f rgba) = 0;
    /**
     * Gets the background color.
     * Should assert just in case the developer tried to check what
     * the background color was before initializing the engine.
     *
     * @return The background color as RGBA correspondingly in the 0-1 format
     */
    virtual Vecs::Vec4f getBackgroundColor() = 0;
public:
    AquaticRendering(const AquaticRendering&) = delete;
    AquaticRendering(AquaticRendering&&) = delete;

    AquaticRendering& operator=(const AquaticRendering&) = delete;
    AquaticRendering& operator=(AquaticRendering&&) = delete;
public:
    virtual ~AquaticRendering();
};
