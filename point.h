#ifndef POINT_H
#define POINT_H
#include "visualobject.h"
#include "vertex.h"

class point : public VisualObject
{
public:
    ~point();

    float mPos[3] = {0.0f, 0.0f, 0.0f};

    point();
    point(std::string fileName, bool readFileCheck);
    void init(GLint matrixUniform) override;
    void draw() override;

    void readFile(std::string fileName);
};
#endif // POINT_H
