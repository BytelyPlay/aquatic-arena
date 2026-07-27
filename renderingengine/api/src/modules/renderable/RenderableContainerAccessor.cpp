module;

module RenderableContainerAccessor;

// PROTECTED
RenderableContainerAccessor::RenderableContainerAccessor()
= default;

// PUBLIC
// PUBLIC
// PUBLIC
RenderableSPtr RenderableContainerAccessor::operator[](
    int index
)
const
{
    return get(index);
}

// PUBLIC
