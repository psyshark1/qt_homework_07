#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDataStream>
#include <QMessageBox>
#include <QtGlobal>
#include <QtConcurrent>
#include <algorithm>

///Подключаем все что нужно для графиков
//#include <QtCharts>
//#include <QLineSeries>
//#include <QChartView>

#include "graphic.h"
#include "graphwindow.h"

#define FD 1000.0 //частота дискретизации

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Метод считывает данные из исходного файла
    QVector<uint32_t> ReadFile(QString path, uint8_t numberChannel);
    //Метод преобразует данные физические величины, В?
    QVector<double> ProcessFile(QVector<uint32_t> dataFile);
    //Метод ищет Максимумы
    QVector<double> FindMax(QVector<double> resultData);
    //Метод ищет минимумы
    QVector<double> FindMin(QVector<double> resultData);
    //Метод отображает результаты
    void DisplayResult(QVector<double> mins, QVector<double> maxs);



private slots:
    void on_pb_path_clicked();
    void on_pb_start_clicked();

    void on_pb_showGraph_clicked();

    void on_pb_clearResult_clicked();

signals:
    void sig_GraphDataReady(const QVector<double>& x, const QVector<double>& y, QCustomPlot* cPlot, uint32_t numGraph);

private:
    Ui::MainWindow *ui;
    GraphWindow *gw;
    QString pathToFile = "";
    uint8_t numberSelectChannel = 0xEA;

    QVector<uint32_t> readData;
    QVector<double> procesData;
    QVector<double> mins, maxs;

    QCPGraph* graphic;
    Graphic* graphClass;
    QVector<double> X;
    QVector<double> Y;
};
#endif // MAINWINDOW_H
