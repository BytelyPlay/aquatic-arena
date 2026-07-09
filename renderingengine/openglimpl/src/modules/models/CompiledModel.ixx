module;
#include <vector>

export module CompiledModel;
import CompiledMesh;

export class CompiledModel
{
public:
    CompiledModel(CompiledMesh meshes);
private:
    std::vector<CompiledMesh> meshes;
};
