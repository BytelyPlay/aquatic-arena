module;
#include "glad/gl.h"

export module VAO;

export class VAO
{
public:
    /**
     * Returns the VAO ID, will build if not built.
     * @return Returns 0 if not successful, otherwise the VAO ID
     */
    unsigned int getVAOId();
    /**
     * Returns the mode to render in.
     * @return The mode (GL_LINES, GL_TRIANGLES, etc) to render in.
       GL_NONE if we couldn't build.
     */
    GLenum getMode();
protected:
    /**
     * Should build the VAO, it is expected that you will need the
     * VBO and (maybe) EBO, that should be the job of the subclass.
     * @param id The ID of the VAO.
     * @param mode The mode to render in.
     */
    virtual void build(unsigned int& id, GLenum& mode) = 0;
private:
    void buildInternal();
private:
    /**
     * VAO ID from OpenGL.
     */
    unsigned int vaoId = 0;
    /**
     * This is the mode to render (GL_TRIANGLES, GL_LINES, etc)
     * Defaults to GL_NONE
     */
    GLenum mode = GL_NONE;
    /**
     * If it was built or not, doesn't mean it was successful, just that we tried to build it.
     */
    bool built = false;
};
