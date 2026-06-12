module;
#include <cstring>
#include <glad/gl.h>
#include <vector>

module SimpleVBO;

// PUBLIC
SimpleVBO::SimpleVBO(std::vector<unsigned char> data) :
data(data), VBO()
{}

SimpleVBO::SimpleVBO(const void* ptr, const size_t& size)
{
    data.resize(size);
    memcpy(data.data(), ptr, size);
}

// PROTECTED
bool SimpleVBO::build(unsigned int& vboId)
{
    glGenBuffers(1, &vboId);
    // A bit ugly, sort of like it is in the way, but I can't do much about that.
    if (vboId <= 0) return false;

    glBindBuffer(GL_ARRAY_BUFFER, vboId);

    glBufferData(
        GL_ARRAY_BUFFER, data.size(),
        data.data(), GL_STATIC_DRAW
    );
    return true;
}

// PRIVATE
