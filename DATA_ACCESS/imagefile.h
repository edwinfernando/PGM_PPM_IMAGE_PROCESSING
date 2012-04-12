//**********************************************************
// INTRODUCCION AL PROCESAMIENTO DIGITAL DE IMÁGENES
// PGM_PPM_IMAGE_PROCESSING_V2
//
// ARCHIVO: imagefile.h
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

#ifndef IMAGEFILE_H
#define IMAGEFILE_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QList>

class ImageFile: public QFile
{
private:
    QList<QString> lectura;

public:
    ImageFile(QString fileName);
    bool readImageContents();
    void printImageContents();
    QList<QString> getImageContents();
};

#endif // IMAGEFILE_H
