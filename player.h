#ifndef PLAYER_H
#define PLAYER_H

#include <QKeyEvent>
#include "visualobject.h"

class Player : public VisualObject
{
public:
    Player();
    Player(float scale);

    std::vector<Vertex> PlayerPoints;

    void init(GLint matrixUniform) override;
    void draw() override;

    void Move(QKeyEvent* event);
};

#endif // PLAYER_H
