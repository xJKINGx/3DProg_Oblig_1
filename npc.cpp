#include "npc.h"
#include <iostream>

NPC::NPC()
{
    FetchCoordinates("graph.txt");
}

void NPC::FollowPath(Curve path, TriangleSurface ground)
{

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

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof(Vertex),  (GLvoid*)(3 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(1);

    // 3rd attribute buffer : uvs
    glVertexAttribPointer(2, 2,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)( 6 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
}

NPC::~NPC()
{

}

void NPC::draw()
{
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}
