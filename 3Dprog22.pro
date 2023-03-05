QT          += core gui widgets opengl

TEMPLATE    = app
CONFIG      += c++17

TARGET      = 3D-programmering

SOURCES += main.cpp \
    bed.cpp \
    camera.cpp \
    cube.cpp \
    curve.cpp \
    door.cpp \
    doorcollider.cpp \
    house.cpp \
    logger.cpp \
    mainwindow.cpp \
    npc.cpp \
    point.cpp \
    positioncomponent.cpp \
    renderwindow.cpp \
    shader.cpp \
    trianglesurface.cpp \
    trophy.cpp \
    vertex.cpp \
    visualobject.cpp \
    xyz.cpp

HEADERS += \
    bed.h \
    camera.h \
    cube.h \
    curve.h \
    door.h \
    doorcollider.h \
    house.h \
    logger.h \
    mainwindow.h \
    npc.h \
    point.h \
    positioncomponent.h \
    renderwindow.h \
    shader.h \
    trianglesurface.h \
    trophy.h \
    vertex.h \
    visualobject.h \
    xyz.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    plainshader.frag \
    plainshader.vert
