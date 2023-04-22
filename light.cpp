#include "light.h"
#include <iostream>

// Default values for both ambient and diffuse lighting
Light::Light()
{
    CreateMesh(0.1f);
    color = QVector3D(1.0f, 1.0f, 1.0f);
    direction = QVector3D(0.0f, -1.0f, 0.0f); // pointing downwards

    ambientIntensity = 0.3f;
    diffuseIntensity = 0.8f;
}

// Used for ambient lighting only
Light::Light(GLfloat r, GLfloat g, GLfloat b, GLfloat intensity)
{
    CreateMesh(0.1f);
    color = QVector3D(r, g, b);
    ambientIntensity = intensity;
}

// Used for ambient and diffuse lighting
Light::Light(GLfloat r, GLfloat g, GLfloat b, GLfloat intensity, GLfloat xDir, GLfloat yDir, GLfloat zDir, GLfloat dIntensity)
{
    CreateMesh(0.1f);

    color = QVector3D(r, g, b);
    ambientIntensity = intensity;
    direction = QVector3D(xDir, yDir, zDir);
    diffuseIntensity = dIntensity;
}

void Light::UseLight(GLuint LightIntensityLocation, GLfloat LightColorLocation)
{
    glUniform3f(LightColorLocation, color[0], color[1], color[2]);
    glUniform1f(LightIntensityLocation, ambientIntensity);
}

void Light::UseLight(GLuint LightIntensityLocation, GLfloat LightColorLocation, GLfloat DiffuseIntensityLocation,
                     GLfloat DirectionLocation)
{
    glUniform3f(LightColorLocation, color[0], color[1], color[2]);
    glUniform1f(LightIntensityLocation, ambientIntensity);

    glUniform3f(DirectionLocation, direction[0], direction[1], direction[2]);
    glUniform1f(DiffuseIntensityLocation, diffuseIntensity);
}

void Light::CreateMesh(float scale)
{
    // NORTH SIDE
    Vertex v1{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower right
    Vertex v2{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper left
    Vertex v3{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower left

    Vertex v4{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper Right
    Vertex v5{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower right
    Vertex v6{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper left

    // EAST SIDE
    Vertex v7{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower left
    Vertex v8{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper left
    Vertex v9{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 1, 1, 1}; // Lower right

    Vertex v10{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 1, 1, 1}; // Upper right
    Vertex v11{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 1, 1, 1}; // Lower right
    Vertex v12{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper left

    // SOUTH SIDE
    Vertex v13{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 1, 1, 1}; // Lower right
    Vertex v14{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 1, 1, 1}; // Upper left
    Vertex v15{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 1, 1, 1}; // Lower left

    Vertex v16{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 1, 1, 1}; // Upper Right
    Vertex v17{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 1, 1, 1}; // Lower right
    Vertex v18{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 1, 1, 1}; // Upper left

    // WEST SIDE
    Vertex v19{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower left
    Vertex v20{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper left
    Vertex v21{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 1, 1, 1}; // Lower right

    Vertex v22{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 1, 1, 1}; // Upper right
    Vertex v23{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 1, 1, 1}; // Lower right
    Vertex v24{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper left

    // TOP SIDE
    Vertex v25{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper north
    Vertex v26{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper east
    Vertex v27{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 1, 1, 1}; // Upper south

    Vertex v28{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 1, 1, 1}; // Upper south
    Vertex v29{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 1, 1, 1}; // Upper west
    Vertex v30{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper north

    // BOTTOM SIDE
    Vertex v31{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower north
    Vertex v32{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower east
    Vertex v33{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 1, 1, 1}; // Lower south

    Vertex v34{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 1, 1, 1}; // Lower south
    Vertex v35{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 1, 1, 1}; // Lower west
    Vertex v36{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 1, 1, 1}; // Lower north

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
}

void Light::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;

    // Since the light requires a new VAO, we need to create a special override for the init function
    initializeOpenGLFunctions();


    glGenVertexArrays( 1, &lightVAO );
    glBindVertexArray( lightVAO );

    glGenBuffers( 1, &mVBO );
    glBindBuffer( GL_ARRAY_BUFFER, mVBO );

    glBufferData( GL_ARRAY_BUFFER, mVertices.size()*sizeof( Vertex ), mVertices.data(), GL_DYNAMIC_DRAW );

    // Vertices
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0  );
    glEnableVertexAttribArray(0);

    // Colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof(Vertex),  (GLvoid*)(3 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(1);


    glBindVertexArray(0);
}

void Light::draw()
{
    glBindVertexArray( lightVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

Light::~Light()
{

}
