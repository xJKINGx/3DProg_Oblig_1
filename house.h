#ifndef HOUSE_H
#define HOUSE_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "visualobject.h"

class house : public VisualObject
{
public:
    house();
    house(float scale, QVector3D start);
    ~house() override;
    void init(GLint matrixUniform) override;
    void draw() override;


    std::vector<Vertex> HousePoints;
    float StartPos[3] = {0.0f, 0.0f, 0.0f};
    float HouseColour[3] = {0.56f, 0.12f, 0.16f};
    float RoofColour[3] = {0.12f, 0.12f, 0.12f};
    float FloorColour[3] = {0.96f, 0.96f, 0.86f}; // Fikk ikke til å gjøre gulvet beige :(
    // IN CASE FOUNDATIONS ARE NEEDED
    float FoundationColour[3] = {0.5f, 0.5f, 0.5f}; // No foundation colour either D:
};

#endif // HOUSE_H
