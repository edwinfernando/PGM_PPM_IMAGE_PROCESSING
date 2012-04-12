//**********************************************************
// INTRODUCCION AL PROCESAMIENTO DIGITAL DE IMÁGENES
// PGM_PPM_IMAGE_PROCESSING_V2
//
// ARCHIVO: resultwindow.h
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

#ifndef EXPORT_H
#define EXPORT_H

#include <QDialog>
#include <QFileDialog>
#include <QPixmap>

namespace Ui {
class Export;
}

class ResultWindow : public QDialog
{
    Q_OBJECT
    
public:

    explicit ResultWindow(QWidget *parent, QImage *image, QString type);
    ~ResultWindow();

private slots:

    void on_pButton_Save_clicked();
    void on_pushButton_adjust_clicked();
    void on_pushButton_normalS_clicked();

private:

    Ui::Export *ui;
    QImage *qImage;
    QString imageType;
    void showImage();
};

#endif // EXPORT_H
