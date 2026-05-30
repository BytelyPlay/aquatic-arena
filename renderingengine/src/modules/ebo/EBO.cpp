module;

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

    build(eboId, indiceCount, type);
    built = true;
}

// PRIVATE
