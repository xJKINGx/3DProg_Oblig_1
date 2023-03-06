#ifndef PLAYER_H
#define PLAYER_H

#include <QKeyEvent>
#include "visualobject.h"
#include <iostream>
class Player : public VisualObject
{
public:
    Player();
    Player(float scale);

    float PlayerScale;

    bool bSecondScene = false;

    std::vector<Vertex> PlayerPoints;

    void init(GLint matrixUniform) override;
    void draw() override;


    void Move(QKeyEvent* event);
    void MoveToSecondHouse();

    void checkCollision(VisualObject* other) override {

        float dist = m_Position.distanceToPoint(other->m_Position);
        if (dist < Radius + other->Radius) {
            std::cout << "PLAYER COLLIDED WITH DOOR" << std::endl;
            //renderValue = 2; // Invisible
            bSecondScene = true;
            MoveToSecondHouse();
            std::cout << bSecondScene << std::endl;
        }
        else
        {
            //std::cout << "No collision" << std::endl;
            //renderValue = 0; // Wireframe
        }
    }
};

#endif // PLAYER_H
