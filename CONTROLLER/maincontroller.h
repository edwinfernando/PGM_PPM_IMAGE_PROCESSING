//**********************************************************
// INTRODUCCION AL PROCESAMIENTO DIGITAL DE IMÁGENES
// PGM_PPM_IMAGE_PROCESSING_V2
//
// ARCHIVO: maincontroller.h
//
// FECHA INICIACION: Marzo de 2012
//
// AUTORES:
// Gustavo Adolfo Rodriguez         0932979-3743
// gustalibreros@hotmail.com
//
// Edwin Fernando Muñoz             0910398-3743
// edwinfernandomudelgado@hotmail.com
//
// ESCUELA DE INGENIERIA DE SISTEMAS Y COMPUTACION
// UNIVERSIDAD DEL VALLE
//**********************************************************

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

// Qt include
#include <QImage>
#include <QString>

// Project include
#include "LOGIC/imagenpgm.h"
#include "LOGIC/imagenppm.h"
#include "LOGIC/histogram.h"
#include "DATA_ACCESS/imagefile.h"
#include "LOGIC/imagedcm.h"

class MainController
{
private:

    ImagenPGM *imagenPGM;
    ImagenPPM *imagenPPM;
    QImage *qImage;

    void exportTempImage(ImagenPGM *imagen, QString filename);
    void exportTempImage(ImagenPPM *imagen, QString filename);

public:

    MainController();
    ~MainController();

    bool loadImage(QString filename);
    QImage* pixelDensityChanged(int density);
    QImage* colorDensityChanged(int intensidad);
    QImage* convertGrayscale();
    QImage* generateHistogram();
    void newJob();

    //GETTERS
    QImage* getImage();
    QString getImageType();
    QString getImageWide();
    QString getImageHigh();
    QString getColorDensity();

};

#endif // MAINCONTROLLER_H
