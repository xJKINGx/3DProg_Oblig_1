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
    house(float scale);
    ~house() override;
    void init(GLint matrixUniform) override;
    void draw() override;

    std::vector<Vertex> HousePoints;
    float m_Position[3] = {0.0f, 0.0f, 0.0f};
    float StartPos[3] = {0.0f, 0.0f, 0.0f};
    float HouseColour[3] = {1.0f, 0.0f, 0.0f};
    float RoofColour[3] = {0.0f, 0.0f, 0.0f};
    float FloorColour[3] = {245.0f, 245.0f, 220.0f}; // Fikk ikke til å gjøre gulvet beige :(
    // IN CASE FOUNDATIONS ARE NEEDED
    float FoundationColour[3] = {80.0f, 80.0f, 80.0f}; // No foundation colour either D:
};

#endif // HOUSE_H
