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

        PerlinNoise mPerlin = PerlinNoise();
        float mScale = 1.0f;

        for (float i = 0.0f; i < yMax; i++) {
            for (float j = 0.0f; j < xMax; j++) {
                double jP = (double)j / mScale;
                double iP = (double)i / mScale;

                float perlinValue = mPerlin.noise(iP,1,jP) * 2 - 1;

                mVertices.push_back(Vertex{j-offset,0,i-offset,             1,0,0});
                mVertices.push_back(Vertex{(j+1)-offset,0,i-offset,         1,0,0});
                mVertices.push_back(Vertex{j-offset,0,(i+1)-offset,         1,0,0});

                mVertices.push_back(Vertex{j-offset,0,(i+1)-offset,         1,0,0});
                mVertices.push_back(Vertex{(j+1)-offset,0,(i+1)-offset,     1,0,0});
                mVertices.push_back(Vertex{(j+1)-offset,0,i-offset,         1,0,0});
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
