#ifndef LIGHT_H
#define LIGHT_H

#include "visualobject.h"

class Light : public VisualObject
{
public:
    Light();
    // Ambient lighting
    Light(GLfloat r, GLfloat g, GLfloat b, GLfloat intensity);
    // Ambient & Diffuse lighting
    Light(GLfloat r, GLfloat g, GLfloat b, GLfloat intensity, GLfloat dIntensity);

    // Use only ambient light
    void UseLight(GLuint LightIntensityLocation, GLfloat LightColorLocation);
    // Use both ambient and diffuse light
    void UseLight(GLuint LightIntensityLocation, GLfloat LightColorLocation, GLfloat DiffuseIntensityLocation,
                  GLint LightPositionLocation);


    QVector3D lightPos;

    unsigned int lightVAO;

    void init(GLint matrixUniform) override;
    void draw() override;

    void CreateMesh(float scale, float r, float g, float b);

    ~Light();

private:
    QVector3D color;
    GLfloat ambientIntensity;
    GLfloat diffuseIntensity;
    QVector3D direction;
};

#endif // LIGHT_H
