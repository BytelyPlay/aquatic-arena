module;
#include <vector>

module Model;

// PUBLIC
Model::Model(const std::vector<Mesh>& meshes) :
meshes(meshes) {}

// PUBLIC
const std::vector<Mesh>& Model::getMeshes() const
{
    return meshes;
}

// PRIVATE
