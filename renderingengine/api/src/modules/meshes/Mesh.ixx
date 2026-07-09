module;
#include <cstdint>
#include <vector>

export module Mesh;
import Vecs;
import Vertex;

/* TODO: Some kind of Mesh creator from vertices and indices
 * that is implemented by the underlying engine.
 */
export class Mesh
{
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