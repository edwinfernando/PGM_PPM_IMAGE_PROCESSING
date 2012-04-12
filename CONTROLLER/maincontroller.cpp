//**********************************************************
// INTRODUCCION AL PROCESAMIENTO DIGITAL DE IMÁGENES
// PGM_PPM_IMAGE_PROCESSING_V2
//
// ARCHIVO: maincontroller.cpp
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

#include "maincontroller.h"

MainController::MainController(){
    this->imagenPGM=0;
    this->imagenPPM=0;
    this->qImage=0;
}

MainController::~MainController(){

}

// LOAD IMAGE
bool MainController::loadImage(QString filename){

    if(!filename.contains("."))
    {
        ImageDCM *imageDCM = new ImageDCM();

        if(imageDCM->convertToBMP(filename.toAscii()))
        {
            qImage=new QImage(filename+".pgm");
            return true;
        }else{
            return false;
        }

    }else{
        ImageFile archivo(filename);        // Crear el objeto tipo Archivo
        if(archivo.readImageContents()){
            QString imageType = filename.right(3).toUpper();    // Obtener la extension de la imagen
            qImage=new QImage(filename);

            if(imageType == "PPM"){
                imagenPPM = new ImagenPPM(archivo.getImageContents());
            }else{
                imagenPGM = new ImagenPGM(archivo.getImageContents());
            }
            return true;
        }else{
            return false;
        }
    }
}

// GETTERS

QImage* MainController::getImage(){
    return qImage;
}

QString MainController::getImageType(){
    if (imagenPPM !=0) {
        return "PPM";
    } else {
        return "PGM";
    }
}

QString MainController::getImageWide(){
    if (imagenPPM !=0) {
        return QString::number(imagenPPM->getColumnNumber());
    } else {
        return QString::number(imagenPGM->getColumnNumber());
    }
}

QString MainController::getImageHigh(){
    if (imagenPPM !=0) {
        return QString::number(imagenPPM->getRowNumber());
    } else {
        return QString::number(imagenPGM->getRowNumber());
    }
}

QString MainController::getColorDensity(){
    if (imagenPPM !=0) {
        return QString::number(imagenPPM->getColorDensity());
    } else {
        return QString::number(imagenPGM->getColorDensity());
    }
}

// Image Transfomations
QImage* MainController::pixelDensityChanged(int density){

    if(imagenPPM != 0){
        ImagenPPM* imagenPPMTransformed;
        if(density==50)
        {
            imagenPPMTransformed=imagenPPM->reducirTamano();
        }else{
            if(density==25){
                imagenPPMTransformed=imagenPPM->reducirTamano()->reducirTamano();
            }else
                imagenPPMTransformed=imagenPPM->reducirTamano()->reducirTamano()->reducirTamano();
        }
        exportTempImage(imagenPPMTransformed, "tem.ppm~");   // Imagen transformada se guarda como un Archivo
        return new QImage("tem.ppm~");

    }else{
        ImagenPGM* imagenPGMTransformed;
        if(density==50)
        {
            imagenPGMTransformed=imagenPGM->reducirTamano();
        }else{
            if(density==25){
                imagenPGMTransformed=imagenPGM->reducirTamano()->reducirTamano();
            }else
                imagenPGMTransformed=imagenPGM->reducirTamano()->reducirTamano()->reducirTamano();
        }
        exportTempImage(imagenPGMTransformed, "tem.pgm~");  // Imagen transformada se guarda como un Archivo
        return new QImage("tem.pgm~");
    }
}

QImage* MainController::colorDensityChanged(int intensidad){

    if(imagenPPM != 0){
        ImagenPPM *imagenPPMTransformed=imagenPPM->reducirIntensidad(intensidad);
        exportTempImage(imagenPPMTransformed, "tem.ppm~");  // Se guarda como Archivo
        return new QImage("tem.ppm~");

    }else{
        ImagenPGM *imagenPGMTransformed=imagenPGM->reducirIntensidad(intensidad);
        exportTempImage(imagenPGMTransformed, "tem.pgm~");  // Se guarda como Archivo
        return new QImage("tem.pgm~");
    }

}

QImage* MainController::convertGrayscale(){
    ImagenPGM *imagenPGMTransformed=imagenPPM->convertirGris(1);
    exportTempImage(imagenPGMTransformed, "tem.pgm~");  // Se guarda como Archivo
    return new QImage("tem.pgm~");
}

QImage* MainController::generateHistogram(){

    Histogram histogram(imagenPGM);
    ImagenPGM *imagenPGMTransformed=histogram.getHistogram();
    exportTempImage(imagenPGMTransformed, "tem.pgm~");
    return new QImage("tem.pgm~");
}


// Other Methods
void MainController::exportTempImage(ImagenPGM *imagen, QString filename){
    QFile temp(filename);
    if(temp.open(QFile::WriteOnly)){
        QTextStream fSalida(&temp);
        imagen->exportar(fSalida);
    }
}

void MainController::exportTempImage(ImagenPPM *imagen, QString filename){
    QFile temp(filename);
    if(temp.open(QFile::WriteOnly)){
        QTextStream fSalida(&temp);
        imagen->exportar(fSalida);
    }
}

void MainController::newJob(){

    imagenPGM=0;
    imagenPPM=0;
    qImage=0;
}


