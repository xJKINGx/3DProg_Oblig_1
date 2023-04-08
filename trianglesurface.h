#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H

#include "visualobject.h"
#include "vertex.h"
#include "perlinnoise.h"

class TriangleSurface : public VisualObject
{
public:
   TriangleSurface();
   TriangleSurface(std::string filnavn, bool write);
   ~TriangleSurface() override;
   void readFile(std::string filnavn);
   void writeFile(std::string filnavn);
   void init(GLint matrixUniform) override;
   void draw() override;

   float GetZValue(float X, float Y);
   float f(float x, float z);
};

#endif // TRIANGLESURFACE_H
