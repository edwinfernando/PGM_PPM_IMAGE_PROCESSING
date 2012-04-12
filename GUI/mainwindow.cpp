//**********************************************************
// INTRODUCCION AL PROCESAMIENTO DIGITAL DE IMÁGENES
// PGM_PPM_IMAGE_PROCESSING_V2
//
// ARCHIVO: mainwindow.cpp
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

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainController= new MainController();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Methods related to the load image event
void MainWindow::on_pButton_LoadImage_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*)"));

    if (mainController->loadImage(filename)) {
        this->change_OnSuccessfulLoad();
    } else {
        this->change_OnUnsuccessfulLoad();
    }
}

void MainWindow::change_OnSuccessfulLoad(){

    // Changes on PushButtons:
    ui->pButton_LoadImage->setEnabled(false);
    ui->pButton_ColorDensity->setEnabled(true);
    ui->pButton_PixelDensity->setEnabled(true);
    ui->pButton__AdjustImageSize->setEnabled(true);
    ui->pButton__NormalSize->setEnabled(true);

    // Changes in ComboBoxes:
    ui->comboBox_color->setEnabled(true);
    ui->comboBox_size->setEnabled(true);

    // Changes on labels
    ui->label_Density->setEnabled(true);
    ui->label_Dimensions->setEnabled(true);
    ui->label_ImageType->setEnabled(true);

    // Set text on Labels:
    ui->label_Messages->setText("The Image was successfully loaded");
    showImage(mainController->getImage());
    //    ui->label_DimensionsValue->setText("W: "+mainController->getImageWide()+" H: "+mainController->getImageHigh());
    //    ui->label_DensityValue->setText(mainController->getColorDensity()+" Bits");
    //    ui->label_ImageTypeValue->setText(mainController->getImageType());

    //    if (mainController->getImageType()=="PPM") {
    //        ui->pButton_ConvertGrayscale->setEnabled(true);
    //    } else {
    //        ui->pButton_Histogram->setEnabled(true);
    //    }
}

void MainWindow::change_OnUnsuccessfulLoad(){
    ui->label_Messages->setText("The Image file is not found");
}

// Methods for displaying the image on the main screen
void MainWindow::showImage(QImage *qImage){
    this->qImage=qImage;
    ui->label_Imagen->setPixmap(QPixmap::fromImage(*this->qImage));
}

void MainWindow::on_pButton__AdjustImageSize_clicked()
{
    ui->label_Imagen->setPixmap(QPixmap::fromImage(this->qImage->scaled(QSize(470,470),Qt::KeepAspectRatio)));
}

void MainWindow::on_pButton__NormalSize_clicked()
{
    ui->label_Imagen->setPixmap(QPixmap::fromImage(*this->qImage));
}

// Image Processing
void MainWindow::on_pButton_PixelDensity_clicked()
{
    ui->label_Messages->setText("Changing the size of the image...");
    int density = ui->comboBox_size->currentText().left(2).toInt();
    showResultWindow(mainController->pixelDensityChanged(density));
}

void MainWindow::showResultWindow(QImage *qImage){
    ResultWindow exportWindow(this, qImage, mainController->getImageType());
    exportWindow.setModal(true);
    exportWindow.exec();
}

void MainWindow::on_pButton_ColorDensity_clicked(){
    ui->label_Messages->setText("Changing the Color Density of the image...");
    int intensidad = ui->comboBox_color->currentText().left(1).toInt();
    showResultWindow(mainController->colorDensityChanged(intensidad));
}

void MainWindow::on_pButton_ConvertGrayscale_clicked()
{
    ui->label_Messages->setText("Converting the image to grayscale...");
    showResultWindow(mainController->convertGrayscale());
}

void MainWindow::on_pButton_Histogram_clicked(){
    showResultWindow(mainController->generateHistogram());
}

//// OTHER EVENTS
void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::on_actionNew_Job_triggered()
{
    // Changes on PushButtons:
    ui->pButton_LoadImage->setEnabled(true);
    ui->pButton_ColorDensity->setEnabled(false);
    ui->pButton_PixelDensity->setEnabled(false);
    ui->pButton__AdjustImageSize->setEnabled(false);
    ui->pButton__NormalSize->setEnabled(false);
    ui->pButton_ConvertGrayscale->setEnabled(false);
    ui->pButton_Histogram->setEnabled(false);

    // Changes in ComboBoxes:
    ui->comboBox_color->setEnabled(false);
    ui->comboBox_size->setEnabled(false);

    // Changes on labels
    ui->label_Density->setEnabled(false);
    ui->label_Dimensions->setEnabled(false);
    ui->label_ImageType->setEnabled(false);

    // changes in the text on Labels:
    ui->label_Messages->setText("");
    ui->label_DensityValue->setText("");
    ui->label_DimensionsValue->setText("");
    ui->label_ImageTypeValue->setText("");

    // Erase Image
    ui->label_Imagen->setPixmap(0);

    //    mainController->newJob();
}

void MainWindow::on_actionAbout_triggered()
{
    DialogAbout about(this);
    about.setModal(true);
    about.exec();
}


