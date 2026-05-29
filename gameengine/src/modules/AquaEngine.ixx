module;
#include <string>

export module AquaEngine;
import AquaticRendering;

export class AquaEngine
{
public:
    bool init(int width, int height, std::string title);
private:
    AquaticRendering rendering;
};
