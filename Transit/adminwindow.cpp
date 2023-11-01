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

void AdminWindow::on_randomGen_clicked()//随机生成地图
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
        int nodes=(rand()%30)+100;//随机出路线数以及站点数
        int lines=(rand()%10)+20;
        oup<<nodes<<" "<<lines<<endl;
        QString s="南医大二附院总站安德门,能仁里,雨花西路,窑湾街,钓鱼台,中山南路·新桥,中山南路·升州路,三元巷,新街口南,新街口北,中山路·珠江路北,中山北路·鼓楼,中山北路·大方巷,山西路,中山北路·虹桥,中山北路·三牌楼,萨家湾,南医二附院东院,盐仓桥广场西,挹江门,热河南路,南医大二附院,姜家圩,姜家园南,南医大二附院总站,丁家庄九乡河西路,信息学院,文澜路东,紫金学院,文澜路·南工院西,邮电大学北,学海路,文澜路北,文澜路,文澜路南,亚东新城区,文苑路西,仙隐北路,雁鸣山庄,亚东花园城,尧胜村,仙尧路·尧胜村,花卉物流中心,海子口,尧化门西,金尧山庄,丁家庄,珍珠泉东站,瑞龙郊野公园站,石佛寺站,定山大街站,江北商务区站,江北市民中心站,马骡圩站,西江口站,绿水湾路站,行知路站,卓越路站,江淼路站,城南河站,浦口万汇城站,临滁路站,七里河站,江北商务区站,广西埂大街站,南京铁道学院站,新马路站,浦东路站,柳洲南路站,长江大桥北站,明滨路站,柳洲东路站,浦洲路站,八卦洲大桥南地铁站,笆斗山地铁站,燕子矶地铁站,吉祥庵地铁站,晓庄地铁站,迈皋桥地铁站,红山地铁站,南京站地铁站,新模范地铁站,玄武门地铁站,鼓楼地铁站,珠江路地铁站,新街口地铁站,张府园地铁站,三山街地铁站,中华门地铁站,安德门地铁站,天隆寺地铁站,软件大道地铁站,花神庙地铁站,南京南地铁站,双龙大道地铁站,河定桥地铁站,胜太路地铁站,百家湖地铁站,小龙湾地铁站,竹山路地铁站,天印大道地铁站,龙眠大道地铁站,南医大地铁站,南京交院地铁站,药科大学地铁站,经天路地铁站,南大地铁站,羊山公园地铁站,仙林中心地铁站,学则路地铁站,仙鹤门地铁站,金马路地铁站,马群地铁站,钟灵街地铁站,孝陵卫地铁站,下马坊地铁站,苜蓿园地铁站,明故宫地铁站,西安门地铁站,大行宫地铁,、新街地铁站,上海路地铁站,汉中门地铁站,莫愁湖地铁站,云锦路地铁站,集庆门地铁站,兴隆大街地铁站,奥体东地铁站,元通地铁站,雨润大街地铁站,油坊桥地铁站,螺塘路地铁站,青莲街地铁站,天保街地铁站,鱼嘴地铁站,";
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

        for(int i=0;i<lines;i++)//生成随机序列，截取随机序列的随即长度表示一条路线
        {
            int length=(rand()%30)+1;
            if(length<10) length+=10;
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
            char c=char((rand()%26)+'A');
            for(int j=0;j<length-1;j++)//随机路线名称，以及每两站之间的距离，将图输出到文件
            {
                int x=vAvailableIndices[j]+1,y=vAvailableIndices[j+1]+1;
                if(lenc.find(make_pair(x,y))==lenc.end())
                {
                    lenc[make_pair(x,y)]=lenc[make_pair(y,x)]=(rand()%20)+5;
                }

                oup<<x<<" "<<y<<" "<<lenc[make_pair(x,y)]<<" "<<c<<i+1<<endl;
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

void AdminWindow::on_lineSearch_clicked()
{
    searchline *searchL=new searchline;
    searchL->show();
}

void AdminWindow::on_roadChange_clicked()
{
    changeLine *changeL=new changeLine;
    changeL->show();
}

void AdminWindow::on_help_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("点击随机生成可以随机生成一张带时间的公交线路图，站名取自现实站名。");
    msgBox.setWindowTitle("帮助");
    msgBox.exec();
}
