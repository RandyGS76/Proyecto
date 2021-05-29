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
    // Creas una instancia de Huffman
    Huffman * h = new Huffman();
    // Le pasas el texto
    std::string x = "Esto es un ejemplo mas complejo con muchas palabras\n Un salto de linea cabron, etc, etc";

    // Llamas a generate map y luego generate CSV
    std::map<char, int> z = h->generateMap(x);
    std::string csv = h->generateCSV(z);

    h->save_file("ejemplo.csv", csv);

    // Si queres recuperar ese CSV, llamas a decodeCSV
    std::list<std::list<std::string>> data = h->decodeCSV("ejemplo.csv");

    z = h->decodedCSVToMap(data);

    // Para generar los codigos de Huffman (el arbol) generateTree
    Node * tree = h->generateTree(x);
    // generateBinString genera el string de binarios. Ej: "10101010"
    std::string rst = h->generateBinString(tree, x);

    // Para guardar el .cfh, tenes esta lista de bytes
    // Llamando a toBinary y le pasas el string de binarios
    std::list<unsigned char> lista = h->toBinary(rst);

    std::string cfh = "";

    for (auto it = lista.begin(); it != lista.end(); it++){
        cfh += (*it);
    }

    h->save_file("resultado.cfh",cfh);

    // Cuando leas el archivo .cfh y lo dejes en una lista de bytes (std::list<unsigned char>)
    // decodeBinary lo deja en formato: "101010101000"
    rst = h->decodeBinary(lista);
    // decodeBinString desencripta
    rst = h->decodeBinString(tree, rst);
    std::cout << rst << std::endl;

    return 0;
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
}
