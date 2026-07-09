module;
#include <cstdint>
#include <vector>

export module Mesh;
import Vecs;

export class Mesh
{
public:
    /**
     * One vertex
     */
    struct Vertex
    {
        Vecs::Vec3f position;
        Vecs::Vec3f texCoord;
    };
protected:
    /**
     * Construct a mesh
     * @param vertices The vertices (data to be used rendered, but indices decide the order)
     * @param indices The indices (basically reference vertices)
     */
    Mesh(
        std::vector<Vertex> vertices,
        std::vector<uint32_t> indices
    );
};
