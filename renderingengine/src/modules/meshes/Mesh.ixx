module;
#include <memory>
#include <vector>

#include "../../../../libs/glfw/src/internal.h"

export module Mesh;
import VAO;
import VBO;
import EBO;
import Texture;
import Vecs;
import Logger;
import SimpleVAO;

export struct Mesh
{
    static const std::vector<SimpleVAO::TypeEntry> ENTRIES;

    struct Vertex
    {
        Vecs::Vec3b vertex;
        Vecs::Vec3b textureCoord;
    };
    Mesh(
        std::vector<Vertex> vertices,
        std::vector<unsigned int> indices
    );

    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

    std::unique_ptr<Texture> tex;

    /**
     * Draws the Mesh.
     * @return Successful or not
     */
    bool draw();
private:
    Logger& log = Logger::getInstance();
};
