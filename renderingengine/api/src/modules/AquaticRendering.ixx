module;
#include <memory>
#include <vector>

export module AquaticRendering;
import Renderable;

export class AquaticRendering
{
public:
    /**
     * Construct AquaticRendering.
     */
    AquaticRendering();
public:
    /**
     * Begins the render loop.
     */
    void init();
public:
    void addRenderable(std::shared_ptr<Renderable> renderable);
    std::shared_ptr<Renderable> getRenderable(int index);

    size_t sizeOfRenderables();
    void removeRenderable(std::shared_ptr<Renderable> renderable);
private:
    std::vector<std::shared_ptr<Renderable>> renderVector;
public:
    AquaticRendering(const AquaticRendering&) = delete;
    AquaticRendering(AquaticRendering&&) = delete;

    AquaticRendering operator=(const AquaticRendering&) = delete;
    AquaticRendering operator=(AquaticRendering&&) = delete;
};
