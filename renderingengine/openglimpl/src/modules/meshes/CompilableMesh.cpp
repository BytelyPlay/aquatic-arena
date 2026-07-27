module;
#include <glad/gl.h>
#include <memory>
#include <vector>

module CompilableMesh;
import Logger;
import SimpleVAO;
import SimpleVBO;
import Vecs;
import SimpleEBO;

const std::vector<SimpleVAO::TypeEntry> CompilableMesh::ENTRIES = {
    {GL_UNSIGNED_BYTE, 3}, // Vertices
    {GL_UNSIGNED_BYTE, 3} // Texture coordinates
};

CompilableMesh::CompilableMesh(
    std::vector<Vertex> vertices,
    std::vector<unsigned int> indices
) : Mesh(vertices, indices)
{
    vbo = std::make_unique<SimpleVBO>(
        vertices.data(),
        vertices.size() * sizeof(Vecs::Vec3b)
    );
    vao = std::make_unique<SimpleVAO>(*vbo, ENTRIES);
    ebo = std::make_unique<SimpleEBO>(indices);
}

bool CompilableMesh::draw() const
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
