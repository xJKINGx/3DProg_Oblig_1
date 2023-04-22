#include "trianglesurface.h"
#include <iostream>

TriangleSurface::TriangleSurface() : VisualObject()
{

}

TriangleSurface::TriangleSurface(std::string filnavn, bool write)
{
    if (write)
    {
        float xMax = 20.0f;
        float yMax = 20.0f;
        float pointDistance = 1.0f;
        float offset = 10.0f;
        float houseOffset = 2.0f;
        float heightScale = 2.0f;

        for (float i = 0.0f; i < yMax; i++) {
            for (float j = 0.0f; j < xMax; j++) {
                float y = f(j-offset,i-offset) * heightScale;
                mVertices.push_back(Vertex{j-offset,y + houseOffset,i-offset,                                     1,y,0});
                y = f((j+pointDistance)-offset,i-offset) * heightScale;
                mVertices.push_back(Vertex{(j+pointDistance)-offset,y + houseOffset,i-offset,                     1,y,0});
                y = f(j-offset,(i+pointDistance)-offset) * heightScale;
                mVertices.push_back(Vertex{j-offset,y + houseOffset,(i+pointDistance)-offset,                     1,y,0});

                y = f(j-offset,(i+pointDistance)-offset) * heightScale;
                mVertices.push_back(Vertex{j-offset,y + houseOffset,(i+pointDistance)-offset,                     1,y,0});
                y = f((j+pointDistance)-offset,(i+pointDistance)-offset) * heightScale;
                mVertices.push_back(Vertex{(j+pointDistance)-offset,y + houseOffset,(i+pointDistance)-offset,     1,y,0});
                y = f((j+pointDistance)-offset,i-offset) * heightScale;
                mVertices.push_back(Vertex{(j+pointDistance)-offset,y + houseOffset,i-offset,                     1,y,0});
            }

        }

        writeFile(filnavn);
    }
    else
    {
        readFile(filnavn);
    }
    std::cout << "Bababooey:" << mVertices.size() << std::endl;

    for(int i = 0; i <= mVertices.size() - 2; i += 3)
    {
        mVertices[i].m_normal = VisualObject::findVectorNormal(mVertices[i], mVertices[i + 1], mVertices[i + 2]);
        mVertices[i + 1].m_normal = VisualObject::findVectorNormal(mVertices[i], mVertices[i + 1], mVertices[i + 2]);
        mVertices[i + 2].m_normal = VisualObject::findVectorNormal(mVertices[i], mVertices[i + 1], mVertices[i + 2]);


//        std::cout << "Vertex " << i + 1 << "'s normal: " << mVertices[i].m_normal[0] << ", " <<
//                  mVertices[i].m_normal[1] << ", " << mVertices[i].m_normal[2] << std::endl;

//        std::cout << "Vertex " << i + 2 << "'s normal: " << mVertices[i + 1].m_normal[0] << ", " <<
//                  mVertices[i + 1].m_normal[1] << ", " << mVertices[i + 1].m_normal[2] << std::endl;

//        std::cout << "Vertex " << i + 3 << "'s normal: " << mVertices[i + 2].m_normal[0] << ", " <<
//                  mVertices[i + 2].m_normal[1] << ", " << mVertices[i + 2].m_normal[2] << std::endl;
    }
}

TriangleSurface::~TriangleSurface()
{

}

void TriangleSurface::readFile(std::string filnavn)
{
    std::ifstream inn;
    inn.open(filnavn.c_str());

    if (inn.is_open())
    {
        int n;
        Vertex vertex;
        inn >> n;
        mVertices.reserve(n);
        for (int i=0; i<n; i++)
        {
             inn >> vertex;
             mVertices.push_back(vertex);
        }
        inn.close();
    }
}

void TriangleSurface::writeFile(std::string filnavn)
{
    std::ofstream ut;
    ut.open(filnavn.c_str());

    if (ut.is_open())
    {
        auto n = mVertices.size();
        Vertex vertex;
        ut << n << std::endl;
        for (auto it=mVertices.begin(); it != mVertices.end(); it++)
        {
            ut << *it << std::endl;
        }

        ut.close();
    }
}

