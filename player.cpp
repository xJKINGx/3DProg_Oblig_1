#include "player.h"

Player::Player()
{

}

Player::Player(float scale)
{
    PlayerScale = scale;
    // NORTH SIDE
    Vertex v1{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower left
    Vertex v2{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower right
    Vertex v3{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper left

    Vertex v4{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower right
    Vertex v5{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper Right
    Vertex v6{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper left

    // EAST SIDE
    Vertex v7{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 1, 0, 0}; // Lower left
    Vertex v8{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 1, 0, 0}; // Lower right
    Vertex v9{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 0, 0}; // Upper left

    Vertex v10{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 1, 0, 0}; // Lower right
    Vertex v11{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 1, 0, 0}; // Upper right
    Vertex v12{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 0, 0}; // Upper left

    // SOUTH SIDE
    Vertex v13{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 0}; // Lower left
    Vertex v14{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 0}; // Lower right
    Vertex v15{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 0, 1, 0}; // Upper left

    Vertex v16{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 0}; // Lower right
    Vertex v17{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 0, 1, 0}; // Upper Right
    Vertex v18{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 0, 1, 0}; // Upper left

    // WEST SIDE
    Vertex v19{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 0, 0, 1}; // Lower left
    Vertex v20{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 0, 0, 1}; // Lower right
    Vertex v21{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 0, 0, 1}; // Upper left

    Vertex v22{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 0, 0, 1}; // Lower right
    Vertex v23{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 0, 0, 1}; // Upper right
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

    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v3);
    mVertices.push_back(v4);
    mVertices.push_back(v5);
    mVertices.push_back(v6);
    mVertices.push_back(v7);
    mVertices.push_back(v8);
    mVertices.push_back(v9);
    mVertices.push_back(v10);
    mVertices.push_back(v11);
    mVertices.push_back(v12);

    mVertices.push_back(v13);
    mVertices.push_back(v14);
    mVertices.push_back(v15);
    mVertices.push_back(v16);
    mVertices.push_back(v17);
    mVertices.push_back(v18);
    mVertices.push_back(v19);
    mVertices.push_back(v20);
    mVertices.push_back(v21);
    mVertices.push_back(v22);
    mVertices.push_back(v23);
    mVertices.push_back(v24);

    mVertices.push_back(v25);
    mVertices.push_back(v26);
    mVertices.push_back(v27);
    mVertices.push_back(v28);
    mVertices.push_back(v29);
    mVertices.push_back(v30);
    mVertices.push_back(v31);
    mVertices.push_back(v32);
    mVertices.push_back(v33);
    mVertices.push_back(v34);
    mVertices.push_back(v35);
    mVertices.push_back(v36);

    mMatrix.setToIdentity();

    for(int i = 0; i <= mVertices.size() - 2; i += 3)
    {
        QVector3D norm = VisualObject::findVectorNormal(mVertices[i], mVertices[i + 1], mVertices[i + 2]);
        mVertices[i].m_normal = norm;
        mVertices[i + 1].m_normal = norm;
        mVertices[i + 2].m_normal = norm;
    }

}

void Player::Move(QKeyEvent* event)
{
    moveSpeed = 0.2f;
    if (event->key() == Qt::Key_D)
    {
        m_Position[0] -= moveSpeed;
        mMatrix.translate(-moveSpeed, 0.0f, 0.0f);
    }
    if (event->key() == Qt::Key_A)
    {
        m_Position[0] += moveSpeed;
        mMatrix.translate(moveSpeed, 0.0f, 0.0f);
    }
    if (event->key() == Qt::Key_W)
    {
        m_Position[2] += moveSpeed;
        mMatrix.translate(0.0f, 0.0f, moveSpeed);
    }
    if (event->key() == Qt::Key_S)
    {
        m_Position[2] -= moveSpeed;
        mMatrix.translate(0.0f, 0.0f, -moveSpeed);
    }


//    if (bSecondScene != true) {
//        auto YCol = mMatrix.column(3);
//        YCol.setY(2 * cos(m_Position[0]) * sin(m_Position[2]) + PlayerScale);
//        m_Position[1] = (2 * cos(m_Position[0]) * sin(m_Position[2]) + PlayerScale);
//        mMatrix.setColumn(3, YCol);
//    }
//    else
//    {
//        m_Position[1] = 1000.0f;
//    }
}

void Player::MoveToSecondHouse()
{
    if (!bSecondScene)
    {
        m_Position[0] = 998.0f;
        m_Position[1] = 1001.0f;
        m_Position[2] = 1000.0f;

        auto V4D = mMatrix.column(3);
        V4D.setX(m_Position.x());
        V4D.setY(m_Position.y());
        V4D.setZ(m_Position.z());
        mMatrix.setColumn(3, V4D);
    }
}

void Player::draw()
{
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

void Player:: init(GLint matrixUniform)
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
