#include "player.h"

Player::Player()
{

}

Player::Player(float scale)
{
    PlayerScale = scale;
    // NORTH SIDE
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

    PlayerPoints.push_back(v1);
    PlayerPoints.push_back(v2);
    PlayerPoints.push_back(v3);
    PlayerPoints.push_back(v4);
    PlayerPoints.push_back(v5);
    PlayerPoints.push_back(v6);
    PlayerPoints.push_back(v7);
    PlayerPoints.push_back(v8);
    PlayerPoints.push_back(v9);
    PlayerPoints.push_back(v10);
    PlayerPoints.push_back(v11);
    PlayerPoints.push_back(v12);

    PlayerPoints.push_back(v13);
    PlayerPoints.push_back(v14);
    PlayerPoints.push_back(v15);
    PlayerPoints.push_back(v16);
    PlayerPoints.push_back(v17);
    PlayerPoints.push_back(v18);
    PlayerPoints.push_back(v19);
    PlayerPoints.push_back(v20);
    PlayerPoints.push_back(v21);
    PlayerPoints.push_back(v22);
    PlayerPoints.push_back(v23);
    PlayerPoints.push_back(v24);

    PlayerPoints.push_back(v25);
    PlayerPoints.push_back(v26);
    PlayerPoints.push_back(v27);
    PlayerPoints.push_back(v28);
    PlayerPoints.push_back(v29);
    PlayerPoints.push_back(v30);
    PlayerPoints.push_back(v31);
    PlayerPoints.push_back(v32);
    PlayerPoints.push_back(v33);
    PlayerPoints.push_back(v34);
    PlayerPoints.push_back(v35);
    PlayerPoints.push_back(v36);

    for (int i = 0; i < PlayerPoints.size(); i++)
    {
        mVertices.push_back(PlayerPoints[i]);
    }

    mMatrix.setToIdentity();
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


    if (bSecondScene != true) {
        auto YCol = mMatrix.column(3);
        YCol.setY(2 * cos(m_Position[0]) * sin(m_Position[2]) + PlayerScale);
        mMatrix.setColumn(3, YCol);
    }
    else
    {
        m_Position[1] = 1000.0f;
    }
}

void Player::MoveToSecondHouse()
{
    mMatrix.translate(m_Position[0] - m_Position[0], m_Position[1] - m_Position[1], m_Position[2] - m_Position[2]);
    m_Position[0] = 1000.0f;
    m_Position[1] = 1000.0f;
    m_Position[2] = 1000.0f;
    mMatrix.translate(m_Position[0], m_Position[1], m_Position[2]);
    std::cout << "Player X: " << m_Position[0] << std::endl;
    std::cout << "Player Y: " << m_Position[1] << std::endl;
    std::cout << "Player Z: " << m_Position[2] << std::endl;
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

    glBindVertexArray(0);
}
