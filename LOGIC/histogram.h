//**********************************************************
// INTRODUCCION AL PROCESAMIENTO DIGITAL DE IMÁGENES
// PGM_PPM_IMAGE_PROCESSING_V2
//
// ARCHIVO: histogram.h
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

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "imagenpgm.h"

//

//
class Histogram
{

public:

    Histogram(ImagenPGM *imagen);
    ImagenPGM *getHistogram();

private:

    double *relativeFrecuency;
    int **matrizHistograma;
    int intensidad;

    void generateMatrix();
    double findMaxRelativeFrecuency();

};
#endif
