#ifndef NPC_H
#define NPC_H

#include "curve.h"
#include "visualobject.h"
#include "trianglesurface.h"
#include <fstream>

class NPC : public VisualObject
{
public:
    float Pos[3] = {0.0f, 0.0f, 0.0f};
    float Rotation[3] = {0.0f, 0.0f, 0.0f};

    std::vector<std::string> PathingFileNames;

    NPC();
    void init(GLint matrixUniform) override;
    void draw() override;
    ~NPC();

    void FollowPath(Curve path, TriangleSurface ground);
    void FetchCoordinates(std::string fileName);


};

#endif // NPC_H
