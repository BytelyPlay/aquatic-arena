module;

export module Renderable;
import Vecs;

export class Renderable
{
public:
    virtual void setPosition(Vecs::Vec3f pos) = 0;
    virtual Vecs::Vec3f getPosition() = 0;

    virtual void setScale(Vecs::Vec3f scale) = 0;
    virtual Vecs::Vec3f getScale() = 0;

    virtual void setRotQuaternion(Vecs::Vec4f quat) = 0;
    virtual Vecs::Vec4f getRotQuaternion() = 0;
public:
    Renderable(const Renderable&) = delete;
    Renderable(Renderable&&) = delete;

    Renderable& operator=(const Renderable&) = delete;
    Renderable& operator=(Renderable&&) = delete;
};