//float TriangleSurface::GetZValue(float X, float Y)
//{
//    // Z er høyde, så vi kalkulerer høyden basert på X og Y verdien gitt, også returnerer vi Z
//    // Da får vi tilgang til høyden på hvilket som helst punkt.
//    return (2*cos(X)*sin(Y));
//}

float TriangleSurface::f(float x, float z)
{
    float noiseHeight = 0;
    int octaves = 4;
    float scale = 4;
    float amplitude = 1;
    float frequency = 1;
    float persitence = 0.5f;
    float lacunarity = 2;

    PerlinNoise mPerlin = PerlinNoise();

    for (int i{}; i < octaves; i++)
    {
        double xP = (double)x /scale;
        double zP = (double)z /scale;

        xP *= frequency;
        zP *= frequency;

        float perlinValue = mPerlin.noise(xP,1,zP) * 2 - 1;
        noiseHeight += perlinValue * amplitude;

        amplitude *= persitence;
        frequency *= lacunarity;
    }

    return noiseHeight;
}

float TriangleSurface::HeightFromBaryc(const QVector2D& playerPos)
{
    QVector3D v0, v1, v2;
    QVector3D baryc{-1, -1, -1};

    for (int i = 0; i < mVertices.size() - 2; i += 3)
    {
        v0 = {mVertices[i].m_xyz};
        v1 = {mVertices[i + 1].m_xyz};
        v2 = {mVertices[i + 2].m_xyz};

        baryc = CalcBarysentricCoords(QVector2D(v0[0], v0[2]), QVector2D(v1[0], v1[2]), QVector2D(v2[0], v2[2]), playerPos);

        if (baryc.x() >= 0 && baryc.y() >= 0 && baryc.z() >= 0)
        {
            //std::cout << "Found at triangle number: " + std::to_string(i / 3) << std::endl;
            break;
        }
    }

    float height = v0.y() * baryc.x() + v1.y() * baryc.y() + v2.y() * baryc.z();
//    std::cout << "v0: " << v0.y() << std::endl;
//    std::cout << "v1: " << v1.y() << std::endl;
//    std::cout << "v2: " << v2.y() << std::endl;
//    std::cout << "Players apparent height: " << std::to_string(height) << std::endl;
    return height;
}

QVector3D TriangleSurface::CalcBarysentricCoords(const QVector2D& v0, const QVector2D& v1, const QVector2D& v2, const QVector2D& playerPos)
{

    QVector2D v10 = v1 - v0;
    QVector2D v21 = v2 - v1;

    float area = QVector3D::crossProduct(QVector3D(v10, 0.f), QVector3D(v21, 0.0f)).z();

    QVector2D v0p = v0 - playerPos;
    QVector2D v1p = v1 - playerPos;
    QVector2D v2p = v2 - playerPos;

    float u = QVector3D::crossProduct(QVector3D(v0p, 0.0f), QVector3D(v1p, 0.0f)).z() / area;
    float v = QVector3D::crossProduct(QVector3D(v1p, 0.0f), QVector3D(v2p, 0.0f)).z() / area;
    float w = QVector3D::crossProduct(QVector3D(v2p, 0.0f), QVector3D(v0p, 0.0f)).z() / area;

    QVector3D tempBaryc = {u, v, w};

//    std::cout << "U: " << tempBaryc.x() << std::endl;
//    std::cout << "V: " << tempBaryc.y() << std::endl;
//    std::cout << "W: " << tempBaryc.z() << std::endl;

    return tempBaryc;
}


void TriangleSurface::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;
    //must call this to use OpenGL functions
    initializeOpenGLFunctions();

    glGenVertexArrays( 1, &mVAO );
    glBindVertexArray( mVAO );

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers( 1, &mVBO );
    glBindBuffer( GL_ARRAY_BUFFER, mVBO );

    //Vertex Buffer Object to hold vertices - VBO
    glBufferData( GL_ARRAY_BUFFER, mVertices.size()*sizeof( Vertex ), mVertices.data(), GL_DYNAMIC_DRAW );

    // 1rst attribute buffer : vertices
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0  );          // array buffer offset
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof(Vertex),  (GLvoid*)(3 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(1);

    // 3rd attribute buffer : uvs
    glVertexAttribPointer(2, 2,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)( 6 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE,  sizeof(Vertex),  (GLvoid*)(8 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(3);

    glBindVertexArray(0);

}

void TriangleSurface::draw()
{

    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());

}
