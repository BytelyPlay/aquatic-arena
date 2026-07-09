module;
#include <vector>

export module CompilableModel;
import CompilableMesh;

export class CompilableModel
{
public:
    CompilableModel(CompilableMesh meshes);
private:
    std::vector<CompilableMesh> meshes;
};
