module;
#include <glad/gl.h>

export module SimpleVAO;
import VAO;
import EBO;
import VBO;

export class SimpleVAO : public VAO
{
public:
    SimpleVAO(VBO& vbo, EBO& ebo);
public:
    bool build(unsigned int& id, GLenum& mode) override;
private:

};
