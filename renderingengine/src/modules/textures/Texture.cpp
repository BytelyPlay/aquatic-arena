module;
#include <cstring>
#include <fstream>
#include <utility>
#include <stb_image.h>

module Texture;
import FileUtils;

// PUBLIC
Texture::Texture(std::vector<unsigned char> bytes, bool rawPixels, bool& successful)
{
    if (rawPixels)
    {
        textureBytes = bytes;
        successful = true;
        return;
    } else
    {
        successful = turnCompressedToRawPixels(bytes);
    }
}

Texture::Texture(const std::string& path, bool& successful)
{
    std::vector<unsigned char> bytes;

    successful =
        FileUtils::readFullFile(path, bytes);
    this(bytes, false);
}

// PUBLIC
bool Texture::use()
{

}

// PUBLIC
unsigned int Texture::getTextureID()
{

}

// PRIVATE
bool Texture::build()
{
    
}

// PRIVATE
bool Texture::turnCompressedToRawPixels(std::vector<unsigned char> bytes)
{
    int width, height, channels, size;

    auto* rawPixels = stbi_load_from_memory(
        bytes.data(), bytes.size(),
        &width, &height,
        &channels, DESIRED_AMOUNT_OF_CHANNELS
    );
    size = width * height * DESIRED_AMOUNT_OF_CHANNELS;

    if (rawPixels == nullptr)
    {
        log.error("Couldn't get raw pixel array from texture.");
        return false;
    }
    textureBytes.resize(size);
    memcpy(textureBytes.data(), rawPixels, size);

    return true;
}

// PRIVATE
// PRIVATE