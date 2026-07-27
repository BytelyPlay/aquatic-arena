module;

export module RenderableSnapshot;
import Vecs;
import Model;

export struct RenderableSnapshot
{
    Vecs::Vec3f position, scale;
    Vecs::Vec4f rotQuaternion;

    const Model& model;
};