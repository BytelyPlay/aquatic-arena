module;
#include <iostream>

module LoggerImpl;

// PUBLIC
void LoggerImpl::debug(std::string s)
{
    std::cout << "[DEBUG] " << s << "\n";
}
void LoggerImpl::info(std::string s)
{
    std::cout << "[INFO] " << s << "\n";
}
void LoggerImpl::warn(std::string s)
{
    std::cout << "[WARN] " << s << "\n";
}
void LoggerImpl::error(std::string s)
{
    std::cout << "[ERROR] " << s << "\n";
}
