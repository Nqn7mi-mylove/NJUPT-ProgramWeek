#include "mainwindow.h"
#include "ui_mainwindow.h"

const int maxn=100005;
vector<pair<int,int> > graph[100005];
map<pair<int,int>,vector<int> > bel;
map<int,string> name;
int nodes,edges,lines;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionHelp,SIGNAL(clicked),this,SLOT(help_clicked()));

    ifstream inputGragh("./graph.txt");
    inputGragh>>nodes>>lines;
    for(int i=1;i<=nodes;i++)
    {
        string s;
        inputGragh>>s;
        name[i]=s;
    }
    string xycl;
    while(getline(inputGragh,xycl))
    {
        int x,y,c,l;
        sscanf(xycl.c_str(),"%d,%d,%d,%d",&x,&y,&c,&l);
        graph[x].push_back(make_pair(y,c));
        graph[y].push_back(make_pair(x,c));
        bel[make_pair(x,y)].push_back(l);
        bel[make_pair(y,x)].push_back(l);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_roadSearch_clicked()
{
    searchDialog *searchD=new searchDialog;
    searchD->show();
}

void MainWindow::on_help_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("帮助");
    msgBox.setText("此处界面为用户端，无法增添、修改路线。\n如需增添修改，请使用管理员账号登陆");
    msgBox.exec();
}

void MainWindow::on_showMap_clicked()
{

}
