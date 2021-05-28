#include "mainwindow.h"

#include <QApplication>
#include <hauffman.cpp>

void printTree(Node * tree){
    if (tree == NULL){
        return;
    }

    std::cout << "[ " << tree->getValue() << ", " << tree->getAmount() << " ]" << std::endl;

    printTree(tree->getLeftChild());
    printTree(tree->getRightChild());
}

int main(int argc, char *argv[])
{
    Huffman * h = new Huffman();
    std::string x = "abeja";

    Node * tree = h->generateTree(x);
    std::string rst = "";

    for (auto it = x.begin(); it != x.end(); it++){
        rst += tree->getAmountInTree(*it);
    }

    std::cout << "CODED: " << rst << std::endl;

    while (rst.size() != 0){
        std::cout << tree->findValueInTree(&rst);
    }

    std::cout << std::endl;

    return 0;
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
}
