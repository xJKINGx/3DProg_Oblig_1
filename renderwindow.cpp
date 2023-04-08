#include "renderwindow.h"
#include <QTimer>
#include <QMatrix4x4>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLDebugLogger>
#include <QKeyEvent>
#include <QStatusBar>
#include <QDebug>

#include <string>

#include "shader.h"
#include "mainwindow.h"
#include "logger.h"
#include "xyz.h"
#include "trophy.h"
#include "house.h"
#include "door.h"
#include "doorcollider.h"
#include "bed.h"
#include "secondscenehouse.h"
#include "trianglesurface.h"
#include "cube.h"
#include "curve.h"
#include "point.h"
#include "npc.h"
#include "player.h"
#include "light.h"
#include "texture.h"
//#include "landscape.h"

Player* player = new Player(0.2f);
house* House = new house(1, QVector3D(1.4f, 2.0f, 1.5f));
door* Door = new door(1, House->m_Position + QVector3D(-1.0f, 0.0f, 0.0f));
doorcollider* DoorCol = new doorcollider(1, House->m_Position + QVector3D(-1.0f, 0.0f, 0.0f));
TriangleSurface* Ground = new TriangleSurface("oblig2Ground.txt", true);
//Landscape* Ground = new Landscape("../3DProg_Oblig_1/textures/Heightmap.jpg");
secondscenehouse* SecondHouse = new secondscenehouse(1, QVector3D{1000.f, 1000.f, 1000.f});
bed* Bed = new bed(1, QVector3D{1000.f, 1000.f, 1000.f});
NPC* npc;
Curve* graph1 = new Curve("graph.txt", true);
Curve* graph2 = new Curve("4610CurvePoints.txt", true);
Light* light = new Light();
Texture* obamnaTex;

RenderWindow::RenderWindow(const QSurfaceFormat &format, MainWindow *mainWindow)
    : mContext(nullptr), mInitialized(false), mMainWindow(mainWindow)

{
    //This is sent to QWindow:
    setSurfaceType(QWindow::OpenGLSurface);
    setFormat(format);
    //Make the OpenGL context
    mContext = new QOpenGLContext(this);
    //Give the context the wanted OpenGL format (v4.1 Core)
    mContext->setFormat(requestedFormat());
    if (!mContext->create()) {
        delete mContext;
        mContext = nullptr;
        qDebug() << "Context could not be made - quitting this application";
    }

    mPmatrix = new QMatrix4x4{};         // Leksjon 3
    mVmatrix = new QMatrix4x4{};         // Leksjon 3

    //Make the gameloop timer:
    mRenderTimer = new QTimer(this);



    //mObjects.push_back(new XYZ());
    //mObjects.push_back(new TriangleSurface("vertices.txt", false));
    //mObjects.push_back(newCube);

    // Oblig 2 - Oppgave 4.4.4
    //mObjects.push_back(new Curve("graph.txt", true));
    //mObjects.push_back(new point("points.txt", true));

    // Oblig 2 - Oppgave 4.6.10
    //mObjects.push_back(new Curve("4610CurvePoints.txt", true));
    //mObjects.push_back(new point("4610points.txt", true));

    mObjects.push_back(player);

    //    Curve* GroundGraph = new Curve("graph.txt", true);
        mObjects.push_back(Ground);
        // mObjects.push_back(new NPC());

        // Y-verdiene er unødvendige siden de blir overskrevet av bakken uansett
        mObjects.push_back(new trophy(0.3, QVector3D(3.0f, 0.0f, -5.0f)));
        mObjects.push_back(new trophy(0.3, QVector3D(1.0f, 0.0f, -3.0f)));
        mObjects.push_back(new trophy(0.3, QVector3D(-6.0f, 0.0f, -1.0f)));
        mObjects.push_back(new trophy(0.3, QVector3D(-2.0f, 0.0f, -5.0f)));
        mObjects.push_back(new trophy(0.3, QVector3D(-5.0f, 0.0f, -4.0f)));
        mObjects.push_back(new trophy(0.3, QVector3D(3.0f, 0.0f, 0.0f)));

        mObjects.push_back(House);
        mObjects.push_back(Door);
        mObjects.push_back(DoorCol);

    //    mObjects.push_back(new doorcollider(1));

        mObjects.push_back(SecondHouse);
        mObjects.push_back(Bed);
        mObjects.push_back(graph1);
        mObjects.push_back(graph2);
        //mObjects.push_back(npc);
        mObjects.push_back(light);
}

