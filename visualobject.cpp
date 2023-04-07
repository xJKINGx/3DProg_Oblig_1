// 3D-programmering 2022
#include "visualobject.h"

VisualObject::VisualObject() {  }
VisualObject::~VisualObject() {
   glDeleteVertexArrays( 1, &mVAO );
   glDeleteBuffers( 1, &mVBO );
   glDeleteBuffers(1, &mIBO );
}

QVector3D VisualObject::getVertexPosition(int index)
{
    return mVertices[index].m_xyz;
}

//QVector3D VisualObject::getIndicesPosition(int index)
//{
//    return mIndices[index].m_xyz;
//}
