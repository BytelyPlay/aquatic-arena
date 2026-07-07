module;
#include <string>

#include "glad/gl.h"

export module Shader;
import Logger;

export class Shader
{
public:
    /**
     * Saves the shader string, to be used for lazy loading later.
     * @param shader The Shader code.
     * @param type The type of shader.
     */
    Shader(std::string shader, GLenum type);
public:
    /**
     * Enables the shader.
     * @return Successful or not
     */
    bool use();
private:
    void buildInternal();
    /**
     * Compiles the Shader.
     * @return Successful or not
     */
    bool build();
    bool checkIfSuccessful();
    void handleError();
private:
    /**
     * Whether it was built or not, it doesn't mean it was successful.
     */
    bool built = false;
    unsigned int shaderId = 0;

    std::string shader;
    /**
     * The type of shader.
     */
    GLenum type;

    Logger& log = Logger::getInstance();
};
