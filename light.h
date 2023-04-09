#ifndef LIGHT_H
#define LIGHT_H

#include "visualobject.h"

class Light : public VisualObject
{
public:
    Light();
    // Ambient lighting
    Light(GLfloat r, GLfloat g, GLfloat b, GLfloat intensity);
    // Diffuse lighting
    Light(GLfloat r, GLfloat g, GLfloat b, GLfloat intensity, GLfloat xDir, GLfloat yDir, GLfloat zDir, GLfloat dIntensity);



    QVector3D lightPos;

    unsigned int lightVAO;

    void init(GLint matrixUniform) override;
    void draw() override;

    ~Light();

private:
    QVector3D color;
    GLfloat ambientIntensity;
    GLfloat diffuseIntensity;
    QVector3D direction;
};

#endif // LIGHT_H
