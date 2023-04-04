#include "light.h"

Light::Light()
{

}

void Light::init(GLint matrixUniform)
{
    // Since the light requires a new VAO, we need to create a special override for the init function
    initializeOpenGLFunctions();

    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Light::draw()
{

}
