#ifndef NOISE_H
#define NOISE_H

#include "visualobject.h"
#include "perlinnoise.h"
//#include <vector>
//#include <iostream>


class Noise : public VisualObject
{
public:
    Noise();
    QVector2D GenerateNoiseMap(int mapWidth, int mapHeight, float scale);

};

#endif // NOISE_H
