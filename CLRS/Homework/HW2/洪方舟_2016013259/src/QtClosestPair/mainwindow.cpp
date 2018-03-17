#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	setWindowTitle("Find Closest Pair");

	setFixedSize(800,600);

	lineedit=new QLineEdit();

	bu_generate_points=new QPushButton("Generate Points");
	bu_get_closest_pair=new QPushButton("O(nlogn) Get Closest Pair");
	bu_naive_get_closest_pair=new QPushButton("O(n^2) Get Closest Pair");
	bu_clear_points=new QPushButton("Clear Points");
	bu_cancel=new QPushButton("Cancel");
	bu_start_click_input=new QPushButton("Start Click Input");
	bu_end_click_input=new QPushButton("End Click Input");

	bu_end_click_input->setEnabled(false);

	layout=new QGridLayout;
	int cut=3;
	int base=1;
	layout->addWidget(lineedit,0,cut,1,1);
	layout->addWidget(bu_generate_points,base,cut,1,1);
	layout->addWidget(bu_get_closest_pair,base+1,cut,1,1);
	layout->addWidget(bu_naive_get_closest_pair,base+2,cut,1,1);
	layout->addWidget(bu_clear_points,base+3,cut,1,1);
	layout->addWidget(bu_cancel,base+4,cut,1,1);
	layout->addWidget(bu_start_click_input,base+5,cut,1,1);
	layout->addWidget(bu_end_click_input,base+6,cut,1,1);

	canvaswidget=new CanvasWidget();

	layout->addWidget(canvaswidget,0,0,7,3);

	mainwidget=new QWidget();
	mainwidget->setLayout(layout);
	this->setCentralWidget(mainwidget);

	connect(bu_get_closest_pair,SIGNAL(clicked(bool)),canvaswidget,SLOT(GetClosestPair()));
	connect(bu_naive_get_closest_pair,SIGNAL(clicked(bool)),canvaswidget,SLOT(NaiveGetClosestPair()));
	connect(bu_generate_points,SIGNAL(clicked(bool)),this,SLOT(GeneratePointsSlot()));
	connect(this,SIGNAL(GeneratePointsSignal(int)),canvaswidget,SLOT(GeneratePointsClicked(int)));
	connect(bu_cancel,SIGNAL(clicked(bool)),canvaswidget,SLOT(CancelClicked()));
	connect(bu_clear_points,SIGNAL(clicked(bool)),canvaswidget,SLOT(ClearClicked()));
	connect(bu_start_click_input,SIGNAL(clicked(bool)),canvaswidget,SLOT(StartClicked()));
	connect(bu_end_click_input,SIGNAL(clicked(bool)),canvaswidget,SLOT(EndClicked()));
	connect(bu_start_click_input,SIGNAL(clicked(bool)),this,SLOT(StartSlot()));
	connect(bu_end_click_input,SIGNAL(clicked(bool)),this,SLOT(EndSlot()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::GeneratePointsSlot()
{
	QString numstr=lineedit->text();
	bool ok=false;
	int num=numstr.toInt(&ok,10);
	if(ok)
	{
		emit GeneratePointsSignal(num);
	}
}

void MainWindow::StartSlot()
{
	bu_start_click_input->setEnabled(false);
	bu_end_click_input->setEnabled(true);
}

void MainWindow::EndSlot()
{
	bu_start_click_input->setEnabled(true);
	bu_end_click_input->setEnabled(false);
}
