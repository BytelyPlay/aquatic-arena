module;
#include <utility>
#include <vector>
#include <glad/gl.h>

module SimpleEBO;

// PUBLIC
SimpleEBO::SimpleEBO(std::vector<unsigned int> indices) :
indices(std::move(indices)) {}

// PROTECTED
bool SimpleEBO::build(
    unsigned int& eboId,
    unsigned int& indiceCount,
    GLenum& type
)
{
    glGenBuffers(1, &eboId);

    if (!eboId)
    {
        log.error("Couldn't build EBO.");
        return false;
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboId);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        indices.size(), indices.data(),
        GL_STATIC_DRAW
    );
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    indiceCount = indices.size();
    return true;
}

// PRIVATE
