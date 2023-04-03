#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H
#include "qmatrix4x4.h"
#include <QVector3D>

enum Direction {
    // X
    LEFT,
    RIGHT,
    // Y
    UP,
    DOWN,
    // Z
    FORWARD,
    BACKWARD

};


class positionComponent {
public:
    // Keyboard

    QVector3D m_Position;
    QVector3D right;    // local x
    QVector3D up;        // local y
    QVector3D front;    // local z
    const QVector3D worldRight = QVector3D(1.0f, 0.0f, 0.0f);
    const QVector3D worldUp = QVector3D(0.0f, 1.0f, 0.0f);
    const QVector3D worldFront = QVector3D(0.0f, 0.0f, 1.0f);

    float yaw;
    float pitch;
    float roll;

    QVector3D rotation;
    QVector3D scale;

    // Should these be protected?
    QMatrix4x4 mMatrix; // position i guess
    //matrix.setToIdentity();
    //glm::mat4 rotation = glm::mat4(1.0f);

    positionComponent();

    // Realtime movement
    void translateLocal(Direction direction);
    void translateLocal(QVector3D offset, float deltaTime);
    void translate(Direction direction, float deltaTime);
    void translate(float inX, float inY, float inZ, float deltaTime);

    // Set position
    void setPosition(QVector3D offset);

    void setRotation(float angle, QVector3D axis);

    float moveSpeed{};
    bool useLocal{ true };

    // Gets
    QMatrix4x4 getTranslateMatrix(QMatrix4x4 *matrise) {
    /*    matrix = glm::mat4(1.0f);
        matrix = glm::translate(matrix, position);

        matrix = glm::scale(matrix, scale);
        return matrix;*/
        matrise->lookAt(m_Position, m_Position + worldFront, worldUp);
        return *matrise;
    }

protected:

    //QMatrix4x4 matrix;
    //glm::mat4 position;
    //glm::mat4 rotation;
};

#endif // POSITIONCOMPONENT_H
