module;
#include <vector>

export module Model;
import Mesh;

export class Model
{
public:
    Model(Mesh meshes);
private:
    std::vector<Mesh> meshes;
};
