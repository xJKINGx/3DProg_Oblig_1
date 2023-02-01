#ifndef CURVE_H
#define CURVE_H

#include "visualobject.h"
#include "vertex.h"


class Curve : public VisualObject
{
public:
    Curve();
    Curve(std::string fileName, bool readFileCheck);
    void init(GLint matrixUniform) override;
    void draw() override;
    void readFile(std::string fileName);
};

#endif // CURVE_H
