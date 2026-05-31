module;
#include <vector>

export module SimpleVBO;
import VBO;

export class SimpleVBO : public VBO
{
public:
    SimpleVBO(std::vector<int> vertices);
protected:
    bool build(unsigned int& vboId) override;
private:
    std::vector<int> vertices;
};
