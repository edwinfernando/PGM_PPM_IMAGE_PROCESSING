/*
  INTRODUCCION AL PROCESAMIENTO DIGITAL DE IMÁGENES
  PGM_PPM_IMAGE_PROCESSING_V2
  Archivo:          histogram.cpp
  Fecha creacion:   Marzo de 2012
  Autores:          Gustavo Adolfo Rodriguez    0932979
                    Edwin Fernando Muñoz        0910398

  UNIVERSIDAD DEL VALLE
  ESCUELA DE INGENIERIA DE SISTEMAS Y COMPUTACION
*/

#include "histogram.h"
QTextStream cout(stdout);

Histogram::Histogram(ImagenPGM *imagen)
{
    int nColumnas=imagen->getColumnNumber();
    int nFilas=imagen->getRowNumber();
    intensidad=imagen->getColorDensity()+1;
    int **matrizImagen=imagen->getMatrix();
    int totalNumberPixels = nFilas*nColumnas;

    relativeFrecuency= new double[intensidad];
    for (int i=0; i < intensidad; i++)
        relativeFrecuency[i]=0;

    for(int i=0; i<nFilas; i++){
        for(int j=0; j<nColumnas; j++){
            relativeFrecuency[matrizImagen[i][j]]++;
        }
    }
    for (int i=0; i < intensidad; i++){
        relativeFrecuency[i]=(relativeFrecuency[i]/totalNumberPixels)*100;
    }

    generateMatrix();
}

void Histogram::generateMatrix(){

    matrizHistograma = new int*[intensidad];
    for (int i=0; i < intensidad; i++)
        matrizHistograma[i]=new int[intensidad];

    double maxFreq=findMaxRelativeFrecuency();

    for(int i=0; i<intensidad; i++){
        for(int j=0; j<intensidad; j++){
            if(intensidad-i<=((relativeFrecuency[j]*intensidad)/maxFreq)){
                matrizHistograma[i][j]=0;

            }else{
                matrizHistograma[i][j]=1;
            }
        }
    }
}

double Histogram::findMaxRelativeFrecuency(){
    QList<double> frequencies;
    for (int i=0; i<intensidad; i++){
        frequencies.append(relativeFrecuency[i]);
    }
    qSort(frequencies.begin(), frequencies.end());
    return frequencies.last();
}

ImagenPGM* Histogram::getHistogram(){

    return new ImagenPGM ("P2","#Histogram", intensidad, intensidad, 1, matrizHistograma);
}
