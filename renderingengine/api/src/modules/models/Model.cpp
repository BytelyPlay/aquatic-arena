module;
#include <vector>
#include <memory>

module Model;

// PROTECTED
Model::Model(const std::vector<std::shared_ptr<Mesh>>& meshes) :
meshes(meshes) {}

// PUBLIC
const MeshVector& Model::getMeshes() const
{
    return meshes;
}

// PRIVATE
