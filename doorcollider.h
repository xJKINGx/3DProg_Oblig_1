#ifndef DOORCOLLIDER_H
#define DOORCOLLIDER_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "visualobject.h"

class doorcollider : public VisualObject
{
public:
    doorcollider();
    doorcollider(float scale, QVector3D start);
    ~doorcollider() override;
    void init(GLint matrixUniform) override;
    void draw() override;


    std::vector<Vertex> DoorPoints;
    //float m_Position[3] = {0.0f, 0.0f, 0.0f};
    float StartPos[3] = {0.0f, 0.0f, 0.0f};
    float DoorColour[3] = {0.0f, 0.0f, 0.0f};
};

#endif // DOORCOLLIDER_H
