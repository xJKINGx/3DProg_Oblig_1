#define STB_IMAGE_IMPLEMENTATION

#include "landscape.h"
#include "stb_image.h"
#include "logger.h"

Landscape::Landscape(QVector2D bottomLeft, QVector2D topRight)
{
    // Prep beforehand
    height = 0;
    mPersitence = 0.5;
    mLacunarity = 2;
    mOctaves = 4;
    mScale = 4;
    width = 0;

    float minX = bottomLeft.x();
    float maxX = topRight.x();

    float minY = bottomLeft.y();
    float maxY = topRight.y();

    float step = 0.5f;

    for (auto y = minY; y < maxY; y += step)
    {
        height++;
        for (auto x = minX; x < maxX; x += step)
        {
            width++;
            float z = f(x,y);
            mVertices.push_back(Vertex(x,y,z,0,0,1));

        }
    }
    width = width / height;

    // Indices loop
    for (auto y = 0; y < height - 1; y++)
    {
        for (auto x = 0; x < width - 1; x++)
        {
            mIndices.push_back((y * width) + x);
            mIndices.push_back((y * width) + x + 1);
            mIndices.push_back((y * width) + x + width);

            mIndices.push_back((y * width) + x + 1);
            mIndices.push_back((y * width) + x + width + 1);
            mIndices.push_back((y * width) + x + width);
        }
    }
}

// For loading in the heightmap
Landscape::Landscape(std::string fileLocation)
{
    // Prep again
    int Width, Height, nrChannels;
    unsigned char *data = stbi_load(fileLocation.c_str(), &Width, &Height, &nrChannels, 0);

    if (data)
    {
        std::cout << fileLocation.c_str() << std::endl;
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    int a = 0, b = 0;
    for (auto y = -Height / 2; y < Height/ 2; y ++)
    {
        b++;
        a = 0;
        for (auto x = -Width / 2; x < Width/ 2; x++)
        {
            a++;
            float z = 0;
            for (int i{}; i < nrChannels; i++)
            {
                z += data[a + (b * Width) * nrChannels + i ];
            }
            z = z / nrChannels;
            mVertices.push_back(Vertex(x * 0.2f,y * 0.2f,z * 0.1f,0,0,1));
        }
    }

    // Indices again
    for (auto y = 0; y < Height - 1; y++)
    {
        for (auto x = 0; x < Width - 1; x++)
        {
            mIndices.push_back((y * Width) + x);
            mIndices.push_back((y * Width) + x + 1);
            mIndices.push_back((y * Width) + x + Width);

            mIndices.push_back((y * Width) + x + 1);
            mIndices.push_back((y * Width) + x + Width + 1);
            mIndices.push_back((y * Width) + x + Width);
        }
    }

    stbi_image_free(data);
}

// Deconstructor
Landscape::~Landscape()
{

}

// Update function
void Landscape::update(int octaves, float persistance, float lacunarity, float scale)
{
    mOctaves = octaves;
    mPersitence = persistance;
    mLacunarity = lacunarity;
    mScale = scale;

    for(size_t i{}; i < mVertices.size();i++)
    {
        float z = f(mVertices[i].m_xyz[0], mVertices[i].m_xyz[1]);

        QVector3D position;
        position[0] = mVertices[i].m_xyz[0];
        position[1] = mVertices[i].m_xyz[1];
        position[2] = z;
    }

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, mVertices.size()*sizeof(Vertex), mVertices.data(), GL_STATIC_DRAW);
}

// Init function
void Landscape::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;
    initializeOpenGLFunctions();

    //Vertex Array Object - VAO
    glGenVertexArrays( 1, &mVAO );
    glBindVertexArray( mVAO );

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers( 1, &mVBO );
    glBindBuffer( GL_ARRAY_BUFFER, mVBO );

    glBufferData( GL_ARRAY_BUFFER, mVertices.size()*sizeof(Vertex), mVertices.data(), GL_STATIC_DRAW );

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE,sizeof(Vertex), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mIndices), mIndices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

// Draw 1
void Landscape::draw()
{
//    if (bIsActive)
//    {
        glBindVertexArray( mVAO );
        glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
        glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
    //}
}

// Draw 2
void Landscape::draw(QMatrix4x4 transformMatrix)
{
//    if (bIsActive)
//    {
        transformMatrix *= mMatrix;
        glBindVertexArray( mVAO );
        glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, transformMatrix.constData());
        glDrawElements(GL_TRIANGLES, mIndices.size(), GL_UNSIGNED_INT, mIndices.data());
    //}
}

// For preparing variables and PerlinNoise
float Landscape::f(float x, float y)
{
    float noiseHeight = 0;
    float amplitude = 1;
    float frequency = 1;

    PerlinNoise mPerlin = PerlinNoise();

    for (int i{}; i < mOctaves; i++)
    {
        double xP = (double)x / mScale;
        double yP = (double)y / mScale;

        xP *= frequency;
        yP *= frequency;

        float perlinValue = mPerlin.noise(xP,yP,1) * 2 - 1;
        noiseHeight += perlinValue * amplitude;

        amplitude *= mPersitence;
        frequency *= mLacunarity;
    }

    return noiseHeight;
}
