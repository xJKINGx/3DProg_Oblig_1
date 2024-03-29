#include "texture.h"
#include <iostream>

#include "logger.h"

Texture::Texture()
{
    initializeOpenGLFunctions();
    textureID = 0;
    width = 0;
    height = 0;
    bitDepth = 0;
    fileLocation = nullptr;
}

Texture::Texture(char* filePath)
{
    initializeOpenGLFunctions();
    textureID = 0;
    width = 0;
    height = 0;
    bitDepth = 0;
    fileLocation = filePath;
}

Texture::~Texture()
{
    ClearTexture();
}

void Texture::ClearTexture()
{
    glDeleteTextures(1, &textureID);
    textureID = 0;
    width = 0;
    height = 0;
    bitDepth = 0;
    fileLocation = nullptr;
}

void Texture::LoadTexture()
{
    initializeOpenGLFunctions();
    mLogger = Logger::getInstance();
    unsigned char* texData = stbi_load(fileLocation, &width, &height, &bitDepth, 0);
    std::cout << fileLocation << std::endl;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // S and T are also known as U and V, another name being X and Y
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    //glBindTexture(GL_TEXTURE_2D, 0); // we unbind the texture

    if (texData) // If the texture data we provided is valid...
    {
        // ... then load the texture...
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);
        glGenerateMipmap(GL_TEXTURE_2D);
        mLogger->logText("Texture file " + std::string(fileLocation) + " was successfully read.", LogType::LOG);
    }
    else
    {
        // ... otherwise something went wrong and we need to report it.
        std::cout << "AHHH THE TEXTURE FILE IS FUCKED" << std::endl;
        mLogger->logText("ERROR - Could not load texture in given filepath: " + std::string(fileLocation), LogType::REALERROR);
    }
    stbi_image_free(texData);
}

void Texture::UseTexture()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
}
