#ifndef HAUFFMAN_H
#define HAUFFMAN_H

#include <string>
#include <node.cpp>
#include <map>
#include <list>
#include <iostream>
#include <math.h>

class Huffman
{
public:
    Huffman();

    Node * generateTree(std::string text);
    int getTotalProb(std::list<Node*> lista);
    std::map<char, int> generateMap(std::string text);
    std::list<Node*> generateList(std::map<char, int> mapa);
    static bool compare_huffman(Node * first, Node * second);
    std::list<unsigned char> toBinary(std::string binaryText);
    std::string decodeBinary(std::list<unsigned char> data);
    std::string toBinaryText();
};

#endif // HAUFFMAN_H
