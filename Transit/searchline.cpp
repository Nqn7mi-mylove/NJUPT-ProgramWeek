#include "searchline.h"
#include "ui_searchline.h"

int node,line;
map<int,QString> nam;
map<QString,vector<pair<pair<int,int>,int> > > gra;

searchline::searchline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchline)
{
    ui->setupUi(this);

    QFile file("graph.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        return;//打开文件失败
    }

    QTextStream inputGragh(&file);
    inputGragh>>node>>line;
    for(int i=1;i<=node;i++)
    {
        QString s;
        inputGragh>>s;
        nam[i]=s;
    }
    QString xycl;
    set<QString> lnams;
    while(!inputGragh.atEnd())
    {
        int x,y,c;
        QString l;
        inputGragh>>x>>y>>c>>l;
        lnams.insert(l);
        gra[l].push_back(make_pair(make_pair(x,y),c));
    }
    file.close();

    ui->findLine->setPlaceholderText("请输入查找线路");
    QStringList list;
    for(auto it:lnams) list.append(it);
    QCompleter *completer = new QCompleter(list, ui->findLine);
    ui->findLine->setCompleter(completer);
}

searchline::~searchline()
{
    delete ui;
}

void searchline::on_search_clicked()
{
    QString x=ui->findLine->text();
    if(gra.find(x)==gra.end())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("错误");
        msgBox.setText("线路不存在！");
        msgBox.exec();
        return;
    }
    int cnt=0;
    stringstream outt;
    cout<<gra.size()<<endl;
    for(auto it:gra[x])
    {
        if(cnt==0)
        {
            outt<<nam[it.first.first].toLocal8Bit().constData();
            cnt++;
        }
        if(cnt%2==0)
        {
            outt<<"--"<<endl<<"-"<<it.second<<"min---"<<nam[it.first.second].toLocal8Bit().constData();
        }
        else
        {
            outt<<"---"<<it.second<<"min---"<<nam[it.first.second].toLocal8Bit().constData();
        }
        cnt++;
    }
    ui->outLine->setText(QString::fromStdString(outt.str()));

}

void searchline::on_findLine_selectionChanged()
{
    ui->findLine->clear();
}
