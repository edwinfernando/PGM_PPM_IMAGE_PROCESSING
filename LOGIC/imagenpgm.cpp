/*
  INTRODUCCION AL PROCESAMIENTO DIGITAL DE IMÁGENES
  Actividad de Programacion 2
  Archivo:          imagenpgm.cpp
  Fecha creacion:   Marzo de 2012
  Autores:          Gustavo Adolfo Rodriguez    0932979
                    Edwin Fernando Muñoz        0910398

  UNIVERSIDAD DEL VALLE
  ESCUELA DE INGENIERIA DE SISTEMAS Y COMPUTACION
*/

#include "imagenpgm.h"


ImagenPGM::ImagenPGM(QList<QString> lectura)
{
    identificacion=lectura.at(0);
    comentario=lectura.at(1);
    columnNumber=lectura.at(2).section(' ',0,0).toInt();
    rowNumber=lectura.at(2).section(' ',1,1).toInt();
    colorDensity=lectura.at(3).toInt();

    matrizImagen = new int*[rowNumber];
    for (int i=0; i < rowNumber; i++)
        matrizImagen[i]=new int[columnNumber];

    int aux=4;
    for(int i=0; i<rowNumber; i++){
        for(int j=0; j<columnNumber; j++){
            matrizImagen[i][j]=lectura[i+j+aux].toInt();
        }
        aux=aux+columnNumber-1;
    }

}

ImagenPGM::ImagenPGM(QString id, QString coment, int filas, int columnas, int intensidad, int **matriz){
    this->identificacion=id;
    this->comentario=coment;
    this->rowNumber=filas;
    this->columnNumber=columnas;
    this->colorDensity=intensidad;
    this->matrizImagen=matriz;
}

void ImagenPGM::exportar(QTextStream &fSalida){

    fSalida<<identificacion<<endl;
    fSalida<<comentario<<endl;
    fSalida<<columnNumber<<" "<<rowNumber<<endl;
    fSalida<<colorDensity<<endl;

    for(int i=0; i<rowNumber; i++){
        for(int j=0; j<columnNumber; j++){
            fSalida<<matrizImagen[i][j]<<endl;
        }
    }
}

ImagenPGM* ImagenPGM::reducirTamano(){

    int r=2;
    int nColumnasReducida=columnNumber/r;
    int nFilasReducida=rowNumber/r;

    // inicializacion
    int **imagenReducida = new int*[nFilasReducida];
    for (int i=0; i < nFilasReducida; i++)
        imagenReducida[i]=new int[nColumnasReducida];

    // Proceso de reduccion
    for(int i=0; i<nFilasReducida; i++){
        for(int j=0; j<nColumnasReducida; j++){
            imagenReducida[i][j]=matrizImagen[i*r][j*r];
        }
    }

    // creacion de nueva imagen reducida

    ImagenPGM *resultado = new ImagenPGM (identificacion,
                                          comentario,
                                          nFilasReducida,
                                          nColumnasReducida,
                                          colorDensity,
                                          imagenReducida);

    return resultado;
}

ImagenPGM* ImagenPGM::reducirIntensidad(int bits){

    int intensidadNueva=(int)(pow(2,bits)-1);

    int **imagenIntensidad = new int*[rowNumber];
    for (int i=0; i < rowNumber; i++)
        imagenIntensidad[i]=new int[columnNumber];

    int divisor = (colorDensity+1)/(intensidadNueva+1);

    for(int i=0; i<rowNumber; i++){
        for(int j=0; j<columnNumber; j++){

            imagenIntensidad[i][j]=floor(matrizImagen[i][j]/divisor);

        }
    }

    // creacion de nueva imagen intensidad reducida

    ImagenPGM *resultado = new ImagenPGM (identificacion,
                                          comentario,
                                          rowNumber,
                                          columnNumber,
                                          intensidadNueva,
                                          imagenIntensidad);

    return resultado;
}

int ImagenPGM::getColorDensity(){
    return colorDensity;
}

int ImagenPGM::getColumnNumber(){
    return columnNumber;
}

int ImagenPGM::getRowNumber(){
    return rowNumber;
}

int** ImagenPGM::getMatrix(){
    return matrizImagen;
}
