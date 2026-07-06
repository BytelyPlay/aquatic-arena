module;

module RenderableAccessor;

// PROTECTED
RenderableAccessor::RenderableAccessor()
= default;

// PUBLIC
// PUBLIC
// PUBLIC
RenderableSPtr RenderableAccessor::operator[](
    int index
)
const
{
    return get(index);
}

// PUBLIC
