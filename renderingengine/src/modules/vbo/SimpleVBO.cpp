module;
#include <glad/gl.h>
#include <vector>

module SimpleVBO;

// PUBLIC
SimpleVBO::SimpleVBO(std::vector<int> vertices) : VBO()
{
}

// PROTECTED
bool SimpleVBO::build(unsigned int& vboId)
{
    glGenBuffers(1, &vboId);
    // A bit ugly, sort of like it is in the way, but I can't do much about that.
    if (vboId <= 0) return false;

    glBindBuffer(GL_ARRAY_BUFFER, vboId);

    glBufferData(
        GL_ARRAY_BUFFER, vertices.size(),
        vertices.data(), GL_STATIC_DRAW
    );
    return true;
}

// PRIVATE
