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
    light.cpp \
    logger.cpp \
    mainwindow.cpp \
    npc.cpp \
    perlinnoise.cpp \
    player.cpp \
    point.cpp \
    positioncomponent.cpp \
    ppm.cpp \
    renderwindow.cpp \
    secondscenehouse.cpp \
    shader.cpp \
    stb_image.cpp \
    texture.cpp \
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
    light.h \
    logger.h \
    mainwindow.h \
    npc.h \
    perlinnoise.h \
    player.h \
    point.h \
    positioncomponent.h \
    ppm.h \
    renderwindow.h \
    secondscenehouse.h \
    shader.h \
    stb_image.h \
    texture.h \
    trianglesurface.h \
    trophy.h \
    vertex.h \
    visualobject.h \
    xyz.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    lightshader.frag \
    lightshader.vert \
    litobjectshader.frag \
    litobjectshader.vert \
    plainshader.frag \
    plainshader.vert \
    texshader.frag \
    texshader.vert
