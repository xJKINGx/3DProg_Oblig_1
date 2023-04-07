#ifndef NPC_H
#define NPC_H

#include "curve.h"
#include "visualobject.h"
#include "trianglesurface.h"
#include <fstream>
#include <iostream>

class NPC : public VisualObject
{
public:
    float Pos[3] = {0.0f, 0.0f, 0.0f};
    float Rotation[3] = {0.0f, 0.0f, 0.0f};

    std::vector<std::string> PathingFileNames;

    int nodeIndex{};
    int VartAmount{41};
    bool NPCLeft = false;
    bool graph1 = true;

    NPC();
    NPC(GLint matrixUniform);
    NPC(float scale, int filler);
    void init(GLint matrixUniform) override;
    void init(unsigned int* indices, unsigned int numOfVertices, unsigned int numOfIndices);
    void draw() override;
    QVector3D temp = {0.0f, 0.0f, 0.0f};

    ~NPC();

    void FollowPath(Curve* curve1, Curve* curve2);
    void FetchCoordinates(std::string fileName);

    void checkCollision(VisualObject* other) override {

        float dist = m_Position.distanceToPoint(other->m_Position);
        if (dist < Radius + other->Radius) {
            std::cout << "NPC and Player collided" << std::endl;
        }

    }
};

#endif // NPC_H
