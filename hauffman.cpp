#include "hauffman.h"

bool Huffman::compare_huffman(Node * first, Node * second){
    return first->getAmount() > second->getAmount() && first->getValue() > second->getValue();
}

bool Huffman::save_file(std::string path, std::string data){
    std::fstream out;

    out.open(path, std::ios::out | std::ofstream::trunc);

    out << data;

    out.close();

    return true;
}

Huffman::Huffman()
{
}

// Convierte un mapa a un string
// O(n)
std::string Huffman::generateCSV(std::map<char, int> mapa){
    std::string rst = "Letra, Valor\n";

    for (std::map<char, int>::iterator data = mapa.begin(); data != mapa.end(); data++){
        Node * node = new Node(data->first, data->second);
        std::string value = std::to_string(data->second);

        rst += std::to_string(int(data->first)) + "," + value + "\n";
    }

    return rst;
}

// Convierte un CSV generado por el programa a un mapa
// O(n)
std::list<std::list<std::string>> Huffman::decodeCSV(std::string csvPath){
    std::list<std::list<std::string>> data;

    std::fstream fin;

    fin.open(csvPath, std::ios::in);

    std::string temp, line;

    while (std::getline(fin, line)){
        std::istringstream iss(line);

        std::list<std::string> row;
        std::string word;

        std::stringstream s(line);

        while (getline(s, word, ',')){
            row.push_back(word);
        }

        data.push_back(row);
    }

    return data;
}

// Convierte una lista decodificada de un CSV a un mapa
// O(n)
std::map<char, int> Huffman::decodedCSVToMap(std::list<std::list<std::string>> data){
    std::map<char, int> rst;

    for (auto it = data.begin(); it != data.end(); it++){
        if (it == data.begin()) continue;

        auto jt = (*it).begin();

        char letra = std::atoi((*jt).c_str());
        jt++;
        int value = std::atoi((*jt).c_str());
    }

    return rst;
}

// Codifica a un texto binario
// O(n)
std::string Huffman::generateBinString(Node *tree, std::string texto){
    std::string rst = "";

    for (auto it = texto.begin(); it != texto.end(); it++){
        rst += tree->getAmountInTree(*it);
    }

    return rst;
}

std::string Huffman::decodeBinString(Node *tree, std::string bin){
    std::string rst = "";

    while (bin.size() != 0){
        rst += tree->findValueInTree(&bin);
    }

    return rst;
}

// Genera una lista de bytes
// O(n)
std::list<unsigned char> Huffman::toBinary(std::string binaryText){
    std::list<unsigned char> lista;

    int k = 0;
    for (auto it = binaryText.end() - 1; it != binaryText.begin() - 1; it--){
        if (k % 8 == 0){
            lista.push_front(0);
        }

        unsigned char value = ((*it) == '1') ? 1 : 0;
        lista.front() += value * std::pow(2, k % 8);

        k++;
    }

    if (binaryText.size() % 8 == 0){
        lista.push_front(0);
    }

    lista.front() += std::pow(2, binaryText.size() % 8);

    return lista;
}

// Dada una lista de bytes, lo decodifica a un string binario
// O(n)
std::string Huffman::decodeBinary(std::list<unsigned char> data){
    bool founded = false;
    std::string rst = "";
    std::string values[] = {"0", "1"};

    unsigned char current = 0;
    int total = data.size() * 8;

    for (int i = 0; i < total; i++){
        if (i % 8 == 0){
            current = data.front();
            data.pop_front();
        }

        unsigned char bin = current & 128;
        bin = bin >> 7;
        current = current << 1;

        if (founded){
            rst += values[bin];
        }

        if (bin == 1){
            founded = true;
        }
    }

    return rst;
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
