#-------------------------------------------------
#
# Project created by QtCreator 2012-03-10T00:20:53
#
#-------------------------------------------------

QT       += core gui

TARGET = PGM_PPM_IMAGE_PROCESSING
TEMPLATE = app


SOURCES += main.cpp\
    GUI/mainwindow.cpp \
    GUI/dialogabout.cpp \
    LOGIC/histogram.cpp \
    LOGIC/imagenpgm.cpp \
    LOGIC/imagenppm.cpp \
    CONTROLLER/maincontroller.cpp \
    GUI/resultwindow.cpp \
    LOGIC/imagedcm.cpp \
    DATA_ACCESS/imagefile.cpp

HEADERS  += \
    GUI/mainwindow.h \
    GUI/dialogabout.h \
    LOGIC/histogram.h \
    LOGIC/imagenpgm.h \
    LOGIC/imagenppm.h \
    CONTROLLER/maincontroller.h \
    GUI/resultwindow.h \
    LOGIC/imagedcm.h \
    DATA_ACCESS/imagefile.h

FORMS    += \
    GUI/dialogabout.ui \
    GUI/mainwindow.ui \
    GUI/resultwindow.ui

QMAKE_CXXFLAGS += -DHAVE_CONFIG_H

unix:!macx:!symbian: LIBS += -ldcmimgle
unix:!macx:!symbian: LIBS += -ldcmdata
unix:!macx:!symbian: LIBS += -loflog
unix:!macx:!symbian: LIBS += -lofstd
