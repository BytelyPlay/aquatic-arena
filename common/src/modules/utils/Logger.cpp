module;
#include <memory>

module Logger;

// PUBLIC
void Logger::setInstance(std::unique_ptr<Logger> loggerInstance)
{
    logger = std::move(loggerInstance);
}

Logger& Logger::getInstance()
{
    return *logger;
}

// PUBLIC
// PRIVATE
std::unique_ptr<Logger> Logger::logger = nullptr;