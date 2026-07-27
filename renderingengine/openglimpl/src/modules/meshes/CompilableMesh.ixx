module;
#include <memory>
#include <vector>

export module CompilableMesh;
import VAO;
import VBO;
import EBO;
import Texture;
import Vecs;
import Logger;
import SimpleVAO;
import Vertex;
import Mesh;

export class CompilableMesh : public Mesh
{
private:
    static const std::vector<SimpleVAO::TypeEntry> ENTRIES;
public:
    CompilableMesh(
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
    bool draw() const;
private:
    Logger& log = Logger::getInstance();
};
