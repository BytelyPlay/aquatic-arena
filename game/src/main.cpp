#include <memory>

import AquaEngine;
import Logger;
import LoggerImpl;

int main()
{
    // just temporary
    Logger::setInstance(std::make_unique<LoggerImpl>());

    AquaEngine engine;
    // delme temp
    engine.init(600, 400, "a");
}
