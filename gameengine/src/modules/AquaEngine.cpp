module;
#include <string>

module AquaEngine;
import AquaticRendering;
import Vecs;

// PUBLIC
bool AquaEngine::init(int width, int height, std::string title)
{
    if (!rendering.init(width, height, title))
        return false;
    // Still gotta do stuff here...
    return true;
}
