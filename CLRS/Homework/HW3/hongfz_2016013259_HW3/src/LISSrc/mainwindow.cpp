#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("LIS");

    mainwidget=new QWidget();
    mainlayout=new QGridLayout();
    mysubmit=new QPushButton("Submit!");
    myinput=new QLineEdit();
    outarr=new QLabel("outarr:");
    mylength=new QLabel("length:");
    mytime=new QLabel("time:");

    mainlayout->addWidget(myinput,0,0,1,3);
    mainlayout->addWidget(mysubmit,0,3,1,1);
    mainlayout->addWidget(outarr,1,0,1,4);
    mainlayout->addWidget(mylength,2,0,1,2);
    mainlayout->addWidget(mytime,2,2,1,2);

    mainwidget->setLayout(mainlayout);
    this->setCentralWidget(mainwidget);

    connect(mysubmit,SIGNAL(clicked(bool)),this,SLOT(SubmitClicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::SubmitClicked()
{
    vector<int> arr;
    if(this->GetInputArr(arr)!=-1)
    {
        this->GetAns(arr);
    }
    else
    {
        QMessageBox::information(this, QString("Error"),QString("Input Format Error!"));
    }
}

int MainWindow::GetInputArr(vector<int> &arr)
{
    QString numstr=myinput->text();
    if(numstr.isEmpty())
        return -1;
    int temp=0;
    for(int i=0;i<numstr.size();++i)
    {
        if(numstr[i]!=' ' && (numstr[i]>'9' || numstr[i]<'0'))
            return -1;
        if(numstr[i]!=' ')
        {
            temp*=10;
            char tempc=numstr[i].toLatin1();
            temp+=(tempc-'0');
        }
        else
        {
            arr.push_back(temp);
            temp=0;
        }
    }
    if(numstr[numstr.size()-1]!=' ')
        arr.push_back(temp);
    return 0;
}

void MainWindow::GetAns(vector<int> &arr)
{
    vector<int> dp;
    clock_t cctime=clock();
    int len=getLISLen(arr,dp);
    cctime=clock()-cctime;
    vector<int> indexarr;
    getLISIndex(arr,dp,indexarr,len);
    mytime->setText(QString("Time: ")+QString::number(static_cast<int>(cctime))+QString("ms"));
    mylength->setText(QString("Length of LIS: ")+QString::number(len));
    QString htmlstr("<p>");
    for(int i=0;i<arr.size();++i)
    {
        if(std::find(indexarr.begin()+1,indexarr.end(),i)!=indexarr.end())
            htmlstr+=QString("<font color=\"#FF0000\">")+QString::number(arr[i])+QString("</font>&nbsp;");
        else
            htmlstr+=QString::number(arr[i])+QString("&nbsp;");
    }
    htmlstr+=QString("</p>");
    outarr->setText(htmlstr);
}

