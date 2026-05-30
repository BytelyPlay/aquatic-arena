module;
#include "glad/gl.h"

export module EBO;

export class EBO
{
public:
    /**
     * Returns the EBO ID, will build if not built.
     * @return Returns 0 if not successful, otherwise the EBO ID
     */
    unsigned int getEBOId();
    unsigned int getIndiceCount();
    /**
     * This gives you the type used for the indices in this EBO.
     * @return The type used for the indices. GL_NONE if it isn't set...
     */
    GLenum getType();
protected:
    /**
     * Should build the EBO.
     * @param eboId The ID of the EBO.
     * @param indiceCount The amount of indices.
     * @param type The type used for indices.
     */
    virtual void build(unsigned int& eboId,
        unsigned int& indiceCount,
        GLenum& type) = 0;
private:
    void buildInternal();
private:
    /**
     * EBO ID from OpenGL.
     */
    unsigned int eboId = 0;
    unsigned int indiceCount = 0;

    /**
     * This is the type used for the indices. Defaults to GL_NONE.
     */
    GLenum type = GL_NONE;
    /**
     * If it was built or not, doesn't mean it was successful, just that we tried to build it.
     */
    bool built = false;
};
