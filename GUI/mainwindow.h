//**********************************************************
// INTRODUCCION AL PROCESAMIENTO DIGITAL DE IMÁGENES
// PGM_PPM_IMAGE_PROCESSING_V2
//
// ARCHIVO: mainwindow.h
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt include
#include <QMainWindow>
#include <QFileDialog>
#include <QApplication>
#include <QPixmap>

// Projec include
#include "GUI/dialogabout.h"
#include "CONTROLLER/maincontroller.h"
#include "GUI/resultwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent=0);
    ~MainWindow();

private slots:

    // Methods related to the load image event
    void on_pButton_LoadImage_clicked();
    void change_OnSuccessfulLoad();
    void change_OnUnsuccessfulLoad();
    void showImage(QImage *qImage);     // Method for displaying the image on the main screen
    void showResultWindow(QImage *qImage);

    // Events for changing the image size on the main screen
    void on_pButton__AdjustImageSize_clicked();
    void on_pButton__NormalSize_clicked();

    // PixelDensity Event;
    void on_pButton_PixelDensity_clicked();

    // ColorDensity
    void on_pButton_ColorDensity_clicked();

    //GrayScale
    void on_pButton_ConvertGrayscale_clicked();

    // Histogram
    void on_pButton_Histogram_clicked();

    //     MenuBar Events
    void on_actionClose_triggered();
    void on_actionNew_Job_triggered();
    void on_actionAbout_triggered();


private:

    Ui::MainWindow *ui;
    MainController *mainController;
    QImage *qImage;
};

#endif // MAINWINDOW_H
