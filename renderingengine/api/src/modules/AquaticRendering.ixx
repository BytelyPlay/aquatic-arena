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
private:
public:
    AquaticRendering(const AquaticRendering&) = delete;
    AquaticRendering(AquaticRendering&&) = delete;

    AquaticRendering operator=(const AquaticRendering&) = delete;
    AquaticRendering operator=(AquaticRendering&&) = delete;
};
