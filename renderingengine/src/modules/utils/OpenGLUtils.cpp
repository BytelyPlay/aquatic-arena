module;
#include <glad/gl.h>

module OpenGLUtils;
import Logger;

unsigned int OpenGLUtils::getSizeOf(GLenum type)
{
    switch (type)
    {
    case GL_FLOAT: return 4;
    case GL_DOUBLE: return 8;

    case GL_SHORT: return 2;
    case GL_UNSIGNED_SHORT: return 2;

    case GL_INT: return 4;
    case GL_UNSIGNED_INT: return 4;

    default:
        {
            Logger::getInstance()
            .warn("OpenGLUtils#getSizeOf couldn't figure out OpenGL type.");
            return 0;
        }
    }
}