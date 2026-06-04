module;
#include <glad/gl.h>

module VBO;

// PUBLIC
VBO::VBO()
= default;

// PUBLIC
unsigned int VBO::getVBOId()
{
    if (built) return vboId;

    if (!build(vboId)) log.error("Couldn't build VBO.");
    built = true;

    return vboId;
}

bool VBO::bind()
{
    unsigned int id = getVBOId();
    if (id <= 0)
    {
        log.error("Couldn't bind VBO.");
        return false;
    }
    glBindBuffer(GL_ARRAY_BUFFER, id);

    return true;
}

// PROTECTED
// PRIVATE
// PUBLIC
VBO::~VBO()
= default;

// PUBLIC
