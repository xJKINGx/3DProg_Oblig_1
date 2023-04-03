// 3D-programmering 2022
#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "positioncomponent.h"

class VisualObject : public QOpenGLFunctions_4_1_Core, public positionComponent {
public:
    VisualObject();
    ~VisualObject();
    virtual void init(GLint matrixUniform)=0;
    virtual void draw()=0;

    int renderValue = 0;
    int trophiesCollected = 0;

    float Radius = 0.5f;

    virtual void checkCollision(VisualObject* other) {
        //const glm::vec3 you = this->position;
        float dist = this->m_Position.distanceToPoint(/*this->m_Position,*/ other->m_Position);
        if (dist < this->Radius + other->Radius) {
            //std::cout << "collision" << std::endl;
        }

    }

    QVector3D getVertexPosition(int index);
    std::vector<Vertex> mVertices;

protected:

    GLuint mVAO{0};
    GLuint mVBO{0};
    GLint mMatrixUniform{0};
    QMatrix4x4 mMatrix;
};

#endif // VISUALOBJECT_H
