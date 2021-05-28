#include "hauffman.h"

bool Huffman::compare_huffman(Node * first, Node * second){
    return first->getAmount() > second->getAmount() && first->getValue() > second->getValue();
}

Huffman::Huffman()
{
}

// Genera el mapa de caracteres
// O(n)
std::map<char, int> Huffman::generateMap(std::string text){
    std::map<char, int> mapa;

    for (std::string::size_type i = 0; i < text.size(); i++){
        mapa[text[i]]++;
    }

    return mapa;
}

// Generate the list and sort it by its rep and char
// O(n*logn)
std::list<Node*> Huffman::generateList(std::map<char, int> mapa){
    std::list<Node*> lista;

    for (std::map<char, int>::iterator data = mapa.begin(); data != mapa.end(); data++){
        Node * node = new Node(data->first, data->second);

        lista.push_back(node);
    }

    lista.sort(Huffman::compare_huffman);

    return lista;
}

// Obtiene la probabilidad total
// O(n)
int Huffman::getTotalProb(std::list<Node *> lista){
    int total = 0;

    for (auto el = lista.begin(); el != lista.end(); el++){
        total += (*el)->getAmount();
    }

    return total;
}

// Genera el arbol de codigos Huffman
// O(n*logn)
Node * Huffman::generateTree(std::string text){
    std::map<char, int> mapa = generateMap(text); // O(n)
    std::list<Node*> nodes = generateList(mapa); // O(n*logn)
    int totalProb = text.size();

    // O(n)
    while (nodes.size() != 1){
        Node* first = nodes.front();
        nodes.pop_front();

        Node * second = nodes.front();
        nodes.pop_front();

        if (first->getValue() != NULL){
            first->setAmount(first->getAmount() / totalProb);
        }

        if (second->getValue() != NULL){
            second->setAmount(second->getAmount() / totalProb);
        }

        double prob = first->getAmount() + second->getAmount();

        Node * newNode = new Node(NULL, prob);

        newNode->addLeftChild(first);
        newNode->addRightChild(second);

        nodes.push_back(newNode);
    }

    // Total O(n*logn + 2n) => (n*logn)
    return nodes.front();
}
