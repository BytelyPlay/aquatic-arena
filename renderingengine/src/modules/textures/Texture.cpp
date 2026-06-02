module;
#include <cstring>
#include <fstream>
#include <utility>
#include <stb_image.h>
#include <glad/gl.h>

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

    if (!successful) log.error("Couldn't read texture from disk.");

    if (successful) successful = turnCompressedToRawPixels(bytes);

    if (!successful) log.error(
        "Couldn't convert compressed image data to raw pixels."
    );
}

// PUBLIC
bool Texture::use()
{
    if (textureId <= 0) return false;

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId);

    return true;
}

// PUBLIC
unsigned int Texture::getTextureID()
{
    buildInternal();
    return textureId;
}

// PRIVATE
void Texture::buildInternal()
{
    if (built) return;
    if (!build(texWidth, texHeight))
        log.error("Couldn't build texture.");
    built = true;
}

bool Texture::build(int texWidth, int texHeight)
{
    glGenTextures(1, textureId);

    if (textureId <= 0)
    {
        log.warn("Couldn't build texture.")
        return false;
    }
    glBindTexture(GL_TEXTURE_2D, textureId);

    setPropertiesForTexture();

    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGBA,
        texWidth, texHeight, 0,
        GL_UNSIGNED_BYTE, textureBytes
    );
    glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture::setPropertiesForTexture()
{
    glTexParameteri(
    GL_TEXTURE_2D,
    GL_TEXTURE_WRAP_S,
    TEXTURE_WRAPPING_BEHAVIOR
);
    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_WRAP_T,
        TEXTURE_WRAPPING_BEHAVIOR
     );

    glTexParameteri(
        GL_TEXTURE_2D,
        // higher resolution texture, lower resolution monitor
        GL_TEXTURE_MIN_FILTER,
        GL_NEAREST
    );
    glTexParameteri(
        GL_TEXTURE_2D,
        // lower resolution texture, higher resolution monitor
        GL_TEXTURE_MAG_FILTER,
        GL_NEAREST
    );

    glTexParameteri(
        GL_TEXTURE_2D,
        // higher resolution texture, lower resolution monitor
        GL_TEXTURE_MIN_FILTER,
        MIPMAP_BEHAVIOR
    );
    glTexParameteri(
        GL_TEXTURE_2D,
        // lower resolution texture, higher resolution monitor
        GL_TEXTURE_MAG_FILTER,
        MIPMAP_BEHAVIOR
    );
}

// PRIVATE
bool Texture::turnCompressedToRawPixels(std::vector<unsigned char> bytes)
{
    int channels, size;

    auto* rawPixels = stbi_load_from_memory(
        bytes.data(), bytes.size(),
        &texWidth, &texHeight,
        &channels, DESIRED_AMOUNT_OF_CHANNELS
    );
    size = texWidth * texHeight * DESIRED_AMOUNT_OF_CHANNELS;

    if (rawPixels == nullptr)
    {
        log.error("Couldn't get raw pixel array from texture.");
        return false;
    }
    textureBytes.resize(size);
    memcpy(textureBytes.data(), rawPixels, size);
    stbi_image_free(rawPixels);

    return true;
}

// PRIVATE
// PRIVATE