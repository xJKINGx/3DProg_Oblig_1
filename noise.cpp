#include "noise.h"


Noise::Noise()
{

}

QVector2D Noise::GenerateNoiseMap(int mapWidth, int mapHeight, float scale)
{
    //PerlinNoise mPerlin = PerlinNoise();

    if  (scale <= 0)
    {
        scale = 0.0001f;
    }

    for (int y = 0; y < mapHeight; y++)
    {
        for (int x = 0; x < mapWidth; x++)
        {
            double xP = (double)x / mScale;
            double yP = (double)y / mScale;

            float perlinValue = PerlinNoise().noise(xP, yP, 1) * 2 - 1;
        }
    }
}
