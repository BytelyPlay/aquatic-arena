module;
#include "glad/gl.h"

export module OpenGLUtils;

export namespace OpenGLUtils
{
    /**
     * Basically sizeof(type) but with OpenGL types.
     * @param type The OpenGL Type
     *
     * @return The size
     */
    unsigned int getSizeOf(GLenum type);
}
