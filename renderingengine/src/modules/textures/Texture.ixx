module;
#include <string>
#include <vector>
#include <glad/gl.h>

export module Texture;
import Logger;

export class Texture
{
private:
    static constexpr GLenum TEXTURE_WRAPPING_BEHAVIOR = GL_REPEAT;
    static constexpr GLenum MIPMAP_BEHAVIOR = GL_LINEAR_MIPMAP_LINEAR;

    static constexpr int DESIRED_AMOUNT_OF_CHANNELS = 4;
public:
    /**
     * Use a byte array to load a texture.
     * @param bytes The "image"
     * @param rawPixels Is it just pixels?
       (can I just give this to OpenGL directly?)
     * @param successful If it is successful or not, but this only tells you if I could turn it into raw pixels.
     */
    Texture(std::vector<unsigned char> bytes, bool rawPixels, bool& successful);
    /**
     * This should lead to a texture.
     * @param path Path to texture.
     * @param successful If it is successful or not, but this only tells you if I could read and turn it into raw pixels.
     */
    Texture(const std::string& path, bool& successful);
public:
    /**
     * Sets the texture as Texture 0
     * @return Successful or not.
     */
    bool use();
public:
    /**
     * Get the texture ID.
     * @return Returns the texture ID or 0 if it failed to build.
     */
    unsigned int getTextureID();
private:
    /**
     * This builds the texture, if it isn't already built, and also then marks it as built.
     */
    void buildInternal();
    /**
     * Compiles the texture.
     * @return Successful or not
     */
    bool build(int texWidth, int texHeight);

    /**
     * Sets all the parameters for the bound texture.
     */
    void setPropertiesForTexture();
private:
    /**
     * I really didn't have any idea what to call this. Basically you give it the compressed file format's bytes, and it converts it into raw pixels.
     * @return successful or not.
     */
    bool turnCompressedToRawPixels(std::vector<unsigned char> bytes);
private:
    /**
     * If the texture is compiled/built, this doesn't mean that it is successful, just that it was built.
     */
    bool built = false;
    /**
     * The texture ID from OpenGL, defaults to 0.
     */
    unsigned int textureId = 0;
    /**
     * This is ready for OpenGL to use.
     */
    std::vector<unsigned char> textureBytes;
    /**
     * Texture width and height
     */
    int texWidth = 0, texHeight = 0;
private:
    Logger& log = Logger::getInstance();
};