module;

module Model;

// PUBLIC
Model::Model(const std::vector<Mesh>& meshes) :
meshes(meshes) {}

// PUBLIC
const std::vector<Mesh>& Model::getMeshes()
{
    return meshes;
}

// PRIVATE
