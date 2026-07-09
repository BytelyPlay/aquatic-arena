module;
#include <vector>

export module Model;
import Mesh;

export class Model
{
public:
    Model(const std::vector<Mesh>& meshes);
public:
    const std::vector<Mesh>& getMeshes() const;
private:
    std::vector<Mesh> meshes;
};