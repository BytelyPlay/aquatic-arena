module;

module VBO;

// PUBLIC
unsigned int VBO::getVBOId()
{
    if (built) return vboId;

    build(vboId, size);
    built = true;

    return vboId;
}

// PROTECTED
// PRIVATE
