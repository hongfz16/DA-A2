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
#include <QTextEdit>

#include <vector>
#include <string>
#include <iostream>
#include "EditDist.h"

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

    QLabel* stringxlabel;
    QLabel* stringylabel;
    QLabel* copylabel;
    QLabel* replacelabel;
    QLabel* insertlabel;
    QLabel* deletelabel;
    QLabel* twiddlelabel;
    QLabel* killlabel;
    QLabel* resultlabel;

    QTextEdit* resultoutput;
    QLabel* costoutput;

    QLineEdit* stringxinput;
    QLineEdit* stringyinput;
    QLineEdit* copyinput;
    QLineEdit* replaceinput;
    QLineEdit* insertinput;
    QLineEdit* deleteinput;
    QLineEdit* twiddleinput;
    QLineEdit* killinput;

    QPushButton* calcbutton;
    QPushButton* clearbutton;

public slots:
    void calcbuttonclicked();
    void clearbuttonclicked();
};

#endif // MAINWINDOW_H
