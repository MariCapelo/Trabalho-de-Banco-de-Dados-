#include <stdio.h>
#include<stdlib.h>
typedef struct Node Node;

int elem = 0;
int maior = 0, menor = 0, qfolhas = 0;
int cont_null = 0, cont_3 = 0;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

// criação e inserção do no 
Node* creat_node(Node* newNode, int data)
{
    //newNode = new Node();
    if(newNode == NULL)
    {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode-> left = NULL;
        newNode-> right = NULL;
        elem++;
        printf("O conteudo foi inserido!\n");
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
        return newNode;
    }
}

void search(Node* node, int num)
{
    if(node == NULL)
    {
        printf("O numero NAO esta na arvore :(\n");
        return;
    }

    if(node->data == num)
    {
        printf("O numero esta na arvora :D\n");
    }
    else if(num > node->data)
    {
        search(node->right, num);
    }
    else if(num < node->data)
    {
        search(node->left, num);
    }
}

void em_ordem(Node* node)
{
    if(node->left != NULL)
    {
        em_ordem(node->left);
    }
    else
    {
        cont_null++;
    }
    printf("%d ", node->data);
    if(node->right != NULL)
    {
        em_ordem(node->right);
    }
    else
    {
        cont_null++;
    }
}

void pos_ordem(Node* node)
{
    if(node->left != NULL)
    {
        pos_ordem(node->left);
    }
    if(node->right != NULL)
    {
        pos_ordem(node->right);
    }
    printf("%d ", node->data);
}

void pre_ordem(Node* node)
{
    if(node->data > maior)
    {
        maior = node->data;
    }

    if (node->data < menor)
    {
        if(menor == 0)
        {
            menor = node->data;
        }
        menor = node->data;
    }

    printf("%d ", node->data);
    if(node->left != NULL)
    {
        pre_ordem(node->left);
    }
    if(node->right != NULL)
    {
        pre_ordem(node->right);
    }
    
}

void e_mult(Node* node)
{
    if(node->data%3 == 0)
    {
        cont_3++;
    }
    if(node->left != NULL)
    {
        pre_ordem(node->left);
    }
    if(node->right != NULL)
    {
        pre_ordem(node->right);
    }
}

void folhas(Node* node)
{
    if(node-> left == NULL && node->right == NULL)
    {
        qfolhas++;
    }

    if(node->left != NULL)
    {
        pre_ordem(node->left);
    }
    if(node->right != NULL)
    {
        pre_ordem(node->right);
    }
}

int alturaArvore(Node* node) {
    if (node == NULL) 
    {
        return 0;
    } 
    else 
    {
        int alturaEsquerda = alturaArvore(node->left);
        int alturaDireita = alturaArvore(node->right);
        return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
    }
}

int main()
{
    Node* root = NULL;
    int quant_elementos, num;
    scanf("%d", &quant_elementos);
    float soma = 0;
    
    // A) leva para a função que cria nos e insere seu dado 
    while(quant_elementos--)
    {
        scanf("%d", &num);
        soma = soma + num;
        root = creat_node(root, num);
    }

    // I) mostra o numeros de elementos da arvore a partir da variavel global elem
    printf("O numero de elementos na arvore e: %d\n", elem);

    // C) procurar num elementos na arvore
    printf("Digite quantos numeros vc quer procurar\n");
    scanf("%d", &quant_elementos);
    while(quant_elementos--)
    {
        scanf("%d", &num);
        search(root, num);
    }

    // B) printando a arvores em diferentes ordens
    printf("- pre-ordem\n");
    pre_ordem(root);
    printf("\n- em ordem\n");
    em_ordem(root);
    printf("\n- pos_ordem\n");
    pos_ordem(root);

    /*D) pegando o maior e o menor elemento que são calculados na função de pós ordem,
        ou seja, agora basta printar*/
    printf("\nO numero menor e maior respectivamente sao: %d %d", menor, maior);

    // E) calculando a media dos elementos da arvore 
    printf("\nA media dos elementos e: %.2f", soma/elem);

    // F) pegando a quantidade total de NULLs da arvore 
    printf("\nA quantidade de NULLs e: %d", cont_null);

    // G) Printar a soma de todas as chaves 
    printf("\nA soma das chaves e: %f", soma);

    // H) Retornar o número de nós cujas chaves são múltiplas de 3
    e_mult(root);
    printf("\nO numero de chaves multiplas de 3 e: %d\n", cont_3);

    // J) retornar o nuemro de folhas na arvore 
    folhas(root);
    printf("O numero de nos folhas na arvore e: %d\n", qfolhas);

    // K) verificar qual a altura da arvore
    printf("%d", alturaArvore(root));

    // L) Verificar se a árvore é estritamente binária
        // Percebemos pela struct Node que os nós apenas possuem 3 componentes neles que sao:
        // - a chave do no (dado)
        // - um ponteiro para o filho esquedor do no
        // - e um ponteiro para o filho direito do no
        // Assim como existe apenas dois ponteiros para cada um dos filho do no criado,
        // a arvore é estritamente binaria
    return 0;
}