#include "positioncomponent.h"


positionComponent::positionComponent()
{
    mMatrix.setToIdentity();
}


void positionComponent::setPosition(QVector3D offset)
{
//    m_Position = offset;
//    getTranslateMatrix(&mMatrix);
//    mMatrix.lookAt(m_Position, m_Position + worldFront, worldUp);


    m_Position = offset;

//    auto V4D = mMatrix.column(3);
//    V4D.setX(offset.x());
//    V4D.setY(offset.y());
//    V4D.setZ(offset.z());
//    mMatrix.setColumn(3, V4D);
}
