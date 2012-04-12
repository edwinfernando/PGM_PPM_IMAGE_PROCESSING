//**********************************************************
// INTRODUCCION AL PROCESAMIENTO DIGITAL DE IMÁGENES
// PGM_PPM_IMAGE_PROCESSING_V2
//
// ARCHIVO: imagenpgm.h
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

#ifndef IMAGENPGM_H
#define IMAGENPGM_H

#include <QList>
#include <QString>
#include <QTextStream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QtAlgorithms>
#include <math.h>

class ImagenPGM
{
    QString identificacion, comentario;
    int rowNumber, columnNumber, colorDensity;
    int **matrizImagen;
    int ***matrizImagenP;
    int *lut;

public:

    ImagenPGM(QList<QString> lectura);
    ImagenPGM(QString id,
                     QString coment,
                     int filas,
                     int columnas,
                     int colorDensity,
                     int **matriz);

    int** getMatrix();
    int getRowNumber();
    int getColumnNumber();
    int getColorDensity();
    void exportar(QTextStream &fSalida);
    ImagenPGM *reducirTamano();
    ImagenPGM *reducirIntensidad(int bits);
};

#endif // IMAGENPGM_H
