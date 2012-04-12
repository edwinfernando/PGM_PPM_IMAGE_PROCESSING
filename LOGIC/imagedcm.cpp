//**********************************************************
// INTRODUCCION AL PROCESAMIENTO DIGITAL DE IMÁGENES
// PGM_PPM_IMAGE_PROCESSING_V2
//
// ARCHIVO: imagedcm.h
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

#include "imagedcm.h"

ImageDCM::ImageDCM()
{
}

bool ImageDCM::convertToBMP(const char *filename)
{
    QString appSentence = "dcmp2pgm "+QString(filename)+" from_dicom.pgm";

    if(system(appSentence.toAscii())==0){
        QImage *rawPGM = new QImage("from_dicom.pgm");
        rawPGM->save("P2.pgm");
        return true;
    }
    else{
        return false;
    }
}
