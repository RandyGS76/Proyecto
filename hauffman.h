#ifndef HAUFFMAN_H
#define HAUFFMAN_H

#include <string>
#include <node.cpp>
#include <map>
#include <list>
#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include <cstdlib>

class Huffman
{
public:
    Huffman();

    std::string generateCSV(std::map<char, int> mapa);
    std::list<std::list<std::string>> decodeCSV(std::string csv);
    std::map<char, int> decodedCSVToMap(std::list<std::list<std::string>> data);

    std::string toBinaryText();
    std::list<unsigned char> toBinary(std::string binaryText);
    std::string decodeBinary(std::list<unsigned char> data);

    int getTotalProb(std::list<Node*> lista);

    Node * generateTree(std::string text);

    std::string generateBinString(Node * tree, std::string texto);
    std::string decodeBinString(Node * tree, std::string bin);

    std::map<char, int> generateMap(std::string text);
    std::list<Node*> generateList(std::map<char, int> mapa);

    static bool compare_huffman(Node * first, Node * second);
    static bool save_file(std::string path, std::string data);
};

#endif // HAUFFMAN_H
