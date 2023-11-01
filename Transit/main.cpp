#include "login.h"

#include <QApplication>
#include <bits/stdc++.h>
#include <QTextCodec>
using namespace std;

vector<int> gragh[100005];

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);
    Login w;
    w.show();


    return a.exec();
}