RenderWindow::~RenderWindow()
{
    //cleans up the GPU memory
    glDeleteVertexArrays( 1, &mVAO );
    glDeleteBuffers( 1, &mVBO );
}

// Sets up the general OpenGL stuff and the buffers needed to render a triangle
void RenderWindow::init()
{
    //Get the instance of the utility Output logger
    //Have to do this, else program will crash (or you have to put in nullptr tests...)
    mLogger = Logger::getInstance();

    GLfloat bababooey = 1.0f;


    //Connect the gameloop timer to the render function:
    //This makes our render loop
    connect(mRenderTimer, SIGNAL(timeout()), this, SLOT(render()));
    //********************** General OpenGL stuff **********************

    //The OpenGL context has to be set.
    //The context belongs to the instanse of this class!
    if (!mContext->makeCurrent(this)) {
        mLogger->logText("makeCurrent() failed", LogType::REALERROR);
        return;
    }

    //just to make sure we don't init several times
    //used in exposeEvent()
    if (!mInitialized)
        mInitialized = true;

    //must call this to use OpenGL functions
    initializeOpenGLFunctions();

    //Print render version info (what GPU is used):
    //Nice to see if you use the Intel GPU or the dedicated GPU on your laptop
    // - can be deleted
    mLogger->logText("The active GPU and API:", LogType::HIGHLIGHT);
    std::string tempString;
    tempString += std::string("  Vendor: ") + std::string((char*)glGetString(GL_VENDOR)) + "\n" +
            std::string("  Renderer: ") + std::string((char*)glGetString(GL_RENDERER)) + "\n" +
            std::string("  Version: ") + std::string((char*)glGetString(GL_VERSION));
    mLogger->logText(tempString);

    //Start the Qt OpenGL debugger
    //Really helpfull when doing OpenGL
    //Supported on most Windows machines - at least with NVidia GPUs
    //reverts to plain glGetError() on Mac and other unsupported PCs
    // - can be deleted
    startOpenGLDebugger();

    //general OpenGL stuff:
    glEnable(GL_DEPTH_TEST);            //enables depth sorting - must then use GL_DEPTH_BUFFER_BIT in glClear
    //    glEnable(GL_CULL_FACE);       //draws only front side of models - usually what you want - test it out!
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);    //gray color used in glClear GL_COLOR_BUFFER_BIT

    //Compile shaders:
    //NB: hardcoded path to files! You have to change this if you change directories for the project.
    //Qt makes a build-folder besides the project folder. That is why we go down one directory
    // (out of the build-folder) and then up into the project folder.
    mShaderProgram[0] = new Shader("../3DProg_Oblig_1/plainshader.vert", "../3DProg_Oblig_1/plainshader.frag");
    mShaderProgram[1] = new Shader("../3DProg_Oblig_1/texshader.vert", "../3DProg_Oblig_1/texshader.frag");
    //mLightShader = new Shader("../3DProg_Oblig_1/lightshader.vert", "../3DProg_Oblig_1/lightshader.frag");


    // Get the matrixUniform location from the shader
    // This has to match the "matrix" variable name in the vertex shader
    // The uniform is used in the render() function to send the model matrix to the shader
    SetupPlainShader(0);
    SetupTextureShader(1);
    mCamera.init(mPmatrixUniform0, mVmatrixUniform0);



    for (auto it=mObjects.begin(); it != mObjects.end(); it++)
    {
        (*it)->init(mMatrixUniform0);
    }

    obamnaTex = new Texture((char*)("../3DProg_Oblig_1/textures/31727014.jpg"));
    obamnaTex->LoadTexture();



    npc = new NPC(mMatrixUniform1);
    //mObjects.push_back(npc);

    glBindVertexArray(0);       //unbinds any VertexArray - good practice
    glPointSize(bababooey);

    mCamera.init(mPmatrixUniform0, mVmatrixUniform0);
    mCamera.perspective(60, 4.0/3.0, 0.1, 1000.0);

    mCamera.lookAt(player->m_Position - QVector3D{0.0f, -5.0f, 5.0f}, player->m_Position, QVector3D{0,1,0});
}

