#ifndef CUBE_H
#define CUBE_H

#include "visualobject.h"
#include <QKeyEvent>

class cube : public VisualObject
{
public:
    cube();
    cube(float scale);

    float moveSpeed = 0.05f;
    ~cube() override;

    void init(GLint matrixUniform) override;
    void draw() override;


    std::vector<Vertex> CubePoints;

    float m_Position[3] = {0.0f, 0.0f, 0.0f};
    void Move(float x, float y, float z, QKeyEvent *event);

    void Rotate(bool rotating);
};

#endif // CUBE_H
