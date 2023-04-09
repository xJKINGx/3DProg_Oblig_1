#include "light.h"

Light::Light()
{

}

Light::Light(GLfloat r, GLfloat g, GLfloat b, GLfloat intensity)
{

}


Light::Light(GLfloat r, GLfloat g, GLfloat b, GLfloat intensity, GLfloat xDir, GLfloat yDir, GLfloat zDir, GLfloat dIntensity)
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
//    glBindVertexArray( mVAO );
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
//    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
}

Light::~Light()
{

}
