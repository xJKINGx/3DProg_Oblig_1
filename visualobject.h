// 3D-programmering 2022
#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "positioncomponent.h"
#include "stb_image.h"

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
        float dist = this->m_Position.distanceToPoint(/*this->m_Position,*/ other->m_Position);
        if (dist < this->Radius + other->Radius) {
            //std::cout << "collision" << std::endl;
        }

    }

    QVector3D getVertexPosition(int index);
    std::vector<Vertex> mVertices;
    std::vector<GLuint> mIndices;

    QVector3D findVectorNormal(/*std::vector<Vertex> myVectorArray*/) {
        for (int i = 0; i < mVertices.size() - 2; i+=3) {
            QVector3D p1 = mVertices[i].m_xyz;
            QVector3D p2 = mVertices[i+1].m_xyz;
            QVector3D p3 = mVertices[i+2].m_xyz;

            QVector3D p12 = p2 - p1;
            QVector3D p13 = p3 - p1;
            QVector3D n = QVector3D::crossProduct(p12, p13).normalized();

            return n;
        }
    }

protected:

    GLuint mVAO{0};
    GLuint mVBO{0};
    GLuint mEBO{0};
    GLuint mIBO{0};
    GLint mMatrixUniform{0};
};

#endif // VISUALOBJECT_H
