module;
#include <glad/gl.h>

module VAO;

// PUBLIC
VAO::VAO()
= default;

// PUBLIC
unsigned int VAO::getVAOId()
{
    buildInternal();
    return vaoId;
}

GLenum VAO::getMode()
{
    buildInternal();
    return mode;
}
// PUBLIC
bool VAO::use()
{
    auto id = getVAOId();
    if (id <= 0) return false;

    glBindVertexArray(id);
    
    return true;
}

// PROTECTED
// PRIVATE
void VAO::buildInternal()
{
    if (built) return;

    if (!build(vaoId, mode)) log.error("Couldn't build VAO");
    built = true;
}

// PRIVATE
// PUBLIC
VAO::~VAO()
{
    glDeleteVertexArrays(1, &vaoId);
    vaoId = 0;
}

// PUBLIC
