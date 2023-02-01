#include "cube.h"
#include <iostream>
cube::cube()
{

}

cube::cube(float scale)
{
    // NORT SIDE
    Vertex v1{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower right
    Vertex v2{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper left
    Vertex v3{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower left

    Vertex v4{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper Right
    Vertex v5{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower right
    Vertex v6{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper left

    // EAST SIDE
    Vertex v7{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 1, 0, 0}; // Lower left
    Vertex v8{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 0, 0}; // Upper left
    Vertex v9{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 1, 0, 0}; // Lower right

    Vertex v10{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 1, 0, 0}; // Upper right
    Vertex v11{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 1, 0, 0}; // Lower right
    Vertex v12{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 0, 0}; // Upper left

    // SOUTH SIDE
    Vertex v13{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 0}; // Lower right
    Vertex v14{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 0, 1, 0}; // Upper left
    Vertex v15{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 0}; // Lower left

    Vertex v16{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 0, 1, 0}; // Upper Right
    Vertex v17{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 0}; // Lower right
    Vertex v18{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 0, 1, 0}; // Upper left

    // WEST SIDE
    Vertex v19{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 0, 0, 1}; // Lower left
    Vertex v20{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 0, 0, 1}; // Upper left
    Vertex v21{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 0, 0, 1}; // Lower right

    Vertex v22{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 0, 0, 1}; // Upper right
    Vertex v23{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 0, 0, 1}; // Lower right
    Vertex v24{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 0, 0, 1}; // Upper left

    // TOP SIDE
    Vertex v25{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 0, 1}; // Upper north
    Vertex v26{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 0, 1}; // Upper east
    Vertex v27{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 1, 0, 1}; // Upper south

    Vertex v28{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 1, 0, 1}; // Upper south
    Vertex v29{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 1, 0, 1}; // Upper west
    Vertex v30{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 0, 1}; // Upper north

    // BOTTOM SIDE
    Vertex v31{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 0, 1, 1}; // Lower north
    Vertex v32{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 0, 1, 1}; // Lower east
    Vertex v33{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 1}; // Lower south

    Vertex v34{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 1}; // Lower south
    Vertex v35{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 1}; // Lower west
    Vertex v36{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 0, 1, 1}; // Lower north

    CubePoints.push_back(v1);
    CubePoints.push_back(v2);
    CubePoints.push_back(v3);
    CubePoints.push_back(v4);
    CubePoints.push_back(v5);
    CubePoints.push_back(v6);
    CubePoints.push_back(v7);
    CubePoints.push_back(v8);
    CubePoints.push_back(v9);
    CubePoints.push_back(v10);
    CubePoints.push_back(v11);
    CubePoints.push_back(v12);

    CubePoints.push_back(v13);
    CubePoints.push_back(v14);
    CubePoints.push_back(v15);
    CubePoints.push_back(v16);
    CubePoints.push_back(v17);
    CubePoints.push_back(v18);
    CubePoints.push_back(v19);
    CubePoints.push_back(v20);
    CubePoints.push_back(v21);
    CubePoints.push_back(v22);
    CubePoints.push_back(v23);
    CubePoints.push_back(v24);

    CubePoints.push_back(v25);
    CubePoints.push_back(v26);
    CubePoints.push_back(v27);
    CubePoints.push_back(v28);
    CubePoints.push_back(v29);
    CubePoints.push_back(v30);
    CubePoints.push_back(v31);
    CubePoints.push_back(v32);
    CubePoints.push_back(v33);
    CubePoints.push_back(v34);
    CubePoints.push_back(v35);
    CubePoints.push_back(v36);

    for (int i = 0; i < CubePoints.size(); i++)
    {
        mVertices.push_back(CubePoints[i]);
    }

    mMatrix.setToIdentity();
}

cube::~cube()
{

}

void cube::init(GLint matrixUniform)
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

void cube::draw()
{
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

void cube::Move(float x, float y, float z, QKeyEvent *event)
{
    if (event->key() == Qt::Key_Right)
    {
        m_Position[0] += moveSpeed;
        mMatrix.translate(moveSpeed, 0.0f, 0.0f);
        std::cout <<"D";
    }
    if (event->key() == Qt::Key_Left)
    {
        m_Position[0] -= moveSpeed;
                mMatrix.translate(-moveSpeed, 0.0f, 0.0f);
        std::cout <<"A";
    }
    if (event->key() == Qt::Key_Up)
    {
        m_Position[1] -= moveSpeed;
        mMatrix.translate(0.0f, moveSpeed, 0.0f);
        std::cout <<"W";
    }
    if (event->key() == Qt::Key_Down)
    {
        m_Position[1] += moveSpeed;
        mMatrix.translate(0.0f, -moveSpeed, 0.0f);
        std::cout <<"S";
    }
}

void cube::Rotate(bool rotating)
{
    if (rotating){
        mMatrix.rotate(2.0f, 1.0f, 1.0f, 0.0f);
    }
}
