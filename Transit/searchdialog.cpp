#include "searchdialog.h"
#include "ui_searchdialog.h"

vector<pair<int,int> > graph[100005];
map<pair<int,int>,vector<QString> > bel;
map<int,QString> name;
int nodes,edges,lines;
vector<int> ans;
int mp[200][200],path[200][200];
stringstream outp;

searchDialog::searchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchDialog)
{
    ui->setupUi(this);

    QFile file("graph.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        return;//打开文件失败
    }

    QTextStream inputGragh(&file);
    inputGragh>>nodes>>lines;
    for(int i=1;i<=nodes;i++)
    {
        QString s;
        inputGragh>>s;
        name[i]=s;
    }
    QString xycl;
    while(!inputGragh.atEnd())
    {
        int x,y,c;
        QString l;
        inputGragh>>x>>y>>c>>l;
        graph[x].push_back(make_pair(y,c));
        graph[y].push_back(make_pair(x,c));
        bel[make_pair(x,y)].push_back(l);
        bel[make_pair(y,x)].push_back(l);
    }
    file.close();

    ui->getStart->setPlaceholderText("请输入起点");
    ui->getEnd->setPlaceholderText("请输入终点");

    QStringList list;
    for(auto it:name) list.append(it.second);
    QCompleter *completer = new QCompleter(list, ui->getStart);
    ui->getStart->setCompleter(completer);
    ui->getEnd->setCompleter(completer);

}

searchDialog::~searchDialog()
{
    delete ui;
}


void searchDialog::on_getStart_selectionChanged()
{
    ui->getStart->clear();
}

void searchDialog::on_getEnd_selectionChanged()
{
    ui->getEnd->clear();
}

void print(int a,int b)
{
    if(path[a][b]==-1) return;
    print(a,path[a][b]);
    ans.push_back(path[a][b]);
    print(path[a][b],b);
}

void searchDialog::on_searchButton_clicked()
{
    int start=-1,end=-1;
    for(auto it:name)
    {
        if(it.second==ui->getEnd->text()) end=it.first;
        if(it.second==ui->getStart->text()) start=it.first;
    }
    if(start==-1)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("错误");
        msgBox.setText("起点不存在！");
        msgBox.exec();
        return;
    }
    if(end==-1)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("错误");
        msgBox.setText("终点不存在！");
        msgBox.exec();
        return;
    }
    memset(path,-1,sizeof(path));
    for(int i=1;i<=nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {
            if(i==j) mp[i][j]=0;
            else mp[i][j]=1e9+7;
        }
        for(auto j:graph[i])
        {
            mp[i][j.first]=j.second;
        }
    }
    for(int k=1;k<=nodes;k++)
    {
        for(int i=1;i<=nodes;i++)
            for(int j=1;j<=nodes;j++)
                if(mp[i][j]>mp[i][k]+mp[k][j])
                {
                    mp[i][j]=mp[i][k]+mp[k][j];
                    path[i][j]=k;
                }
    }
    if(mp[start][end]==1e9+7)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("错误");
        msgBox.setText("没有从起点向终点的线路！");
        msgBox.exec();
        return;
    }
    if(start==end)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("错误");
        msgBox.setText("起点与终点相同！");
        msgBox.exec();
        return;
    }
    outp<<"用时最短线路（用时"<<mp[start][end]<<"分钟）："<<endl;
    if(ans.empty())
    {
        outp<<"乘坐"<<bel[make_pair(start,end)][0].toLocal8Bit().constData()<<"号线，用时"<<mp[start][end]<<"分钟"<<endl;
        outp<<name[start].toLocal8Bit().constData()<<"-->"<<name[end].toLocal8Bit().constData()<<endl;
    }
    vector<int> sameLine;
    map<QString,int> totLine;
    ans.push_back(end);
    sameLine.push_back(start);
    sameLine.push_back(ans[0]);
    for(auto it:bel[make_pair(start,ans[0])])
        totLine[it]++;
    for(int i=1;i<(int)ans.size();i++)
    {
        vector<QString> flag;
        for(auto it:bel[make_pair(ans[i-1],ans[i])])
        {
            if(totLine.find(it)!=totLine.end() && totLine[it]==(int)sameLine.size()-1)
            {
                flag.push_back(it);
            }
        }
        if(flag.empty())
        {
            QString ansLine;
            for(auto it:totLine) if(it.second==(int)sameLine.size()-1)
            {
                ansLine=it.first;
                break;
            }
            outp<<"乘坐"<<ansLine.toLocal8Bit().constData()<<"号线，用时"<<mp[sameLine[0]][sameLine[(int)sameLine.size()-1]]<<"分钟"<<endl;
            for(int j=0;j<(int)sameLine.size();i++)
            {
                if(j==0) outp<<name[sameLine[j]].toLocal8Bit().constEnd();
                else outp<<"-->"<<name[sameLine[j]].toLocal8Bit().constEnd();
            }
            outp<<endl;
            sameLine.resize(0);
            sameLine.push_back(ans[i-1]);
            sameLine.push_back(ans[i]);
            totLine.clear();
        }
        else
        {
            sameLine.push_back(ans[i]);
        }
        for(auto it:bel[make_pair(ans[i-1],ans[i])])
            totLine[it]++;
    }
    ui->sendRoad->setText(QString::fromStdString(outp.str()));


}
