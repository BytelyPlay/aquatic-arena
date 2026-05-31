module;
#include <string>
#include <vector>

export module Texture;
import Logger;

constexpr int DESIRED_AMOUNT_OF_CHANNELS = 4;

export class Texture
{
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
     * Compiles the texture.
     * @return Successful or not
     */
    bool build();
private:
    /**
     * I really didn't have any idea what to call this. Basically you give it the compressed file format's bytes, and it converts it into raw pixels.
     */
    bool turnCompressedToRawPixels(std::vector<unsigned char> bytes);
private:
    unsigned int textureId = 0;
    /**
     * This is ready for OpenGL to use.
     */
    std::vector<unsigned char> textureBytes;
private:
    Logger& log = Logger::getInstance();
};