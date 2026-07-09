module;
#include <vector>

export module CompiledModel;
import CompiledMesh;
import Model;

export class CompiledModel : public Model
{
public:
    CompiledModel(const std::vector<CompiledMesh>& meshes);
public:
    const std::vector<CompiledMesh>& getMeshes();
private:
    std::vector<CompiledMesh> meshes;
};
