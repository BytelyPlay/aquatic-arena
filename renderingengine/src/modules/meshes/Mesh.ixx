module;
#include <memory>

export module Mesh;
import VAO;
import VBO;
import EBO;
import Texture;

export struct Mesh
{
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

    std::unique_ptr<Texture> tex;

    /**
     * Draws the Mesh.
     * @return Successful or not
     */
    bool draw();
};
