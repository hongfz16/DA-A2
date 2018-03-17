#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QWidget>
#include "canvaswidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindow *ui;
	QLineEdit *lineedit;
	QPushButton *bu_generate_points;
	QPushButton *bu_get_closest_pair;
	QPushButton *bu_naive_get_closest_pair;
	QPushButton *bu_clear_points;
	QPushButton *bu_cancel;
	QPushButton *bu_start_click_input;
	QPushButton *bu_end_click_input;
	QGridLayout *layout;
	QWidget *mainwidget;
	CanvasWidget *canvaswidget;

signals:
	void GeneratePointsSignal(int);

public slots:
	void GeneratePointsSlot();
	void StartSlot();
	void EndSlot();
};

#endif // MAINWINDOW_H
