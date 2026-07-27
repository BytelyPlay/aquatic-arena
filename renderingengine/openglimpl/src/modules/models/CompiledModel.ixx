module;
#include <vector>

export module CompilableModel;
import CompilableMesh;
import Model;

export class CompilableModel : public Model
{
public:
    CompilableModel(const std::vector<CompilableMesh>& meshes);
public:
    const std::vector<CompilableMesh>& getMeshes();
public:
    void draw() override;
private:
    std::vector<CompilableMesh> meshes;
};
