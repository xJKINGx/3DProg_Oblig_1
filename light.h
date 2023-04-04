#ifndef LIGHT_H
#define LIGHT_H

#include "visualobject.h"

class Light : public VisualObject
{
public:
    Light();

    QVector3D lightPos;

    unsigned int lightVAO;

    void init(GLint matrixUniform) override;
    void draw() override;
};

#endif // LIGHT_H
