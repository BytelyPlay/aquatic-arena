module;
#include <vector>
#include <memory>

export module Model;
import Mesh;

using MeshPtr = std::shared_ptr<Mesh>;
using MeshVector = std::vector<MeshPtr>;

// TODO: Some kind of Model creator from meshes that is implemented by the underlying engine.
export class Model
{
protected:
    Model(
        const MeshVector& meshes
    );
public:
    [[nodiscard]]
    virtual const MeshVector&
        getMeshes() const = 0;
public:
    virtual void draw();
private:
    MeshVector meshes;
public:
    virtual ~Model() = default;
};