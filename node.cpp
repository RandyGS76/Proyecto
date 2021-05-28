#include "node.h"

Node::Node(std::string value, int amount){
    this->value = value;
    this->amount = amount;
}

void Node::add(Node *next){
    this->next = next;
}

void Node::addLeftChild(Node *left){
    this->leftChild = left;
}

void Node::addRightChild(Node *right){
    this->rightChild = right;
}

void Node::setAmount(int amount){
    this->amount = amount;
}

int Node::getAmount(){
    return this->amount;
}