// Called each frame - doing the rendering!!!
void RenderWindow::render()
{
    mTimeStart.restart(); //restart FPS clock
    mContext->makeCurrent(this); //must be called every frame (every time mContext->swapBuffers is called)

    initializeOpenGLFunctions();    //must call this every frame it seems...

    //clear the screen for each redraw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //what shader to use


    glUseProgram(mShaderProgram[0]->getProgram() );

    mCamera.update(mVmatrixUniform0, mPmatrixUniform0);

    for (auto it=mObjects.begin(); it != mObjects.end(); it++)
    {
        (*it)->checkCollision(DoorCol);
        (*it)->checkCollision(player); // For trophies, will be changed to player later
    }

    for (auto it=mObjects.begin(); it != mObjects.end(); it++)
    {
        (*it)->draw();
    }

    glUseProgram(mShaderProgram[1]->getProgram() );

    glUniform1i(mTextureUniform, 0);
    obamnaTex->UseTexture();

    mCamera.update(mVmatrixUniform1, mPmatrixUniform1);

    npc->draw();

    calculateFramerate();
    checkForGLerrors(); //using our expanded OpenGL debugger to check if everything is OK.
    mContext->swapBuffers(this);

//    if (mRotate)
//    {
//        Door->Rotate(true);
//        newCube->Rotate(true);
//    }
//    else
//    {
//        newCube->Rotate(false);
//    }

    if (player->bSecondScene)
    {
        mCamera.init(mPmatrixUniform0, mVmatrixUniform0);
        mCamera.perspective(60, 4.0/3.0, 0.1, 1000.0);
        mCamera.lookAt(QVector3D{993,1005,994}, SecondHouse->m_Position, QVector3D{0,1,0});
    }
    else
    {
        mCamera.init(mPmatrixUniform0, mVmatrixUniform0);
        mCamera.perspective(60, 4.0/3.0, 0.1, 1000.0);
        mCamera.lookAt(player->m_Position - QVector3D{0.0f, -5.0f, 5.0f}, player->m_Position, QVector3D{0,1,0});
    }

//    mLogger->logText("NPC X: " + std::to_string(npc->m_Position[0]));
//    mLogger->logText("NPC Y: " + std::to_string(npc->m_Position[1]));
//    mLogger->logText("NPC Z: " + std::to_string(npc->m_Position[2]));

    npc->FollowPath(graph1, graph2);
}

//This function is called from Qt when window is exposed (shown)
// and when it is resized
//exposeEvent is a overridden function from QWindow that we inherit from
void RenderWindow::exposeEvent(QExposeEvent *)
{
    //if not already initialized - run init() function - happens on program start up
    if (!mInitialized)
        init();

    //This is just to support modern screens with "double" pixels (Macs and some 4k Windows laptops)
    const qreal retinaScale = devicePixelRatio();

    //Set viewport width and height to the size of the QWindow we have set up for OpenGL
    glViewport(0, 0, static_cast<GLint>(width() * retinaScale), static_cast<GLint>(height() * retinaScale));

    //If the window actually is exposed to the screen we start the main loop
    //isExposed() is a function in QWindow
    if (isExposed())
    {
        //This timer runs the actual MainLoop
        //16 means 16ms = 60 Frames pr second (should be 16.6666666 to be exact...)
        mRenderTimer->start(16);
        mTimeStart.start();
    }
}

//The way this function is set up is that we start the clock before doing the draw call,
// and check the time right after it is finished (done in the render function)
//This will approximate what framerate we COULD have.
//The actual frame rate on your monitor is limited by the vsync and is probably 60Hz
void RenderWindow::calculateFramerate()
{
    long nsecElapsed = mTimeStart.nsecsElapsed();
    static int frameCount{0};                       //counting actual frames for a quick "timer" for the statusbar

    if (mMainWindow)            //if no mainWindow, something is really wrong...
    {
        ++frameCount;
        if (frameCount > 30)    //once pr 30 frames = update the message == twice pr second (on a 60Hz monitor)
        {
            //showing some statistics in status bar
            mMainWindow->statusBar()->showMessage(" Time pr FrameDraw: " +
                                                  QString::number(nsecElapsed/1000000.f, 'g', 4) + " ms  |  " +
                                                  "FPS (approximated): " + QString::number(1E9 / nsecElapsed, 'g', 7));
            frameCount = 0;     //reset to show a new message in 30 frames
        }
    }
}

