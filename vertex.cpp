// 3D-programmering 2022
#include "vertex.h"
#include <iostream>
Vertex::Vertex()
{


}
Vertex::Vertex(float x, float y, float z, float r, float g, float b)
{
    m_xyz[0] = x; m_xyz[1] = y; m_xyz[2] = z;
    m_normal[0] = r; m_normal[1] = g; m_normal[2] = b;
    m_st[0] = 0.0; m_st[1] = 1.0;
}

Vertex::Vertex(float x, float y, float z, float r, float g, float b, float u, float v)
{
    m_xyz[0] = x; m_xyz[1] = y; m_xyz[2] = z;
    m_normal[0] = r; m_normal[1] = g; m_normal[2] = b;
    m_st[0] = u; m_st[1] = v;
}

Vertex::Vertex(float x, float y, float z, float u, float v)
{
    m_xyz[0] = x; m_xyz[1] = y; m_xyz[2] = z;
    m_normal[0] = 0.86; m_normal[1] = 0.0; m_normal[2] = 0.99;
    m_st[0] = u; m_st[1] = v;
}

std::ostream& operator<< (std::ostream& os, const Vertex& v) {
  os << std::fixed;
  os << "(" << v.m_xyz[0] << ", " << v.m_xyz[1] << ", " << v.m_xyz[2] << ") ";
  os << "(" << v.m_normal[0] << ", " << v.m_normal[1] << ", " << v.m_normal[2] << ") ";
  os << "(" << v.m_st[0] << ", " << v.m_st[1] << ") ";
  return os;
}
std::istream& operator>> (std::istream& is, Vertex& v) {
// Trenger fire temporære variabler som kun skal lese inn parenteser og komma
  char dum, dum2, dum3, dum4;
  is >> dum >> v.m_xyz[0] >> dum2 >> v.m_xyz[1] >> dum3 >> v.m_xyz[2] >> dum4;
  is >> dum >> v.m_normal[0] >> dum2 >> v.m_normal[1] >> dum3 >> v.m_normal[2] >> dum4;
  is >> dum >> v.m_st[0] >> dum2 >> v.m_st[1] >> dum3;
  return is;
}

QVector3D Vertex::CalcBarysentricCoords(const QVector3D& p1, const QVector3D& p2, const QVector3D& p3)
{
    QVector3D p12 = p2 - p1;
    QVector3D p13 = p3 - p1;

    QVector3D n;
    n = n.crossProduct(p12, p13);
    float area = n.length();

    QVector3D baryc;

    // U
    QVector3D p = p2 - this->m_xyz;
    QVector3D q = p3 - this->m_xyz;

    n = n.crossProduct(p, q);
    baryc[0] = n.z()/area;

    // V
    p = p3 - this->m_xyz;
    q = p1 - this->m_xyz;

    n = n.crossProduct(p, q);
    baryc[1] = n.z()/area;

    // W
    p = p1 - this->m_xyz;
    q = p2 - this->m_xyz;

    n = n.crossProduct(p, q);
    baryc[2] = n.z()/area;

    return baryc;
}

QVector3D Vertex::CalcNormal(const QVector3D& p1, const QVector3D& p2, const QVector3D& p3)
{
    QVector3D p12 = p2 - p1;
    QVector3D p13 = p3 - p1;

    QVector3D n;
    n = n.crossProduct(p12, p13);

    return n;
}
