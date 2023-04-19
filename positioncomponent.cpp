#include "positioncomponent.h"


positionComponent::positionComponent()
{
    mMatrix.setToIdentity();
}


void positionComponent::setPosition(QVector3D targetPos)
{
    QVector4D position = mMatrix.column(3);
    position = QVector4D(targetPos.x(),targetPos.y(),targetPos.z(),position.w());
    mMatrix.setColumn(3, position);
    m_Position[0] = mMatrix.column(3).x();
    m_Position[1] = mMatrix.column(3).y();
    m_Position[2] = mMatrix.column(3).z();
}
