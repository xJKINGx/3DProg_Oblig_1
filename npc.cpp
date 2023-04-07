#include "npc.h"
#include <iostream>

NPC::NPC()
{

}

NPC::NPC(GLint matrixUniform) : VisualObject()
{
    mMatrixUniform = matrixUniform;
    GLuint indices[] = {
        0, 1, 2, 2, 3, 0,       // Front face
        4, 5, 6, 6, 7, 4,       // Back face
        8, 9, 10, 10, 11, 8,    // Left face
        12, 13, 14, 14, 15, 12, // Right face
        16, 17, 18, 18, 19, 16, // Top face
        20, 21, 22, 22, 23, 20  // Bottom face
    };

    /* FRONT FACE
    -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, // Bottom-left
    0.5f, -0.5f, 0.5f,  1.0f, 0.0f, // Bottom-right
    0.5f,  0.5f, 0.5f,  1.0f, 1.0f, // Top-right
    -0.5f,  0.5f, 0.5f,  0.0f, 1.0f, // Top-left
    */

    Vertex v1{m_Position[0] - 0.5f, m_Position[1] - 0.5f, m_Position[2] + 0.5f, 0.0f, 0.0f};
    Vertex v2{m_Position[0] + 0.5f, m_Position[1] - 0.5f, m_Position[2] + 0.5f, 1.0f, 0.0f};
    Vertex v3{m_Position[0] + 0.5f, m_Position[1] + 0.5f, m_Position[2] + 0.5f, 1.0f, 1.0f};
    Vertex v4{m_Position[0] - 0.5f, m_Position[1] + 0.5f, m_Position[2] + 0.5f, 0.0f, 0.0f};

    /* BACK FACE
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, // Bottom-left
    0.5f, -0.5f, -0.5f, 1.0f, 0.0f, // Bottom-right
    0.5f,  0.5f, -0.5f, 1.0f, 1.0f, // Top-right
    -0.5f,  0.5f, -0.5f, 0.0f, 1.0f, // Top-left
    */

    Vertex v5{m_Position[0] - 0.5f, m_Position[1] - 0.5f, m_Position[2] - 0.5f, 0.0f, 0.0f};
    Vertex v6{m_Position[0] + 0.5f, m_Position[1] - 0.5f, m_Position[2] - 0.5f, 1.0f, 0.0f};
    Vertex v7{m_Position[0] + 0.5f, m_Position[1] + 0.5f, m_Position[2] - 0.5f, 1.0f, 1.0f};
    Vertex v8{m_Position[0] - 0.5f, m_Position[1] + 0.5f, m_Position[2] - 0.5f, 0.0f, 1.0f};

    /* LEFT FACE
    -0.5f,  0.5f,  0.5f, 1.0f, 0.0f, // Top-right
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, // Top-left
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, // Bottom-left
    -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, // Bottom-right
    */

    Vertex v9 {m_Position[0] - 0.5f, m_Position[1] + 0.5f, m_Position[2] + 0.5f, 1.0f, 0.0f};
    Vertex v10{m_Position[0] - 0.5f, m_Position[1] + 0.5f, m_Position[2] - 0.5f, 1.0f, 1.0f};
    Vertex v11{m_Position[0] - 0.5f, m_Position[1] - 0.5f, m_Position[2] - 0.5f, 0.0f, 1.0f};
    Vertex v12{m_Position[0] - 0.5f, m_Position[1] - 0.5f, m_Position[2] + 0.5f, 0.0f, 0.0f};

    /* RIGHT FACE
    0.5f,  0.5f,  0.5f, 0.0f, 0.0f, // Top-left
    0.5f,  0.5f, -0.5f, 1.0f, 0.0f, // Top-right
    0.5f, -0.5f, -0.5f, 1.0f, 1.0f, // Bottom-right
    0.5f, -0.5f,  0.5f, 0.0f, 1.0f, // Bottom-left
    */

    Vertex v13{m_Position[0] + 0.5f, m_Position[1] + 0.5f, m_Position[2] + 0.5f, 0.0f, 0.0f};
    Vertex v14{m_Position[0] + 0.5f, m_Position[1] + 0.5f, m_Position[2] - 0.5f, 1.0f, 0.0f};
    Vertex v15{m_Position[0] + 0.5f, m_Position[1] - 0.5f, m_Position[2] - 0.5f, 1.0f, 1.0f};
    Vertex v16{m_Position[0] + 0.5f, m_Position[1] - 0.5f, m_Position[2] + 0.5f, 0.0f, 1.0f};

    /* TOP FACE
    -0.5f,  0.5f,  0.5f, 0.0f, 1.0f, // Bottom-left
    0.5f,  0.5f,  0.5f, 1.0f, 1.0f, // Bottom-right
    0.5f,  0.5f, -0.5f, 1.0f, 0.0f, // Top-right
    -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, // Top-left
    */

    Vertex v17{m_Position[0] - 0.5f, m_Position[1] + 0.5f, m_Position[2] + 0.5f, 0.0f, 1.0f};
    Vertex v18{m_Position[0] + 0.5f, m_Position[1] + 0.5f, m_Position[2] + 0.5f, 1.0f, 1.0f};
    Vertex v19{m_Position[0] + 0.5f, m_Position[1] + 0.5f, m_Position[2] - 0.5f, 1.0f, 0.0f};
    Vertex v20{m_Position[0] - 0.5f, m_Position[1] + 0.5f, m_Position[2] - 0.5f, 0.0f, 0.0f};

    /* BOTTOM FACE
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, // Top-left
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f, // Top-right
    0.5f, -0.5f, -0.5f, 1.0f, 1.0f, // Bottom-right
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f // Bottom-left
    */

    Vertex v21{m_Position[0] - 0.5f, m_Position[1] - 0.5f, m_Position[2] + 0.5f, 0.0f, 0.0f};
    Vertex v22{m_Position[0] + 0.5f, m_Position[1] - 0.5f, m_Position[2] + 0.5f, 1.0f, 0.0f};
    Vertex v23{m_Position[0] + 0.5f, m_Position[1] - 0.5f, m_Position[2] - 0.5f, 1.0f, 1.0f};
    Vertex v24{m_Position[0] - 0.5f, m_Position[1] - 0.5f, m_Position[2] - 0.5f, 0.0f, 1.0f};

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

    mMatrix.setToIdentity();

    init(indices, sizeof(mVertices)/sizeof(mVertices[0]), sizeof(indices)/sizeof(indices[0]));
}

