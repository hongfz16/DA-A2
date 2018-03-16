#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <vector>
#include <iostream>
#include <ctime>
#include "LIS.h"

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QWidget* mainwidget;
    QGridLayout* mainlayout;
    QPushButton* mysubmit;
    QLineEdit* myinput;
    QLabel* outarr;
    QLabel* mylength;
    QLabel* mytime;

public slots:
    void SubmitClicked();

public:
    int GetInputArr(vector<int>& arr);
    void GetAns(vector<int>& arr);
};

#endif // MAINWINDOW_H
