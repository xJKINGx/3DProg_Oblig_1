#ifndef BED_H
#define BED_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "visualobject.h"

class bed : public VisualObject
{
public:
    bed();
    bed(float scale, QVector3D start);
    ~bed() override;
    void init(GLint matrixUniform) override;
    void draw() override;

    std::vector<Vertex> BedPoints;
    //float m_Position[3] = {0.0f, 0.0f, 0.0f};
    float StartPos[3] = {-3.0f, 0.0f, 1.0f};
    float BedColour[3] = {0.0f, 0.0f, 1.0f};
    float MatressAndPillowColour[3] = {0.93f, 0.93f, 0.93f};
};

#endif // BED_H
