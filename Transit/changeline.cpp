#include "changeline.h"
#include "ui_changeline.h"

int nod,lin;
map<int,QString> na;
map<QString,vector<pair<pair<int,int>,int> > > gr;
QString inp;
QListWidgetItem *item;

changeLine::changeLine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeLine)
{
    ui->setupUi(this);
    QFile file("graph.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        return;//打开文件失败
    }

    QTextStream inputGragh(&file);
    inputGragh>>nod>>lin;
    for(int i=1;i<=nod;i++)
    {
        QString s;
        inputGragh>>s;
        na[i]=s;
    }
    QString xycl;
    set<QString> lnams;
    while(!inputGragh.atEnd())
    {
        int x,y,c;
        QString l;
        inputGragh>>x>>y>>c>>l;
        lnams.insert(l);
        gr[l].push_back(make_pair(make_pair(x,y),c));
    }
    file.close();

    ui->findLine->setPlaceholderText("请输入查找线路");
    QStringList list;
    for(auto it:lnams) list.append(it);
    QCompleter *completer = new QCompleter(list, ui->findLine);
    ui->findLine->setCompleter(completer);
}

changeLine::~changeLine()
{
    delete ui;
}

void saveallchange()
{
    QFile file("graph.txt");
    if(!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    QTextStream oup(&file);
    oup<<nod<<" "<<lin;
    for(int i=1;i<=nod;i++) oup<<na[i]<<endl;
    for(auto it:gr)
    {
        for(auto itt:it.second)
        {
            int x=itt.first.first,y=itt.first.second,c=itt.second;
            oup<<x<<" "<<y<<" "<<c<<" "<<it.first<<endl;
        }
    }

}

void changeLine::on_pushButton_clicked()
{
    ui->listWidget->clear();
    QString x=ui->findLine->text();
    if(gr.find(x)==gr.end())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("错误");
        msgBox.setText("线路不存在！");
        msgBox.exec();
        return;
    }
    for(int i=0;i<(int)gr[x].size();i++)
    {
        if(i==0)
        ui->listWidget->addItem(na[gr[x][i].first.first]);
        ui->listWidget->addItem(na[gr[x][i].first.second]);
    }
    ui->listWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
    for(int i = 0;i < ui->listWidget->count();i++)
    {
        ui->listWidget->item(i)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    }
}

void changeLine::on_addButton_clicked()
{
    if(ui->findLine->text().isEmpty()) return;
    bool flag=0,p=1;
    QMessageBox msgBox;
    item = ui->listWidget->currentItem();
    if(!item)
    {
        msgBox.setWindowTitle("错误");
        msgBox.setText("未选中任何站点！插入将在插在选中站点后。");
    }
    QString statName;
    while(p)
    {
        statName=QInputDialog::getText(this,"请输入","请输入站点名称，不能重复",QLineEdit::Normal,"",&flag);
        p=0;
        for(auto it:na) if(statName==it.second)
        {
            p=1;
            break;
        }
    }

    int toLast=QInputDialog::getInt(this,"请输入","请输入与上一站距离",5,0,100,1,&flag);
    int toNext=QInputDialog::getInt(this,"请输入","请输入与下一站距离",5,0,100,1,&flag);
    ++nod;na[nod]=statName;
    QString x=ui->findLine->text();
    vector<pair<pair<int,int>,int> > tmp;
    tmp.resize(0);
    QString dname=item->text();
    for(int i=0;i<(int)gr[x].size();i++)
    {
        pair<pair<int,int>,int> xx=gr[x][i],newx,newy;
        if(na[xx.first.first]==dname)
        {
            newx=xx;
            newx.first.second=nod;
            newx.second=toLast;
            newy=xx;
            newy.first.first=nod;
            newy.second=toNext;
            tmp.push_back(newx);
            tmp.push_back(newy);
        }
        else tmp.push_back(xx);
    }
    gr[x]=tmp;
    changeLine::on_pushButton_clicked();
    saveallchange();
}

void changeLine::on_deleteButton_clicked()
{
    if(ui->findLine->text().isEmpty()) return;
    QMessageBox msgBox;
    item = ui->listWidget->currentItem();
    if(!item)
    {
        msgBox.setWindowTitle("错误");
        msgBox.setText("未选中任何站点！");
        msgBox.exec();
    }
    msgBox.setWindowTitle("警告");
    msgBox.setText("删除一个站点将删除与之相连的所有线路上的该站点，\n每条线路上将自动链接该站前后两战，确认删除吗？");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret=msgBox.exec();
    if(ret==QMessageBox::Cancel) return;

    QString dname=item->text();

    for(auto it:gr)
    {
        vector<pair<pair<int,int>,int> > tmp;
        tmp.resize(0);
        for(int i=0;i<(int)it.second.size();i++)
        {
            pair<pair<int,int>,int> x=it.second[i];
            if(na[x.first.first]==dname) if(i==0) continue;
            if(na[x.first.second]==dname)
            {
                if(i==(int)it.second.size()-1) continue;
                else
                {
                    it.second[i+1].first.first=x.first.first;
                    it.second[i+1].second+=x.second;
                    continue;
                }
            }
            tmp.push_back(x);
        }
        gr[it.first]=tmp;
    }
    ui->listWidget->takeItem(ui->listWidget->row(item));
    saveallchange();
}


void changeLine::on_help_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("帮助");
    msgBox.setText("操作之前请选中站点，添加功能将在选中站点后插入新的站点，每次操作后将自动保存。");
    msgBox.exec();
}

void changeLine::on_changeButton_clicked()
{
    if(ui->findLine->text().isEmpty()) return;
    QMessageBox msgBox;
    item = ui->listWidget->currentItem();
    if(!item)
    {
        msgBox.setWindowTitle("错误");
        msgBox.setText("未选中任何站点！");
        msgBox.exec();
    }

    QString dname=item->text();

    QString statName;
    bool p=1,flag=0;
    while(p)
    {
        statName=QInputDialog::getText(this,"请输入","请输入站点名称，不能重复",QLineEdit::Normal,"",&flag);
        p=0;
        for(auto it:na) if(statName==it.second)
        {
            p=1;
            break;
        }
    }

    for(auto it:na)
    {
        if(it.second==dname)
        {
            na[it.first]=statName;
            break;
        }
    }
    changeLine::on_pushButton_clicked();
    saveallchange();
}
