module;
#include <vector>

export module SimpleVBO;
import VBO;

export class SimpleVBO : public VBO
{
public:
    SimpleVBO(std::vector<unsigned char> data);
    SimpleVBO(const void* ptr, const size_t& size);
protected:
    bool build(unsigned int& vboId) override;
private:
    std::vector<unsigned char> data;
};
