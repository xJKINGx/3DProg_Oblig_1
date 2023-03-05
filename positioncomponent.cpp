#include "positioncomponent.h"

positionComponent::positionComponent()
{
    mMatrix.setToIdentity();
}


void positionComponent::setPosition(QVector3D offset)
{
    m_Position = offset;
    getTranslateMatrix(&mMatrix);
    mMatrix.lookAt(m_Position, m_Position + worldFront, worldUp);
}
