#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include "visualobject.h"
#include "perlinnoise.h"
#include <vector>
#include <iostream>


class Landscape : public VisualObject
{
public:
    Landscape(QVector2D bottomLeft, QVector2D topRight);
    Landscape(std::string fileLocation);
    ~Landscape();

    void update(int octaves, float persistance, float lacunarity, float scale);
    void init(GLint matrixUniform);
    void draw();
    void draw(QMatrix4x4 transformMatrix);

    float f(float x, float y);
    //Color recalc(float z);


    float height;
    float width;
    float mPersitence;
    float mLacunarity;
    int mOctaves;
    float mScale;

    //bool bIsActive = true;

};

#endif // LANDSCAPE_H
