#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <QWindow>
#include <QOpenGLFunctions_4_1_Core>
#include <QTimer>
#include <QElapsedTimer>
#include <vector>
#include "visualobject.h"
#include "cube.h"
#include "camera.h"
#include "texture.h"

class QOpenGLContext;
class Shader;
class MainWindow;

/// This inherits from QWindow to get access to the Qt functionality and
// OpenGL surface.
// We also inherit from QOpenGLFunctions, to get access to the OpenGL functions
// This is the same as using "glad" and "glw" from general OpenGL tutorials
class RenderWindow : public QWindow, protected QOpenGLFunctions_4_1_Core
{
    Q_OBJECT
public:
    RenderWindow(const QSurfaceFormat &format, MainWindow *mainWindow);
    ~RenderWindow() override;

    QOpenGLContext *context() { return mContext; }

    void exposeEvent(QExposeEvent *) override;  //gets called when app is shown and resized

    bool mRotate{true};     //Check if triangle should rotate

private slots:
    void render();          //the actual render - function

private:
    Camera mCamera; // Kamera-greie som ble kommentert ut i .h
    void init();            //initialize things we need before rendering

    QOpenGLContext *mContext{nullptr};  //Our OpenGL context
    bool mInitialized{false};

    //Shader *mLightShader{nullptr};

    Shader *mShaderProgram[4]; //holds pointer the GLSL shader program
    Texture *mTextures[4];

    // A new setup function is needed for each new shader
    void SetupPlainShader(int shaderIndex);
    void SetupTextureShader(int shaderIndex);
    void SetupLightShader(int shaderIndex);

    // The matrices system has been changed to now be more robust
    // If there are more uniforms needed the can be added here.
    GLint mMatrixUniform{-1};
    GLint mPmatrixUniform{-1};
    GLint mVmatrixUniform{-1};
    GLint mTextureUniform{-1};
    GLint mAmbientColorUniform{-1};
    GLint mAmbientIntensityUniform{-1};
    GLint mDiffuseIntensityUniform{-1};
    GLint mCameraPositionUniform{-1};
    GLint mLightPositionUniform{-1};


    GLuint mVAO;                        //OpenGL reference to our VAO
    GLuint mVBO;                        //OpenGL reference to our VBO

    void UpdateCurrentUniforms(Shader* currentShader);

    QMatrix4x4 *mPmatrix{nullptr};         // Leksjon 3
    QMatrix4x4 *mVmatrix{nullptr};         // Leksjon 3
    QMatrix4x4 *mMmatrix{nullptr};

    QTimer *mRenderTimer{nullptr};           //timer that drives the gameloop
    QElapsedTimer mTimeStart;               //time variable that reads the calculated FPS

    MainWindow *mMainWindow{nullptr};        //points back to MainWindow to be able to put info in StatusBar

    class QOpenGLDebugLogger *mOpenGLDebugLogger{nullptr};  //helper class to get some clean debug info from OpenGL
    class Logger *mLogger{nullptr};         //logger - Output Log in the application

    cube* newCube = new cube(0.75f);

    ///Helper function that uses QOpenGLDebugLogger or plain glGetError()
    void checkForGLerrors();

    void calculateFramerate();          //as name says

    ///Starts QOpenGLDebugLogger if possible
    void startOpenGLDebugger();

    std::vector<VisualObject*> mObjects;


protected:
    //The QWindow that we inherit from have these functions to capture
    // - mouse and keyboard.
    // Uncomment to use (you also have to make the definitions of
    // these functions in the cpp-file to use them of course!)
    //
    //    void mousePressEvent(QMouseEvent *event) override{}
    //    void mouseMoveEvent(QMouseEvent *event) override{}
    void keyPressEvent(QKeyEvent *event) override;              //the only one we use now
    //    void keyReleaseEvent(QKeyEvent *event) override{}
    //    void wheelEvent(QWheelEvent *event) override{}
};

#endif // RENDERWINDOW_H
