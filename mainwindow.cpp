#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <string>

using namespace cv;
using namespace std;

string wn2 = "Detectar rostros";
string wn1 = "Imagen Original";
string face_cascade_name = "/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml";
string eyes_cascade_name = "/usr/share/opencv/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
string mouth_cascade_name = "/usr/share/opencv/haarcascades/haarcascade_mcs_mouth.xml";
string nose_cascade_name = "/usr/share/opencv/haarcascades/haarcascade_mcs_nose.xml";
string folder_rostros = "Rostros/";
string archivo_csv = "rostros.csv";

cv::Ptr<cv::FaceRecognizer> model;

vector<Rect> faces, eyes, mouth, nose;

//Vectores con los rostros guardados
vector<cv::Mat> imagenes;
vector<int> etiquetas;
vector<string> nombres;

const int im_width = 200;
const int im_height = 200;

std::string MainWindow::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%T", &tstruct);
    return buf;
}

/*
 * Lee un archivo CSV y llena los vectores de imagenes y etiquetas
 */
void MainWindow::readCSV(string& filename, vector<Mat>& images, vector<int>& labels, vector<string>& names){
  ifstream file;
  file.open(filename.c_str(), ios::in);
  if ( !file ){
    string error = "No file input given";
    CV_Error(CV_StsBadArg, error);
  }
  string line, path, classLabel, name;
  while ( getline(file, line)){
    stringstream liness(line);
    getline(liness, path, ',');
    getline(liness, classLabel, ',');
    getline(liness, name);
    if(!path.empty() && !classLabel.empty()){
      images.push_back(imread(path,0));
      labels.push_back(atoi(classLabel.c_str()));
      names.push_back(name);
    }
  }
}

void MainWindow::writeCSV(string& filename, string path, int label, string name){
  ofstream file;
  file.open(filename.c_str(), ios::app);
  file << path << ',' << label << ',' << name << endl;
  file.close();
}

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  this->setFixedSize(800,600);
  timer = new QTimer(this);
  cap = VideoCapture(0);
  connect(timer, SIGNAL(timeout()), this, SLOT(mostrarFrame()));
  timer->setInterval(fps);
  detectaRostros = false;
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::mostrarFrame(){
  if(cap.isOpened()){
    if(!face_cascade.load(face_cascade_name));
    eyes_cascade.load(eyes_cascade_name);
    mouth_cascade.load(mouth_cascade_name);
    nose_cascade.load(nose_cascade_name);
    cap >> frame;

    if(detectaRostros){
      Mat gray, dest;
      cvtColor(frame, gray, CV_BGR2GRAY);
      equalizeHist(gray,dest);
      //vector<Rect> faces;
      //Utiliza el detector HAAR para detectar los rostros en la imagen
      face_cascade.detectMultiScale(dest, faces,1.2,4,0, Size(60,60));
      for (size_t i = 0; i < faces.size(); ++i) {
        //Dibuja un rectangulo en el rostro detectado
        //rectangle(frame, Point(faces[i].x, faces[i].y*0.8), Point(faces[i].x+faces[i].width,faces[i].y+faces[i].height*1.2), CV_RGB(0,255,0),1);
        //Reconocimiento de rostros
        Rect face_i = faces[i];
        Mat face = gray(face_i);
        cv::resize(face, face_resized, Size(im_width, im_height), 1.0, 1.0);
        try{
          int prediccion = model->predict(face_resized);
          int pos_x = std::max(face_i.tl().x - 10, 0);
          int pos_y = std::max(face_i.tl().y - 10, 0);
          string box_text = format("%d", prediccion);
          putText(frame, box_text, Point(pos_x, pos_y), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);
        } catch (cv::Exception e) {
          cerr <<  "No se puedo abrir el archivo " << archivo_csv << "\". Rason: " << e.msg << endl;
        }

        rectangle(frame, face_i, CV_RGB(0,255,0),1);

        //Crea una matriz de solo el rostro;
        Mat faceROI = dest(faces[i]);
        //Utiliza el detector HAAR para detectar los ojos en el rostro
        //vector<Rect> eyes;
        eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2,
            0 | CV_HAAR_SCALE_IMAGE, Size(30,30));
        for (size_t j = 0; j < eyes.size(); ++j) {
          Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5,
              faces[i].y + eyes[j].y + eyes[j].height*0.5 );
          int radius = cvRound((eyes[j].width + eyes[j].height)*0.3);
          circle( frame, center, radius, Scalar(0,255,255), 1, 4 ,0);
        }

        mouth_cascade.detectMultiScale(faceROI, mouth, 1.3, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(30,30));
        rectangle(frame,
            Point(faces[i].x+mouth[0].x, faces[i].y+mouth[0].y),
            Point(faces[i].x+mouth[0].x+mouth[0].width, faces[i].y+mouth[0].y+mouth[0].height),
            CV_RGB(127,127,0), 1);

        nose_cascade.detectMultiScale(faceROI, nose, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30,30));
        rectangle(frame,
            Point(faces[i].x+nose[0].x, faces[i].y+nose[0].y),
            Point(faces[i].x+nose[0].x+nose[0].width, faces[i].y+nose[0].y+nose[0].height),
            CV_RGB(0,0,255), 1);

      }
      ui->capturaCamara->showImage(frame);
    }
  }
}

/*
 * Al presionar el boton guardar rostro, el programa debe realizar el recorte 
 * del frame y guardar en un archivo la imagen resultante.
 * Ademas debe actualizar el archivo CSV con la ruta y nombre
 */
void MainWindow::on_btnRecortar_released()
{
  //Verificar que haya un nombre ingresado
  QString qNombre = ui->leNombre->text();
  QString qEtiqueta = ui->leEtiqueta->text();
  if(qNombre.isEmpty() && qEtiqueta.isEmpty()){
    //Manada un mensaje de error
  }
  string nombre = qNombre.toStdString();
  int etiqueta = qEtiqueta.toInt();

  //Verificar que haya un rostro detectado
  if(!faces.empty() && !face_resized.empty()){
    //Obtengo la cara recortada
    //Guardarlo en la ruta
    string time = currentDateTime();
    string ruta = folder_rostros + nombre + "-" + time;
    imwrite(ruta + ".jpg", face_resized);

    //Actualizar el CSV
    writeCSV(archivo_csv, ruta + ".jpg", etiqueta, nombre);
    //finalmente vuelve a entrenar el reconocedor.
    trainFaceRecogniser();
  }
}

//Lee el archivo CSV y entrena el reconocedor de rostros;
void MainWindow::trainFaceRecogniser()
{
  try {
    readCSV(archivo_csv, imagenes, etiquetas, nombres);
    //model = cv::createFisherFaceRecognizer();
    //model->train(imagenes, etiquetas);
  } catch (cv::Exception e) {
    cerr <<  "No se puedo abrir el archivo " << archivo_csv << "\". Razon: " << e.msg << endl;
  }
}

/*
 * Al presionar el boton detectar debe reconocer un rotro
 * y en caso lo reconosca debe imprimir el nombre en la imagen
 */
void MainWindow::on_btnDetecta_released()
{
  if(!detectaRostros){
    timer->start();
    trainFaceRecogniser();
    detectaRostros = true;
    ui->btnDetecta->setText("Detener Deteccion");
  }
  else{
    timer->stop();
    frame.~Mat();
    detectaRostros = false;
    ui->btnDetecta->setText("Iniciar Deteccion");
    ui->capturaCamara->showImage(frame);
  }
}
