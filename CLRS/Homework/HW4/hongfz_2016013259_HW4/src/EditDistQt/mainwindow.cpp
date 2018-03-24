#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainwidget=new QWidget();
    mainlayout=new QGridLayout();

    stringxlabel=new QLabel("Source String");
    stringylabel=new QLabel("Target String");
    copylabel=new QLabel("COPY");
    replacelabel=new QLabel("REPLACE");
    insertlabel=new QLabel("INSERT");
    deletelabel=new QLabel("DELETE");
    twiddlelabel=new QLabel("TWIDDLE");
    killlabel=new QLabel("KILL");

    resultoutput=new QTextEdit("RESULT");
    costoutput=new QLabel("COST");

    stringxinput=new QLineEdit();
    stringyinput=new QLineEdit();
    copyinput=new QLineEdit();
    replaceinput=new QLineEdit();
    insertinput=new QLineEdit();
    deleteinput=new QLineEdit();
    twiddleinput=new QLineEdit();
    killinput=new QLineEdit();

    calcbutton=new QPushButton("Calculate");
    clearbutton=new QPushButton("Clear");

    mainlayout->addWidget(stringxlabel,0,0,1,2);
    mainlayout->addWidget(stringxinput,0,2,1,2);
    mainlayout->addWidget(stringylabel,1,0,1,2);
    mainlayout->addWidget(stringyinput,1,2,1,2);
    mainlayout->addWidget(copylabel,2,0,1,1);
    mainlayout->addWidget(copyinput,2,1,1,1);
    mainlayout->addWidget(replacelabel,2,2,1,1);
    mainlayout->addWidget(replaceinput,2,3,1,1);
    mainlayout->addWidget(insertlabel,3,0,1,1);
    mainlayout->addWidget(insertinput,3,1,1,1);
    mainlayout->addWidget(deletelabel,3,2,1,1);
    mainlayout->addWidget(deleteinput,3,3,1,1);
    mainlayout->addWidget(twiddlelabel,4,0,1,1);
    mainlayout->addWidget(twiddleinput,4,1,1,1);
    mainlayout->addWidget(killlabel,4,2,1,1);
    mainlayout->addWidget(killinput,4,3,1,1);
    mainlayout->addWidget(resultlabel,5,0,1,4);
    mainlayout->addWidget(resultoutput,6,0,8,4);
    mainlayout->addWidget(costoutput,14,0,1,4);
    mainlayout->addWidget(calcbutton,15,0,1,2);
    mainlayout->addWidget(clearbutton,15,2,1,2);

    setCentralWidget(mainwidget);
    mainwidget->setLayout(mainlayout);

    connect(calcbutton,SIGNAL(clicked(bool)),this,SLOT(calcbuttonclicked()));
    connect(clearbutton,SIGNAL(clicked(bool)),this,SLOT(clearbuttonclicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::calcbuttonclicked()
{
    QString qx=stringxinput->text();
    QString qy=stringyinput->text();
    QString qcopycost=copyinput->text();
    QString qreplacecost=replaceinput->text();
    QString qinsertcost=insertinput->text();
    QString qdeletecost=deleteinput->text();
    QString qtwiddlecost=twiddleinput->text();
    QString qkillcost=killinput->text();

    if(qx.isEmpty() || qy.isEmpty() || qcopycost.isEmpty()
            || qreplacecost.isEmpty() || qinsertcost.isEmpty() || qdeletecost.isEmpty()
            || qtwiddlecost.isEmpty() || qkillcost.isEmpty())
        QMessageBox::information(this, QString("Error"),QString("Please input enough infomation!"));

    string x=" ";
    x+=qx.toStdString();
    string y=" ";
    y+=qy.toStdString();
    int copycost=qcopycost.toInt();
    int replacecost=qreplacecost.toInt();
    int insertcost=qinsertcost.toInt();
    int deletecost=qdeletecost.toInt();
    int twiddlecost=qtwiddlecost.toInt();
    int killcost=qkillcost.toInt();

    int* cost=new int[6];
    cost[COPY]=copycost;
    cost[REPLACE]=replacecost;
    cost[INSERT]=insertcost;
    cost[DELETE]=deletecost;
    cost[TWIDDLE]=twiddlecost;
    cost[KILL]=killcost;

    int** costtable = new int*[x.length()];
    int** op = new int*[x.length()];
    for (int i = 0; i < x.length(); ++i)
    {
        costtable[i] = new int[y.length()];
        op[i] = new int[y.length()];
    }

    EditDist(x,y,x.length(),y.length(),costtable,op,cost);
    vector<int> consops=Construct(op,x.length(),y.length());
    vector<pair<string,string> > proc=ShowProc(x,y,consops);

    costoutput->setText(QString::number(costtable[x.length()-1][y.length()-1]));
    QString results;
    for(int i=0;i<consops.size();++i)
    {
        switch(consops[i])
        {
        case COPY:
            results+="COPY\t";
            break;
        case REPLACE:
            results+="REPLACE\t";
            break;
        case INSERT:
            results+="INSERT\t";
            break;
        case DELETE:
            results+="DELETE\t";
            break;
        case TWIDDLE:
            results+="TWIDDLE\t";
            break;
        case KILL:
            results+="KILL\t";
            break;
        }
        results+=(QString::fromStdString(proc[i].first)+QString("\t")+QString::fromStdString(proc[i].second)+QString("\n"));
    }
    resultoutput->setText(results);
}

void MainWindow::clearbuttonclicked()
{
    costoutput->clear();
    resultoutput->clear();
    copyinput->clear();
    replaceinput->clear();
    insertinput->clear();
    deleteinput->clear();
    twiddleinput->clear();
    killinput->clear();
    stringxinput->clear();
    stringyinput->clear();
}
