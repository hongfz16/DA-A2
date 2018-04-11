#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainwidget=new QWidget();
    setCentralWidget(mainwidget);
    layout=new QGridLayout();
    mainwidget->setLayout(layout);

    openfilebutton=new QPushButton("Open");
    findfirstbutton=new QPushButton("Find First");
    findallbutton=new QPushButton("Find All");

    patternedit=new QLineEdit();
    filelabel=new QLineEdit();
    resulttext=new QTextEdit();

    filelabel->setFocusPolicy(Qt::NoFocus);
    resulttext->setFocusPolicy(Qt::NoFocus);

    layout->addWidget(filelabel,0,0,1,3);
    layout->addWidget(openfilebutton,0,3,1,1);
    layout->addWidget(patternedit,1,0,1,4);
    layout->addWidget(findfirstbutton,2,0,1,2);
    layout->addWidget(findallbutton,2,2,1,2);
    layout->addWidget(resulttext,3,0,3,4);

    connect(openfilebutton,SIGNAL(clicked(bool)),this,SLOT(openfileclicked()));
    connect(findfirstbutton,SIGNAL(clicked(bool)),this,SLOT(findfirstclicked()));
    connect(findallbutton,SIGNAL(clicked(bool)),this,SLOT(findallclicked()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::openfileclicked()
{
    QString qfilename=QFileDialog::getOpenFileName(this,QString("Select File"),".","*.txt");
    filelabel->setText(qfilename);
    if(qfilename.isEmpty())
        return;
    string filename=qfilename.toStdString();
    ifstream fin(filename);
    string temp;
    while(!fin.eof())
    {
        getline(fin,temp);
        text+=temp+string("\n");
    }
    fin.close();
}

void MainWindow::findfirstclicked()
{
    QString qpattern=patternedit->text();
    if(qpattern.isEmpty() || text.empty())
        return;
    pattern=qpattern.toStdString();

    clock_t s=clock();
    int naiveans=NaiveFindFirst(pattern,text);
    clock_t naivetime=clock()-s;

    s=clock();
    int KMPans=KMPFindFirst(pattern,text);
    clock_t KMPtime=clock()-s;

    s=clock();
    int BMans=BMFindFirst(pattern,text);
    clock_t BMtime=clock()-s;

    QString result;

    result+=QString::number(text.size())+QString(" Characters in Text File.\n");

    if(naiveans==-1)
        result+=QString("Pattern Not Found!\n");
    else
        result+=QString("First Match Found in Shift: ")+QString::number(naiveans)+QString("\n");
    result+=QString("Brute-Force Time: ")+QString::number(naivetime)+QString("ms\n");
    result+=QString("KMP Time: ")+QString::number(KMPtime)+QString("ms\n");
    result+=QString("BM Time: ")+QString::number(BMtime)+QString("ms\n");
    resulttext->setText(result);
}

void MainWindow::findallclicked()
{
    QString qpattern=patternedit->text();
    if(qpattern.isEmpty() || text.empty())
        return;
    pattern=qpattern.toStdString();

    clock_t s=clock();
    vector<int> naiveans=NaiveFindAll(pattern,text);
    clock_t naivetime=clock()-s;

    s=clock();
    vector<int> KMPans=KMPFindAll(pattern,text);
    clock_t KMPtime=clock()-s;

    s=clock();
    vector<int> BMans=BMFindAll(pattern,text);
    clock_t BMtime=clock()-s;

    QString result;

    result+=QString::number(text.size())+QString(" Characters in Text File.\n");

    if(naiveans.size()==0)
        result+=QString("Pattern Not Found!\n");
    else
        result+=QString::number(naiveans.size())+QString(" Matches Found!\n");
    result+=QString("Brute-Force Time: ")+QString::number(naivetime)+QString("ms\n");
    result+=QString("KMP Time: ")+QString::number(KMPtime)+QString("ms\n");
    result+=QString("BM Time: ")+QString::number(BMtime)+QString("ms\n");
    if(naiveans.size()!=0)
    {
        result+=QString("Matches Found in tht following Shifts: ");
        for(const int& i : naiveans)
        {
            result+=QString::number(i)+QString(" ");
        }
        resulttext->setText(result);
    }
    else
    {
        resulttext->setText(result);
    }
}
