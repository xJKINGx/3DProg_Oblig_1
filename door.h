#ifndef DOOR_H
#define DOOR_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "visualobject.h"

class door : public VisualObject
{
public:
    door();
    door(float scale, QVector3D start);
    ~door() override;
    void init(GLint matrixUniform) override;
    void draw() override;

    std::vector<Vertex> DoorPoints;
    //float m_Position[3] = {0.0f, 0.0f, 0.0f};
    float StartPos[3] = {0.0f, 0.0f, 0.0f};
    float DoorColour[3] = {0.64f, 0.16f, 0.16f};
};

#endif // DOOR_H
