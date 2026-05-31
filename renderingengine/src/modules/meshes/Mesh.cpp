module;
#include <glad/gl.h>

module Mesh;
import Logger;

bool Mesh::draw()
{
    unsigned int vaoId = vao->getVAOId();
    unsigned int eboId = ebo->getEBOId();
    unsigned int texId = tex->getTextureID();

    if (vaoId <= 0 || eboId <= 0 || texId <= 0)
    {
        // One of the only times I use getInstance outside of a field.
        // simply because this is a struct and there are no private fields.
        Logger::getInstance().warn("Couldn't compile VAO and EBO...");
        return false;
    };
    tex->use();

    glBindVertexArray(vaoId);
    glDrawElements(
        vao->getMode(),
        ebo->getIndiceCount(),
        ebo->getType(),
        reinterpret_cast<void*>(0)
    );
    return true;
}
