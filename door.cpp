#include "door.h"

door::door()
{

}

door::door(float scale, QVector3D start)
{
    m_Position = start;
    // FRONT
    Vertex v1{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v2{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v3{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};

    Vertex v4{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v5{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v6{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};

    // WEST
    Vertex v7{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v8{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v9{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};

    Vertex v10{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v11{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v12{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};

    // BACK
    Vertex v13{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v14{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v15{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};

    Vertex v16{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v17{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v18{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};

    // EAST
    Vertex v19{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v20{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v21{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};

    Vertex v22{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v23{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v24{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};

    // TOP
    Vertex v25{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v26{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v27{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};

    Vertex v28{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v29{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v30{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};

    // BOTTOM
    Vertex v31{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v32{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v33{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};

    Vertex v34{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v35{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/6, DoorColour[0], DoorColour[1], DoorColour[2]};
    Vertex v36{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], DoorColour[0], DoorColour[1], DoorColour[2]};



    DoorPoints.push_back(v1);
    DoorPoints.push_back(v2);
    DoorPoints.push_back(v3);
    DoorPoints.push_back(v4);
    DoorPoints.push_back(v5);
    DoorPoints.push_back(v6);

    DoorPoints.push_back(v7);
    DoorPoints.push_back(v8);
    DoorPoints.push_back(v9);
    DoorPoints.push_back(v10);
    DoorPoints.push_back(v11);
    DoorPoints.push_back(v12);

    DoorPoints.push_back(v13);
    DoorPoints.push_back(v14);
    DoorPoints.push_back(v15);
    DoorPoints.push_back(v16);
    DoorPoints.push_back(v17);
    DoorPoints.push_back(v18);

    DoorPoints.push_back(v19);
    DoorPoints.push_back(v20);
    DoorPoints.push_back(v21);
    DoorPoints.push_back(v22);
    DoorPoints.push_back(v23);
    DoorPoints.push_back(v24);

    DoorPoints.push_back(v25);
    DoorPoints.push_back(v26);
    DoorPoints.push_back(v27);
    DoorPoints.push_back(v28);
    DoorPoints.push_back(v29);
    DoorPoints.push_back(v30);

    DoorPoints.push_back(v31);
    DoorPoints.push_back(v32);
    DoorPoints.push_back(v33);
    DoorPoints.push_back(v34);
    DoorPoints.push_back(v35);
    DoorPoints.push_back(v36);



    for (int i = 0; i < DoorPoints.size(); i++)
    {
        mVertices.push_back(DoorPoints[i]);
    }

    mMatrix.setToIdentity();
}

door::~door() {    }

void door::init(GLint matrixUniform) {
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

   glBindVertexArray(0);
}

void door::draw()
{
   glBindVertexArray( mVAO );
   glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
   glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
   // (0,0) (1,0) (2,0) (3,0)
}

void door::Rotate(bool rotating)
{
    if (rotating)
    {

        if (maxValue >= 0)
        {
            mMatrix.translate(0.5f, -2.0f, 1.5f);
            mMatrix.rotate(rotationAngle, 0.0f, 1.0f, 0.0f);
            mMatrix.translate(-0.5f, 2.0f, -1.5f);
            maxValue += rotationAngle;
        }
    }
}
