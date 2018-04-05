#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QPushButton>
#include<QLabel>
#include<QWidget>
#include<QGridLayout>
#include<QLineEdit>
#include<QFileDialog>
#include<QString>
#include<QTextEdit>

#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<ctime>

#include"Naive.h"
#include"KMP.h"
#include"BoyerMoore.h"

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openfileclicked();
    void findfirstclicked();
    void findallclicked();

private:
    QPushButton* openfilebutton;
    QPushButton* findfirstbutton;
    QPushButton* findallbutton;

    QLineEdit* patternedit;
    QLineEdit* filelabel;

    QTextEdit* resulttext;

    QGridLayout* layout;
    QWidget* mainwidget;

    string pattern;
    string text;
};

#endif // MAINWINDOW_H
