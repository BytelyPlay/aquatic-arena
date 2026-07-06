module;
#include <memory>

export module AquaticRendering;
import Renderable;
import RenderableAccessor;
import OpenGLRenderingEngine;
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
        std::shared_ptr<RenderableAccessor> accessor
    ) = 0;
public:
    /**
     * Sets the color of the background.
     * There should be an assert
     * just in case the developer set the background color
     * before initing the engine.
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
    virtual ~AquaticRendering() = default;
};
