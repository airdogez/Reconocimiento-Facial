#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <string>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void mostrarFrame();
    void on_btnDetecta_released();
    void on_btnRecortar_released();

private:
    void readCSV(std::string& filename, std::vector<cv::Mat>& images, std::vector<int>& labels, std::vector<std::string>& names);
    void writeCSV(std::string& filename, std::string path, int label, std::string name);
    void trainFaceRecogniser();
    std::string currentDateTime();
    Ui::MainWindow *ui;
    QTimer* timer;
    float fps = 60;

    bool detectaRostros;

    cv::CascadeClassifier face_cascade;
    cv::CascadeClassifier eyes_cascade;
    cv::CascadeClassifier mouth_cascade;
    cv::CascadeClassifier nose_cascade;

    cv::VideoCapture cap;
    cv::Mat frame;
    cv::Mat face_resized;

    float EYE_SX = 0.16;
    float EYE_SY = 0.26;
    float EYE_SW = 0.3;
    float EYE_SH = 0.28;

};

#endif // MAINWINDOW_H
