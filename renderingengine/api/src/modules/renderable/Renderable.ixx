module;

export module Renderable;
import Vecs;
import Model;

export class Renderable
{
public:
    virtual void setPosition(Vecs::Vec3f pos) = 0;
    virtual Vecs::Vec3f getPosition() const = 0;

    virtual void setScale(Vecs::Vec3f scale) = 0;
    virtual Vecs::Vec3f getScale() const = 0;

    virtual void setRotQuaternion(Vecs::Vec4f quat) = 0;
    virtual Vecs::Vec4f getRotQuaternion() const = 0;

    virtual void setModel(const Model&) = 0;
    virtual const Model& getModel() const = 0;
public:
    virtual ~Renderable() = default;
public:
    Renderable(const Renderable&) = delete;
    Renderable(Renderable&&) = delete;

    Renderable& operator=(const Renderable&) = delete;
    Renderable& operator=(Renderable&&) = delete;
};