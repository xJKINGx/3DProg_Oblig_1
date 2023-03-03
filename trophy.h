#ifndef TROPHY_H
#define TROPHY_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "visualobject.h"

class trophy : public VisualObject
{
private:

public:
   trophy();
   trophy(float scale);
   ~trophy() override;
   void init(GLint matrixUniform) override;
   void draw() override;

   std::vector<Vertex> TrophyPoints;
   float m_Position[3] = {0.0f, 0.0f, 0.0f};
   float StartPos[3] = {0.0f, 0.0f, 0.0f};
   float TrophyColour[3] = {1.0f, 1.0f, 0.0f};
};

#endif // TROPHY_H
