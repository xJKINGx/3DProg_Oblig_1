#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLFunctions_4_1_Core>

//#include "GL/glew.h" //We use QOpenGLFunctions instead, so no need for Glew (or GLAD)!

//This class is pretty much a copy of the shader class at
//https://github.com/SonarSystems/Modern-OpenGL-Tutorials/blob/master/%5BLIGHTING%5D/%5B8%5D%20Basic%20Lighting/Shader.h
//which is based on stuff from http://learnopengl.com/ and http://open.gl/.

//must inherit from QOpenGLFunctions_4_1_Core, since we use that instead of glfw/glew/glad
class Shader : protected QOpenGLFunctions_4_1_Core
{
public:
    // Constructor generates the shader on the fly
    Shader(const GLchar *vertexPath, const GLchar *fragmentPath);

    ///Use the current shader
    void use( );

    ///Returns the program number for this shader
    GLuint getProgram() const;

    // Each shader gets its own MatrixUniforms (MUs), this way we can avoid having a million different
    // MUs in renderwindow.h.
    // If we need new and unique uniforms, we'll add them to renderwindow.h
    GLint MMU{-1}; // mMatrixUniform
    GLint PMU{-1}; // pMatrixUniform
    GLint VMU{-1}; // vMatrixUniform

private:
    ///The int OpenGL gives as a reference to this shader
    GLuint mProgram;

    ///The logger - Output Log in the application
    class Logger *mLogger{nullptr};
};

#endif
