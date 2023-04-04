#ifndef SECONDSCENEHOUSE_H
#define SECONDSCENEHOUSE_H


#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "visualobject.h"

class secondscenehouse : public VisualObject
{
public:
    secondscenehouse();
    secondscenehouse(float scale, QVector3D start);
    ~secondscenehouse() override;
    void init(GLint matrixUniform) override;
    void draw() override;


    std::vector<Vertex> HousePoints;
    float StartPos[3] = {0.0f, 0.0f, 0.0f};
    float HouseColour[3] = {1.0f, 0.0f, 0.0f};
    float RoofColour[3] = {0.0f, 0.0f, 0.0f};
    float FloorColour[3] = {0.96f, 0.96f, 0.86f}; // Fikk ikke til å gjøre gulvet beige :(
    // IN CASE FOUNDATIONS ARE NEEDED
    //float FoundationColour[3] = {0.7f, 0.7f, 0.7f}; // No foundation colour either D:
};

#endif // SECONDSCENEHOUSE_H
