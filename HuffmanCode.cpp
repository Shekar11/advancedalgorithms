#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class HuffmanNode
{
public:
    char data;
    int freq;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }

    ~HuffmanNode()
    {
        delete left;
        delete right;
    }
};

class CompareNodes
{
public:
    bool operator()(HuffmanNode *a, HuffmanNode *b)
    {
        return a->freq > b->freq;
    }
};

HuffmanNode *generateHuffmanTree(char data[], int freq[], int size)
{
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNodes> pq;

    for (int i = 0; i < size; i++)
    {
        HuffmanNode *node = new HuffmanNode(data[i], freq[i]);
        pq.push(node);
    }

    while (pq.size() != 1)
    {
        HuffmanNode *left = pq.top();
        pq.pop();
        HuffmanNode *right = pq.top();
        pq.pop();
        HuffmanNode *newNode = new HuffmanNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    return pq.top();
}

void generateHuffmanCodes(HuffmanNode *root, string code, vector<string> &codes)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        codes[root->data] = code;
        return;
    }

    generateHuffmanCodes(root->left, code + "0", codes);
    generateHuffmanCodes(root->right, code + "1", codes);
}

void printHuffmanCodes(vector<string> codes)
{
    for (int i = 0; i < codes.size(); i++)
    {
        if (codes[i] != "")
        {
            cout << (char)i << ": " << codes[i] << endl;
        }
    }
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanNode *root = generateHuffmanTree(arr, freq, size);

    vector<string> codes(128, "");
    generateHuffmanCodes(root, "", codes);

    printHuffmanCodes(codes);

    delete root;

    return 0;
}