NPC::NPC(float scale, int filler)
{
    //FetchCoordinates("graph.txt");
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

void NPC::FollowPath(Curve* curve1, Curve* curve2)
{
    if(nodeIndex < VartAmount && NPCLeft)
    {
        if (graph1) {
            temp = curve1->getVertexPosition(nodeIndex);
        }
        else if (!graph1) {
            temp = curve2->getVertexPosition(nodeIndex);
        }

        setPosition(QVector3D{temp[0], temp[1], temp[2]});
        //std::cout << nodeIndex << std::endl;



        nodeIndex += 1;
        if (nodeIndex >= VartAmount - 1) {
            //std::cout << "kjør da" << std::endl;
            //ballIndex = vartAmount;
            NPCLeft = false;
        }
    }
    else if (nodeIndex >= 0 && !NPCLeft)
    {
        if (graph1) {
            temp = curve1->getVertexPosition(nodeIndex);
        }
        else if (!graph1) {
            temp = curve2->getVertexPosition(nodeIndex);
        }

        setPosition(QVector3D{temp[0], temp[1], temp[2]});
        nodeIndex--;
        if (nodeIndex <= 0) {
            nodeIndex = 0;
            NPCLeft = true;
        }
    }
}

void NPC::FetchCoordinates(std::string fileName)
{
    // iFile = inputfile AKA readfile, oFile = outputfile AKA writefile
    std::ifstream iFile;
    std::ofstream oFile;
    iFile.open(fileName);

    std::string ConvertedString = fileName;

    // removes the ".txt" part of the filename
    ConvertedString.pop_back();
    ConvertedString.pop_back();
    ConvertedString.pop_back();
    ConvertedString.pop_back();


    ConvertedString += "Output.txt";
    // Opens or creates a file with the input filename minus the ".txt" and adds "Output.txt"
    oFile.open(ConvertedString);

    // dum1, dum2 etc. are for filler characters like "(" and ", "
    char dum1, dum2, dum3, dum4;
    // X, Y, Z are for storing the values fetched from the file
    float X, Y, Z;

    // Checking if they're open
    if (iFile.is_open() && oFile.is_open())
    {
        // n will be total points in the file
        int n;
        iFile >> n;
        VartAmount = n;

        // we need this for the output file as well, so we add it
        oFile << n << "\n";

        for (int i = 1; i < n; i++)
        {
            // Here we fetch the X, Y and Z values from the input files and put them in the correct variables
            iFile >> dum1 >> X >> dum2 >> Y >> dum3 >> Z >> dum4;
            // After we've done this we ignore everything else on the line
            iFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Now we add these values to our output file
            oFile << "(" << X << ", " << Y << ", " << Z << ")\n";

            // Debuggin purposes
            //std::cout << "X: " << X << std::endl;
            //std::cout << "Y: " << Y << std::endl;
            //std::cout << "Z: " << Z << std::endl;
        }

        // If the files is not alreday in the NPC's PathingFileNames, we add it
        // We need this to swap between multiple paths during runtime
        if (std::find(PathingFileNames.begin(), PathingFileNames.end(),ConvertedString) != PathingFileNames.end())
        {
            PathingFileNames.push_back(ConvertedString);
        }
    }
    else
    {
        std::cout << "ERROR OPENING NPC MOVEMENT FILES" << std::endl;
    }
}

void NPC::init(unsigned int* indices, unsigned int numOfVertices, unsigned int numOfIndices)
{
    initializeOpenGLFunctions();

    indexCount = numOfIndices;

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glGenBuffers(1, &mEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * numOfIndices, indices, GL_STATIC_DRAW);

    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * numOfVertices, vertices, GL_STATIC_DRAW);
    glBufferData( GL_ARRAY_BUFFER, mVertices.size()*sizeof( Vertex ), mVertices.data(), GL_DYNAMIC_DRAW );


    // 1rst attribute buffer : vertices
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0  );          // array buffer offset
    glEnableVertexAttribArray(0);

    // 2rd attribute buffer : uvs
    glVertexAttribPointer(1, 2,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)( 6 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

void NPC:: init(GLint matrixUniform)
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

//    // 2nd attribute buffer : colors
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof(Vertex),  (GLvoid*)(3 * sizeof(GLfloat)) );
//    glEnableVertexAttribArray(1);

    // 3rd attribute buffer : uvs
    glVertexAttribPointer(1, 2,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)( 6 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(2);

    glBindVertexArray(1);
}

NPC::~NPC()
{

}

void NPC::draw()
{
    glBindVertexArray( mVAO );
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);



//    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
//    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}
