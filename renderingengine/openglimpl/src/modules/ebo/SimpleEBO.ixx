module;
#include <vector>
#include <glad/gl.h>

export module SimpleEBO;
import EBO;

export class SimpleEBO : public EBO
{
public:
    SimpleEBO(std::vector<unsigned int> indices);
protected:
    bool build(
        unsigned int& eboId,
        unsigned int& indiceCount,
        GLenum& type
    )
    override;
private:
    const std::vector<unsigned int> indices;
};
