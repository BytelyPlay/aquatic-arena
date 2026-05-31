module;
#include <glad/gl.h>

module VAO;

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
// PROTECTED
// PRIVATE
void VAO::buildInternal()
{
    if (built) return;

    if (!build(vaoId, mode)) log.error("Couldn't build VAO");
    built = true;
}

// PRIVATE
