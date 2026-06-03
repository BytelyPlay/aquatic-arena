module;
#include <glad/gl.h>
#include <string>

module Shader;

// PUBLIC
Shader::Shader(std::string shader, GLenum type) :
shader(shader),
type(type)
{}

// PUBLIC
bool Shader::use()
{
    buildInternal();
    if (shaderId <= 0) return false;
    glUseProgram(shaderId);

    return true;
}
// PRIVATE
void Shader::buildInternal()
{
    if (built) return;
    if (!build()) log.warn("Couldn't compile shader.");
}

bool Shader::build()
{
    shaderId = glCreateShader(type);

    if (shaderId <= 0)
    {
        log.error("Couldn't compile shader.");
        return false;
    }

    glShaderSource(
        shaderId,
        1,
        reinterpret_cast<const GLchar* const*>(
            shader.c_str()
        ),
        nullptr
    );
    glCompileShader(shaderId);

    return checkIfSuccessful();
}

bool Shader::checkIfSuccessful()
{
    int compileStatus;

    glGetShaderiv(
        shaderId,
        GL_COMPILE_STATUS,
        &compileStatus
    );
    if (!compileStatus)
    {
        handleError();
        return false;
    }
    return true;
}

void Shader::handleError()
{
    int infoLogLength;
    std::string infoLog;

    glGetShaderiv(
        shaderId,
        GL_INFO_LOG_LENGTH,
        &infoLogLength
    );
    infoLog.resize(infoLogLength - 1);

    glGetShaderInfoLog(
        shaderId,
        infoLogLength,
        nullptr,
        infoLog.data()
    );
    log.error("Couldn't compile Shader, error: " + infoLog);
}

// PRIVATE
