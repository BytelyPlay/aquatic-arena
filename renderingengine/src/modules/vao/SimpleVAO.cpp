module;
#include <glad/gl.h>
#include <vector>
import OpenGLUtils;

module SimpleVAO;

// PUBLIC
SimpleVAO::SimpleVAO(VBO& vbo, std::vector<TypeEntry> types) :
vbo(vbo), types(types), VAO()
{}

// PROTECTED
bool SimpleVAO::build(unsigned int& vaoId, GLenum& mode)
{
    glGenVertexArrays(1, &vaoId);

    if (vaoId <= 0)
    {
        log.error("Couldn't create VAO.");
        return false;
    }
    glBindVertexArray(vaoId);
    glBindBuffer(GL_ARRAY_BUFFER, vbo.getVBOId());

    fillVertexAttributes();

    return true;
}
// PRIVATE
bool SimpleVAO::fillVertexAttributes()
{
    unsigned int offset = 0;

    for (int i = 0; i < types.size(); i++)
    {
        TypeEntry& entry = types[i];

        unsigned int sizeOfType = OpenGLUtils::getSizeOf(entry.type);
        unsigned int sizeOfEntry = sizeOfType * entry.size;

        if (sizeOfEntry == 0) {
            log.error("Couldn't calculate size of entry for VAO.");
            return false;
        }

        glVertexAttribPointer(
            i, entry.size, entry.type,
            GL_FALSE, sizeOfType * entry.size,
            reinterpret_cast<void*>(offset)
        );
        offset += sizeOfEntry;

        glEnableVertexAttribArray(i);
    }
    return true;
}

// PRIVATE
