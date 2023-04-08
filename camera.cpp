#include "camera.h"

Camera::Camera() : mEye{0,0,-15}
{
    mPmatrix.setToIdentity();
    mVmatrix.setToIdentity();
}

void Camera::init(GLint pMatrixUniform, GLint vMatrixUniform)
{
    mPmatrix.setToIdentity();
    mVmatrix.setToIdentity();
    mPmatrixUniform = pMatrixUniform;
    mVmatrixUniform = vMatrixUniform;
}

void Camera::perspective(int degrees, double aspect, double nearplane, double farplane)
{
    mPmatrix.perspective(degrees, aspect, nearplane, farplane);
}

void Camera::lookAt(const QVector3D &eye, const QVector3D &at, const QVector3D &up)
{
    // eye = camera position, at = what to look at, aka. the target, up idk
    mVmatrix.lookAt(eye, at, up);
}

void Camera::update(GLint vUniform, GLint pUniform)
{
    initializeOpenGLFunctions();
    mPmatrixUniform = pUniform;
    mVmatrixUniform = vUniform;
    glUniformMatrix4fv(pUniform, 1, GL_FALSE, mPmatrix.constData());
    glUniformMatrix4fv(vUniform, 1, GL_FALSE, mVmatrix.constData());
}
