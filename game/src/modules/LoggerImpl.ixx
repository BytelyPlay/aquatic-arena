module;
#include <string>

export module LoggerImpl;
import Logger;

export class LoggerImpl : public Logger
{
public:
    void debug(std::string s);

    void info(std::string s);
    void warn(std::string s);
    void error(std::string s);
};