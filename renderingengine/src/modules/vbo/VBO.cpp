module;

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

// PROTECTED
// PRIVATE
// PUBLIC
VBO::~VBO()
= default;

// PUBLIC
