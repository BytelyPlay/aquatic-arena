module;

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

    build(vaoId, mode);
    built = true;
}

// PRIVATE
