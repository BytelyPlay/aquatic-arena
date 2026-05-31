module;
#include <fstream>

module FileUtils;

bool FileUtils::readFullFile(
    const std::string& path,
    std::vector<unsigned char>& bytes
)
{
    std::ifstream in;
    in.open(path, std::ios::binary);

    if (!in.good())
    {
        return false;
    }

    in.seekg(std::ifstream::end);
    size_t end = in.tellg();
    in.seekg(std::ifstream::beg);

    bytes.resize(end);
    in.read(
        reinterpret_cast
        <std::istream::char_type*>
        (bytes.data()), end
    );

    return true;
}
