// 3D-programmering 2022
#ifndef VERTEX_H
#define VERTEX_H
#include <fstream>
#include <qvector3d.h>

class Vertex {
    //! Overloaded ostream operator which writes all vertex data on an open textfile stream
    friend std::ostream& operator<< (std::ostream&, const Vertex&);

    //! Overloaded ostream operator which reads all vertex data from an open textfile stream
    friend std::istream& operator>> (std::istream&, Vertex&);

public:
    QVector3D m_xyz;       	// position i 3D
    float m_rgb[3];
    float m_st[2];        	// texture coordinates if used
    QVector3D m_normal;    // normal in 3D or rgb colors


    QVector3D CalcNormal(const QVector3D& p1, const QVector3D& p2, const QVector3D& p3);
public:
    Vertex();
    Vertex(float x, float y, float z, float r, float g, float b);
    Vertex(float x, float y, float z, float r, float g, float b, float u, float v);
    Vertex(float x, float y, float z, float u, float v);

};


#endif // VERTEX_H
