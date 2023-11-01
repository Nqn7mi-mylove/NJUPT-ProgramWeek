#include "searchdialog.h"
#include "ui_searchdialog.h"

vector<pair<int,int> > graph[100005];//地图
map<pair<int,int>,vector<QString> > bel;//边属于哪一条路线
map<int,QString> name;//点的编号对应名称
int nodes,edges,lines;//点数、边数、路线数
vector<int> ans;//用于记录答案
int mp[200][200],path[200][200];//用于floyd，存储点到点的距离以及路径
stringstream outp;//存储输出流

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


void searchDialog::on_getStart_selectionChanged()//选择输入框时清空输入框
{
    ui->getStart->clear();
}

void searchDialog::on_getEnd_selectionChanged()//选择输入框时清空输入框
{
    ui->getEnd->clear();
}

void print(int a,int b)//还原路径
{
    if(path[a][b]==-1) return;
    print(a,path[a][b]);
    ans.push_back(path[a][b]);
    print(path[a][b],b);
}

void Debug()//产生一个输出ok的弹窗，用于debug
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("OK");
    msgBox.setText("ok");
    msgBox.exec();
}

int chang[200];
vector<int> dijkstra(int start,int end)//最短路，计算最少换乘
{
    memset(chang,1e9+7,sizeof(chang));
    priority_queue<pair<int,pair<vector<int>,pair<int,set<string> > > > > q;
    set<string> ss;ss.clear(); vector<int> roadd;
    roadd.resize(0);chang[start]=0;
    q.push(make_pair(0,make_pair(roadd,make_pair(start,ss))));
    vector<int> anss;
    while(!q.empty())
    {

        auto it=q.top();
        q.pop();
        int disc=it.first,x=it.second.second.first;
        ss=it.second.second.second;
        roadd=it.second.first;
        if(x==end)
        {
            anss=roadd;
        }
        for(auto itt:graph[x])
        {
            int y=itt.first;
            int flag=1;set<string> nxt;nxt.clear();
            for(auto ittt:bel[make_pair(x,y)])
            {
                if(ss.find(ittt.toLocal8Bit().constData())!=ss.end())
                {
                    flag=0;
                }
                nxt.insert(ittt.toLocal8Bit().constData());
            }
            if(chang[x]+flag<chang[y])
            {
                chang[y]=chang[x]+flag;
                roadd.push_back(y);
                q.push(make_pair(-chang[y],make_pair(roadd,make_pair(y,nxt))));
                roadd.pop_back();
            }
        }
    }
    return anss;
}

void searchDialog::on_searchButton_clicked()//包括floyd和dijkstra的调用，计算路径
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
    ans.resize(0);
    print(start,end);
    outp<<"用时最短线路（用时"<<mp[start][end]<<"分钟）："<<endl;
    if(ans.empty())
    {
        cout<<"empty"<<endl;
        outp<<"乘坐"<<bel[make_pair(start,end)][0].toLocal8Bit().constData()<<"号线，用时"<<mp[start][end]<<"分钟"<<endl;
        outp<<name[start].toLocal8Bit().constData()<<"-->"<<name[end].toLocal8Bit().constData()<<endl;
    }
    else
    {
        vector<int> sameLine;
        map<QString,int> totLine;
        totLine.clear();
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
                for(int j=0;j<(int)sameLine.size();j++)
                {
                    if(j==0) outp<<name[sameLine[j]].toLocal8Bit().constData();
                    else outp<<"-->"<<name[sameLine[j]].toLocal8Bit().constData();
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
        QString ansLine;
        for(auto it:totLine) if(it.second==(int)sameLine.size()-1)
        {
            ansLine=it.first;
            break;
        }
        outp<<"乘坐"<<ansLine.toLocal8Bit().constData()<<"号线，用时"<<mp[sameLine[0]][sameLine[(int)sameLine.size()-1]]<<"分钟"<<endl;
        for(int j=0;j<(int)sameLine.size();j++)
        {
            if(j==0) outp<<name[sameLine[j]].toLocal8Bit().constData();
            else outp<<"-->"<<name[sameLine[j]].toLocal8Bit().constData();
        }

    }
    outp<<endl;
//    ui->sendRoad->setText(QString::fromStdString(outp.str()));
    ans=dijkstra(start,end);
    outp<<endl;
    int leastime=0;
    if(ans.empty()) leastime+=mp[start][end];
    else leastime+=mp[start][ans[0]];
    for(int i=1;i<(int)ans.size();i++) leastime+=mp[ans[i-1]][ans[i]];
    outp<<"最少换乘线路（用时"<<leastime<<"分钟）："<<endl;
    if(ans.empty())
    {

        outp<<"乘坐"<<bel[make_pair(start,end)][0].toLocal8Bit().constData()<<"号线，用时"<<mp[start][end]<<"分钟"<<endl;
        outp<<name[start].toLocal8Bit().constData()<<"-->"<<name[end].toLocal8Bit().constData()<<endl;
    }
    else
    {
        cout<<ans.size()<<endl;
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        vector<int> sameLine;
        map<QString,int> totLine;
        totLine.clear();
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
                for(int j=0;j<(int)sameLine.size();j++)
                {
                    if(j==0) outp<<name[sameLine[j]].toLocal8Bit().constData();
                    else outp<<"-->"<<name[sameLine[j]].toLocal8Bit().constData();
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
        QString ansLine;
        for(auto it:totLine) if(it.second==(int)sameLine.size()-1)
        {
            ansLine=it.first;
            break;
        }
        outp<<"乘坐"<<ansLine.toLocal8Bit().constData()<<"号线，用时"<<mp[sameLine[0]][sameLine[(int)sameLine.size()-1]]<<"分钟"<<endl;
        for(int j=0;j<(int)sameLine.size();j++)
        {
            if(j==0) outp<<name[sameLine[j]].toLocal8Bit().constData();
            else outp<<"-->"<<name[sameLine[j]].toLocal8Bit().constData();
        }

        outp<<endl;
    }


    ui->sendRoad->setText(QString::fromStdString(outp.str()));

}
