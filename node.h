#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
private:
    Node * next;
    Node * leftChild;
    Node * rightChild;
    std::string value;
    int amount;
public:
    Node(std::string, int amount);
    void add(Node * next);
    void addLeftChild(Node * child);
    void addRightChild(Node * child);
    void setAmount(int amount);
    int getAmount();
};

#endif // NODE_H
