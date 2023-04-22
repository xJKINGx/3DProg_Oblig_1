#include "curve.h"

Curve::Curve()
{
    Vertex v1 (0.0,0.5,0.0, 1,0,0);     mVertices.push_back(v1);
    Vertex v2 (0.1,0.6,0.0, 1,0,0);     mVertices.push_back(v2);
    Vertex v3 (0.2,0.7,0.0, 1,0,0);     mVertices.push_back(v3);
    Vertex v4 (0.3,0.8,0.0, 0,1,0);     mVertices.push_back(v4);
    Vertex v5 (0.4,0.9,0.0, 0,1,0);     mVertices.push_back(v5);
    Vertex v6 (0.5,1.0,0.0, 0,1,0);     mVertices.push_back(v6);
    Vertex v7 (0.6,1.1,0.0, 0,0,1);     mVertices.push_back(v7);
    Vertex v8 (0.7,1.2,0.0, 0,0,1);     mVertices.push_back(v8);
    Vertex v9 (0.8,1.3,0.0, 0,0,1);     mVertices.push_back(v9);

    mMatrix.setToIdentity();
}

Curve::Curve(std::string fileName, bool readFileCheck)
{
    if  (readFileCheck == true)
    {
        readFile(fileName);
    }
}

// Parameternavnet er byttet ut fra leksjonen
// Koden er ellers som for XYZ::init()
void Curve::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;

    initializeOpenGLFunctions();

    //Vertex Array Object - VAO
    glGenVertexArrays( 1, &mVAO );
    glBindVertexArray( mVAO );

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers( 1, &mVBO );
    glBindBuffer( GL_ARRAY_BUFFER, mVBO );

    glBufferData( GL_ARRAY_BUFFER, mVertices.size()*sizeof( Vertex ), mVertices.data(), GL_STATIC_DRAW );

    // 1rst attribute buffer : vertices
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof( Vertex ),  (GLvoid*)(3 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE,  sizeof(Vertex),  (GLvoid*)(8 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(3);

    glBindVertexArray(0);
}

void Curve::draw()
{
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_LINE_STRIP, 0, mVertices.size());
}

void Curve::readFile(std::string fileName)
{
    std::ifstream input;
    input.open(fileName.c_str());

    if (input.is_open())
    {
        ActiveFile = fileName;
        int n;
        Vertex vertex;
        input >> n;
        mVertices.reserve(n);
        for (int i = 0; i < n; i++)
        {
             input >> vertex;
             mVertices.push_back(vertex);
        }
        input.close();
    }
}
