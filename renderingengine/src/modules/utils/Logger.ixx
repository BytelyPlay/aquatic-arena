module;
#include <memory>

export module Logger;

/**
 * This logger should be implemented by the user of the library. Call setInstance and set the instance.
 */
export class Logger
{
public:
    static void setInstance(std::unique_ptr<Logger> loggerInstance);
    static Logger& getInstance();
public:
    virtual void debug(std::string s) = 0;

    virtual void info(std::string s) = 0;
    virtual void warn(std::string s) = 0;
    virtual void error(std::string s) = 0;
private:
    static std::unique_ptr<Logger> logger;
};