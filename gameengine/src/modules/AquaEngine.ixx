module;
#include <string>
#include <memory>

export module AquaEngine;
import AquaticRendering;
import OpenGLRenderingEngine;

using AquaticRenderingImpl = OpenGLRenderingEngine;

export class AquaEngine
{
public:
    AquaEngine();
public:
    bool init(
        const uint& width, const uint& height,
        const std::string& title
    );
private:
    std::shared_ptr<AquaticRendering> rendering;
};