//Uses QOpenGLDebugLogger if this is present
//Reverts to glGetError() if not
void RenderWindow::checkForGLerrors()
{
    if(mOpenGLDebugLogger)  //if our machine got this class to work
    {
        const QList<QOpenGLDebugMessage> messages = mOpenGLDebugLogger->loggedMessages();
        for (const QOpenGLDebugMessage &message : messages)
        {
            if (!(message.type() == message.OtherType)) // get rid of uninteresting "object ...
                                                        // will use VIDEO memory as the source for
                                                        // buffer object operations"
                // valid error message:
                mLogger->logText(message.message().toStdString(), LogType::REALERROR);
        }
    }
    else
    {
        GLenum err = GL_NO_ERROR;
        while((err = glGetError()) != GL_NO_ERROR)
        {
            mLogger->logText("glGetError returns " + std::to_string(err), LogType::REALERROR);
            switch (err) {
            case 1280:
                mLogger->logText("GL_INVALID_ENUM - Given when an enumeration parameter is not a "
                                "legal enumeration for that function.");
                break;
            case 1281:
                mLogger->logText("GL_INVALID_VALUE - Given when a value parameter is not a legal "
                                "value for that function.");
                break;
            case 1282:
                mLogger->logText("GL_INVALID_OPERATION - Given when the set of state for a command "
                                "is not legal for the parameters given to that command. "
                                "It is also given for commands where combinations of parameters "
                                "define what the legal parameters are.");
                break;
            }
        }
    }
}

//Tries to start the extended OpenGL debugger that comes with Qt
//Usually works on Windows machines, but not on Mac...
void RenderWindow::startOpenGLDebugger()
{
    QOpenGLContext * temp = this->context();
    if (temp)
    {
        QSurfaceFormat format = temp->format();
        if (! format.testOption(QSurfaceFormat::DebugContext))
            mLogger->logText("This system can not use QOpenGLDebugLogger, so we revert to glGetError()",
                             LogType::HIGHLIGHT);

        if(temp->hasExtension(QByteArrayLiteral("GL_KHR_debug")))
        {
            mLogger->logText("This system can log extended OpenGL errors", LogType::HIGHLIGHT);
            mOpenGLDebugLogger = new QOpenGLDebugLogger(this);
            if (mOpenGLDebugLogger->initialize()) // initializes in the current context
                mLogger->logText("Started Qt OpenGL debug logger");
        }
    }
}

//Event sent from Qt when program receives a keyPress
// NB - see renderwindow.h for signatures on keyRelease and mouse input
void RenderWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        mMainWindow->close();       //Shuts down the whole program
    } else
    {
        player->Move(event);
        newCube->Move(0.0f,0.0f,0.0f, event);
    }
}

void RenderWindow::SetupPlainShader(int shaderIndex)
{
    mMatrixUniform0  = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "matrix" );
    mPmatrixUniform0 = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "pMatrix" );
    mVmatrixUniform0 = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "vMatrix" );

    std::cout << "M0: " << mMatrixUniform0 << std::endl;
    std::cout << "P0: " << mPmatrixUniform0 << std::endl;
    std::cout << "V0: " << mVmatrixUniform0 << std::endl;
}

void RenderWindow::SetupTextureShader(int shaderIndex)
{
    mMatrixUniform1  = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "matrix" );
    mPmatrixUniform1 = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "pMatrix" );
    mVmatrixUniform1 = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "vMatrix" );
    mTextureUniform  = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "theTexture");

    std::cout << "M1: " << mMatrixUniform1 << std::endl;
    std::cout << "P1: " << mPmatrixUniform1 << std::endl;
    std::cout << "V1: " << mVmatrixUniform1 << std::endl;
    std::cout << "T: " << mTextureUniform<< std::endl;
}
