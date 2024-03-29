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
        if (dist < Radius + other->Radius && trophiesCollected >= 6) {
            std::cout << trophiesCollected << std::endl;
            std::cout << "PLAYER COLLIDED WITH DOOR" << std::endl;
            //renderValue = 2; // Invisible
            MoveToSecondHouse();
            bSecondScene = true;
        }

    }
};

#endif // PLAYER_H
