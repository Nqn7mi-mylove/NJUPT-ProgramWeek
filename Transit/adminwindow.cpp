#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_roadSearch_clicked()
{
    searchDialog *searchD=new searchDialog;
    searchD->show();
}

void AdminWindow::on_randomGen_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("随机生成将覆盖现有的公共交通网络，确认覆盖吗？");
    msgBox.setWindowTitle("确认");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret=msgBox.exec();
    if(ret==QMessageBox::Ok)
    {
        srand(time(NULL));
        QFile file("graph.txt");
        if(!file.open(QIODevice::WriteOnly))
        {
            return;
        }
        QTextStream oup(&file);
        int nodes=rand()%50+100;
        int lines=rand()%10+20;
        oup<<nodes<<" "<<lines<<endl;
        QString s="南医大二附院总站安德门,能仁里,雨花西路,窑湾街,钓鱼台,中山南路·新桥,中山南路·升州路,三元巷,新街口南,新街口北,中山路·珠江路北,中山北路·鼓楼,中山北路·大方巷,山西路,中山北路·虹桥,中山北路·三牌楼,萨家湾,南医二附院东院,盐仓桥广场西,挹江门,热河南路,南医大二附院,姜家圩,姜家园南,南医大二附院总站,丁家庄九乡河西路,信息学院,文澜路东,紫金学院,文澜路·南工院西,邮电大学北,学海路,文澜路北,文澜路,文澜路南,亚东新城区,文苑路西,仙隐北路,雁鸣山庄,亚东花园城,尧胜村,仙尧路·尧胜村,花卉物流中心,海子口,尧化门西,金尧山庄,丁家庄,";
        vector<QString> vs;
        map<pair<int,int>,int> lenc;
        lenc.clear();
        QString k="";
        for(int i=0;i<(int)s.size();i++)
        {
            if(s[i]==',')
            {
                vs.push_back(k);
                k="";
            }
            else k=k+s[i];
        }
        int randStart=rand()%(int)vs.size();
        for(int i=0;i<nodes;i++)
            oup<<vs[(i+randStart)%(int)vs.size()]<<endl;

        for(int i=0;i<lines;i++)
        {
            int length=rand()%nodes+1;
            if(length<5) length+=5;
            if(i==0) length=nodes;
            int N=nodes,n=nodes;
            vector<int> vAllIndices(N);
            vector<int> vAvailableIndices(n);
            for(int j=0;j<(int)vAllIndices.size();j++)
            {
                vAllIndices[j]=j;
            }
            for(int j=0;j<(int)vAvailableIndices.size();j++)
            {
                int idx=rand()%vAllIndices.size();
                vAvailableIndices[j]=vAllIndices[idx];
                vAllIndices[idx]=vAllIndices.back();
                vAllIndices.pop_back();
            }
            QString randomLine="";
            randomLine=randomLine+char(rand()%26+'a')+char(rand()%10+'0');
            if(rand()%2) randomLine=randomLine+char(rand()%10+'0');
            for(int j=0;j<length-1;j++)
            {
                int x=vAvailableIndices[j]+1,y=vAvailableIndices[j+1]+1;
                if(lenc.find(make_pair(x,y))==lenc.end())
                {
                    lenc[make_pair(x,y)]=lenc[make_pair(y,x)]=rand()%20+5;
                }

                oup<<x<<" "<<y<<" "<<lenc[make_pair(x,y)]<<" "<<randomLine<<endl;
            }
        }
        file.close();
        QMessageBox msgBoxYes;
        string msg="生成成功！本次生成了";
        msg=msg+char(nodes/100+'0');
        msg=msg+char(nodes/10%10+'0');
        msg=msg+char(nodes%10+'0');
        msg=msg+"个点的公交网络。";
        msgBoxYes.setText(msg.c_str());
        msgBoxYes.setWindowTitle("成功");
        msgBoxYes.exec();
    }
}
