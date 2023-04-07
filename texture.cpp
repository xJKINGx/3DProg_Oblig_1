#include "texture.h"
#include <iostream>

Texture::Texture()
{
    textureID = 0;
    width = 0;
    height = 0;
    bitDepth = 0;
    fileLocation = " ";
}

Texture::Texture(char* filePath)
{
    textureID = 0;
    width = 0;
    height = 0;
    bitDepth = 0;
    fileLocation = filePath;
}

Texture::~Texture()
{

}

void Texture::ClearTexture()
{
    glDeleteTextures(1, &textureID);
    textureID = 0;
    width = 0;
    height = 0;
    bitDepth = 0;
    fileLocation = " ";
}

void Texture::LoadTexture()
{
    initializeOpenGLFunctions();
    unsigned char* texData = stbi_load(fileLocation, &width, &height, &bitDepth, 0);
    std::cout << fileLocation << std::endl;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // S and T are also known as U and V, another name being X and Y
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (texData) // If the texture data we provided is valid...
    {
        // ... then load the texture...
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        // ... otherwise something went wrong and we need to report it.

    }
}

void Texture::UseTexture()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
}
