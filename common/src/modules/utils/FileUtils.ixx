module;
#include <string>
#include <vector>

export module FileUtils;

export namespace FileUtils
{
    bool readFullFile(const std::string& path, std::vector<unsigned char>& bytes);
};