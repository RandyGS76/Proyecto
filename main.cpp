#include "mainwindow.h"

#include <QApplication>
#include <map>
#include <iostream>

int main(int argc, char *argv[])
{
    std::map<std::string, int> m;

    m["Hola"] = 1;

    if (m.find("Hola") != m.end()){
        std::cout << m["Hola"] << std::endl;
    }

    return 0;
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
}
