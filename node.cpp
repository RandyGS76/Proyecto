#include "node.h"

Node::Node(char value, double amount){
    this->value = value;
    this->amount = amount;
    this->leftChild = NULL;
    this->rightChild = NULL;
    this->next = NULL;
}

char Node::findValueInTree(std::string *paths){
    return this->findValueInTreeAux(paths, this);
}

char Node::findValueInTreeAux(std::string *paths, Node *tree){
    if (tree->value != NULL){
        return tree->value;
    }

    bool isRightChild = (*paths).front() == '1';

    (*paths).erase(0, 1);

    if (isRightChild){
        return findValueInTreeAux(paths, tree->rightChild);
    }

    return findValueInTreeAux(paths, tree->leftChild);
}

std::string Node::getAmountInTree(char value){
    std::string rst = getAmountInTreeAux(value, this);
    rst.pop_back();
    return rst;
}

std::string Node::getAmountInTreeAux(char value, Node *tree){
    if (tree == NULL){
        return "";
    }

    if (tree->value == value){
        return std::string(1, value);
    }

    std::string left = getAmountInTreeAux(value, tree->leftChild);

    if (left.back() == value){
        return  "0" + left;
    }

    std::string right = getAmountInTreeAux(value, tree->rightChild);

    return "1" + right;
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

void Node::setAmount(double amount){
    this->amount = amount;
}

double Node::getAmount(){
    return this->amount;
}

char Node::getValue(){
    return this->value;
}

void Node::setValue(char value){
    this->value = value;
}

Node * Node::getLeftChild(){
    return this->leftChild;
}

Node * Node::getRightChild(){
    return this->rightChild;
}
