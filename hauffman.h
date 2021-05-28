#ifndef HAUFFMAN_H
#define HAUFFMAN_H

#include <string>
#include <node.cpp>
#include <map>
#include <list>

class Hauffman
{
public:
    Hauffman();

    Node generateTree(std::string text);
    std::map<std::string, int> generateMap(std::string text);
    std::list<Node> generateList(std::map<std::string, int> mapa);
};

#endif // HAUFFMAN_H
