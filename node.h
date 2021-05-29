#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>

class Node
{
private:
    Node * next;
    Node * leftChild;
    Node * rightChild;
    char value;
    double amount;
public:
    Node(char value, double amount);

    void add(Node * next);
    void addLeftChild(Node * child);
    void addRightChild(Node * child);

    char getValue();
    double getAmount();
    void setValue(char value);
    void setAmount(double amount);
    char findValueInTree(std::string * paths);
    char findValueInTreeAux(std::string * paths, Node * tree);
    std::string getAmountInTree(char value);
    std::string getAmountInTreeAux(char value, Node * tree);

    Node * getLeftChild();
    Node * getRightChild();
};

#endif // NODE_H
