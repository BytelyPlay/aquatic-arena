module;
#include <memory>
#include <vector>

export module RenderableAccessor;
import Renderable;
import RenderableSnapshot;

// Renderable Smart Pointer
using RenderableSPtr = std::shared_ptr<Renderable>;

// TODO: Replace this whole temporary system with a resource id-like system.

/**
 * A thread-safe accessor for a list of renderable objects.
 *
 * This project only uses it as a read-only accessor,
 * so the things that aren't marked as const don't have to be implemented.
 *
 * All functions must be thread-safe.
 */
export class RenderableAccessor
{
protected:
    RenderableAccessor();
public:
    // Basic "operations" that aren't read-only like add or remove.
    virtual void add(RenderableSPtr renderable)
    = 0;
    virtual void remove(RenderableSPtr renderable)
    = 0;
public:
    // Basic "operations" that are read-only (get by index for example).

    /**
     * Get the renderable using its index.
     * @param index The index
     * @return The smart pointer to the Renderable, or nullptr if the index doesn't exist.
     */
    [[nodiscard]]
    virtual RenderableSPtr get(int index)
    const = 0;

    /**
     * Get how many elements are in the container.
     * @return Size of container
     */
    [[nodiscard]]
    virtual size_t size()
    const = 0;

    /**
     * Get a snapshot of the container.
     * @return Snapshot of the container
     */
    [[nodiscard]]
    virtual std::vector<RenderableSnapshot> getContainerSnapshot()
    const = 0;
public:
    // Operators

    /**
     * Gets a renderable.
     * @return The smart pointer to the Renderable, or nullptr if the index doesn't exist.
     */
    virtual RenderableSPtr operator[](int index)
    const;
public:
    RenderableAccessor(const RenderableAccessor&)
    = delete;
    RenderableAccessor(RenderableAccessor&&)
    = delete;

    RenderableAccessor& operator=(const RenderableAccessor&)
    = delete;
    RenderableAccessor& operator=(RenderableAccessor&&)
    = delete;
};