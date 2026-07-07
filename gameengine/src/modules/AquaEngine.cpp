module;
#include <string>
#include <memory>

module AquaEngine;
import AquaticRendering;
import Vecs;

// PUBLIC
AquaEngine::AquaEngine()
: rendering(std::make_shared<AquaticRenderingImpl>())
{

}

// PUBLIC
bool AquaEngine::init(
    const uint& width, const uint& height,
    const std::string& title
)
{
    // TODO: Actually make it work.
    if (!rendering->init(nullptr, width, height, title))
        return false;
    return true;
}
// PRIVATE
