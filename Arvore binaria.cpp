#include <bits/stdc++.h>

using namespace std;

int elem = 0;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* creat_node(Node* newNode, int data)
{
    //newNode = new Node();
    if(newNode == NULL)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode-> left = newNode-> right = NULL;
        elem++;
        cout << "O conteudo foi inserido!" << endl;
        return newNode;
    }
    else
    {
        if(data > newNode -> data)
        {
            newNode -> right = creat_node(newNode->right, data);
        }
        if(data < newNode ->data)
        {
            newNode -> left = creat_node(newNode->left, data);
        }
    }
}

struct Node* search(struct Node* node, int data)
{
    
}

int main()
{
    Node* root = NULL;
    int quant_elementos, num;
    cin >> quant_elementos;
    //while(elem != quant_elementos)
    while(quant_elementos--)
    {
        cin >> num;
        root = creat_node(root, num);
    }

    cout << "Digite um numero para ver se ja possui na árvore" << endl;
    cin >> num;
    search(root, num); 
    return 0;
}