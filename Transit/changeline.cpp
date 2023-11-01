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

void renewname()
{

}



void changeLine::on_addButton_clicked()
{
    if(ui->findLine->text().isEmpty()) return;
    item = ui->listWidget->currentItem();
    addStat *addS=new addStat;
    addS->show();
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

        }
    }
   ui->listWidget->takeItem(ui->listWidget->row(item));

}

void changeLine::on_listWidget_currentTextChanged(const QString &currentText)
{

}
