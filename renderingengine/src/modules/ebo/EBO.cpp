module;
#include <glad/gl.h>

module EBO;

// PUBLIC
unsigned int EBO::getEBOId()
{
    buildInternal();
    return eboId;
}

unsigned int EBO::getIndiceCount()
{
    buildInternal();
    return indiceCount;
}

GLenum EBO::getType()
{
    buildInternal();
    return type;
}

// PROTECTED
// PRIVATE
void EBO::buildInternal()
{
    if (built) return;

    if (!build(eboId, indiceCount, type)) log.error("Couldn't build EBO.");
    built = true;
}

// PRIVATE
