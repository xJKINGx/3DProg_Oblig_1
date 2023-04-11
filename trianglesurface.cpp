#include "trianglesurface.h"
#include <iostream>

TriangleSurface::TriangleSurface() : VisualObject()
{
//   //         x   y   z   r g b
//   Vertex v0{0.0,0.0,0.0, 1,0,0};    mVertices.push_back(v0);
//   Vertex v1(0.5,0.0,0.0, 0,1,0);    mVertices.push_back(v1);
//   Vertex v2{0.5,0.5,0.0, 0,0,1};    mVertices.push_back(v2);
//   Vertex v3{0.0,0.0,0.0, 0,0,1};    mVertices.push_back(v3);
//   Vertex v4{0.5,0.5,0.0, 0,1,0};    mVertices.push_back(v4);
//   Vertex v5{0.0,0.5,0.0, 1,0,0};    mVertices.push_back(v5);

//   mMatrix.setToIdentity();

}

TriangleSurface::TriangleSurface(std::string filnavn, bool write)
{
    if (write)
    {
        //float xmin=-8.0f, xmax=8.0f, zmin=-8.0f, zmax=8.0f, h=0.25f;
//        for (auto x=xmin; x<xmax; x+=h)
//        {
//            for (auto z=zmin; z<zmax; z+=h)
//            {
//            // f(x,y) = x * sin(y)
////            float z = x*sin(y);
////            mVertices.push_back(Vertex{x,y,z,x,y,z});
////            z = (x+h)*sin(y);
////            mVertices.push_back(Vertex{x+h,y,z,x,y,z});
////            z = x*(sin(y+h));
////            mVertices.push_back(Vertex{x,y+h,z,x,y,z});
////            mVertices.push_back(Vertex{x,y+h,z,x,y,z});
////            z = (x+h)*sin(y);
////            mVertices.push_back(Vertex{x+h,y,z,x,y,z});
////            z = (x+h) * (sin(y+h));
////            mVertices.push_back(Vertex{x+h,y+h,z,x,y,z});


//            float y = 2*cos(x)*sin(z);
////            float yColor = y;
////            if (y < 0.1f)
////            {
////                yColor = 0.5f;
////            }

//            mVertices.push_back(Vertex{x,y,z, 0.0f,0.0f,y});
//            y = 2*cos(x+h)*sin(z);
//            mVertices.push_back(Vertex{x+h,y,z, 0.0f,0.0f,y});
//            y = 2*cos(x)*(sin(z+h));
//            mVertices.push_back(Vertex{x,y,z+h, 0.0f,0.0f,y});
//            mVertices.push_back(Vertex{x,y,z+h, 0.0f,0.0f,y});
//            y = 2*cos(x+h)*sin(z);
//            mVertices.push_back(Vertex{x+h,y,z, 0.0f,0.0f,y});
//            y = 2*cos(x+h)* (sin(z+h));
//            mVertices.push_back(Vertex{x+h,y,z+h, 0.0f,0.0f,y});

//            }
//        }

        float xMax = 20.0f;
        float yMax = 20.0f;
        float pointDistance = 1.0f;
        float offset = 10.0f;
        float houseOffset = 2.0f;
        float heightScale = 2.0f;

        for (float i = 0.0f; i < yMax; i++) {
            for (float j = 0.0f; j < xMax; j++) {
                float z = f(j-offset,i-offset) * heightScale;
                mVertices.push_back(Vertex{j-offset,z + houseOffset,i-offset,                                     1,z,0});
                z = f((j+pointDistance)-offset,i-offset) * heightScale;
                mVertices.push_back(Vertex{(j+pointDistance)-offset,z + houseOffset,i-offset,                     1,z,0});
                z = f(j-offset,(i+pointDistance)-offset) * heightScale;
                mVertices.push_back(Vertex{j-offset,z + houseOffset,(i+pointDistance)-offset,                     1,z,0});

                z = f(j-offset,(i+pointDistance)-offset) * heightScale;
                mVertices.push_back(Vertex{j-offset,z + houseOffset,(i+pointDistance)-offset,                     1,z,0});
                z = f((j+pointDistance)-offset,(i+pointDistance)-offset) * heightScale;
                mVertices.push_back(Vertex{(j+pointDistance)-offset,z + houseOffset,(i+pointDistance)-offset,     1,z,0});
                z = f((j+pointDistance)-offset,i-offset) * heightScale;
                mVertices.push_back(Vertex{(j+pointDistance)-offset,z + houseOffset,i-offset,                     1,z,0});
            }

        }

        writeFile(filnavn);
    }

    readFile(filnavn);
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

float TriangleSurface::GetZValue(float X, float Y)
{
    // Z er høyde, så vi kalkulerer høyden basert på X og Y verdien gitt, også returnerer vi Z
    // Da får vi tilgang til høyden på hvilket som helst punkt.
    return (2*cos(X)*sin(Y));
}

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

QVector3D TriangleSurface::CalcBarysentricCoords(const QVector2D& playerPos)
{

    QVector3D baryc{-1, -1, -1};
    int i = 0;

    QVector2D p1, p2, p3;

    while (baryc[0] < 0 || baryc[1] < 0 || baryc[2] < 0)
    {
        // Finding the 3 points to check
        p1 = QVector2D(mVertices[i].m_xyz[0], mVertices[i].m_xyz[1]);
        p2 = QVector2D(mVertices[i + 1].m_xyz[0], mVertices[i + 1].m_xyz[1]);
        p3 = QVector2D(mVertices[i + 2].m_xyz[0], mVertices[i + 2].m_xyz[1]);

        QVector2D p21 = p2 - p1;
        QVector2D p31 = p3 - p1;

        QVector3D triangle = QVector3D::crossProduct(QVector3D(p21, 0.0), QVector3D(p31, 0.0));
        float triangleNormal = triangle.length();

        // Getting the vectors from the points to the player's position
        QVector2D p11 = p1 - playerPos;
        QVector2D p12 = p2 - playerPos;
        QVector2D p13 = p3 - playerPos;

        // Calculating area of the triangle using our 3 points
        //float area = QVector3D::crossProduct(QVector3D(p2 - p1, 0.0), QVector3D(p3 - p1, 0.0)).length();

        // Getting the normals from the vertices
        float A = QVector3D::crossProduct(QVector3D(p11, 0.0), QVector3D(p12, 0.0)).z();
        float B = QVector3D::crossProduct(QVector3D(p12, 0.0), QVector3D(p13, 0.0)).z();
        float C = QVector3D::crossProduct(QVector3D(p13, 0.0), QVector3D(p11, 0.0)).z();

        // Finding the coordinates by dividing the length of the vector by the triangles total area
        float u = A / triangleNormal;
        float v = B / triangleNormal;
        float w = C / triangleNormal;

        // Set the output variable to the new values we found
        baryc = QVector3D(u, v, w);

        // U, V, and W must all be < 1 or else the player is outside the triangle and we need to try again
        // We set each of the values to -1 so we can continue the while loop
        if (baryc[0] > 1 || baryc[1] > 1 || baryc[2] > 1)
        {
            baryc = QVector3D{-1, -1, -1};
        }

        // i += 3 because we need to start at each new triangle
        // since mVertices is always divisible by 3, each 3rd vertex is the start of a new triangle
        i += 3;
    }

    return baryc;
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

    glBindVertexArray(0);

}

void TriangleSurface::draw()
{

    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());

}
