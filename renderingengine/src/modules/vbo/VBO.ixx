module;
#include <stdexcept>

export module VBO;

export class VBO
{
public:
    /**
     * Get the VBO id, builds if it isn't yet built.
     * @return Returns 0 if we can't get the ID
     */
    unsigned int getVBOId();
protected:
    /**
     * Builds the VBO
     * @return Successful or not
     */
    virtual bool build(unsigned int& id, unsigned int& size) = 0;
private:
    /**
     * The VBO ID from OpenGL.
     */
    unsigned int vboId = 0;
    unsigned int size = 0;
    /**
     * If the VBO was built.
     * Doesn't mean it was successful,
     * it's just so that we don't repeatedly compile it after it fails...
     */
    bool built = false;
};