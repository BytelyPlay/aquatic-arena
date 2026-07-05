module;

export module RenderableSnapshot;
import Vecs;

export struct RenderableSnapshot
{
    Vecs::Vec3f position, scale;
    Vecs::Vec4f rotQuaternion;
};