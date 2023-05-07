#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
    stack <int> pilha_1;
    stack <int> pilha_2;
    int aux;
    // vamos supor uma uma sequecia de dados de tamanho 5 para cada pilha
    for(int i = 1; i <= 5; i++)
    {
        pilha_1.push(i);
    }
    for(int i = 6; i <= 10; i++)
    {
        pilha_2.push(i);
    }
    aux = pilha_2.size();
    //pilha 2 para pilha 1
    while(!pilha_2.empty())
    {
        pilha_1.push(pilha_2.top());
        pilha_2.pop();
    }
    /*nao entendi se essa inverter a ordem de inclusao
    seja em relaçao apenas da pilha 2 para a 1 ou se é 
    da pilha 1 inteira, o que entendi foi que era a pilha 1 inteira
    vou fazer assim*/
    vector <int> invertendo;
    //passando elementos da pilha 1 para o vector auxiliar invertendo
    while(!pilha_1.empty())
    {
        invertendo.push_back(pilha_1.top());
        pilha_1.pop();
    }
    //voltando os elementos para a pilha 1. Agora estao todos invertidos!
    for(int i = 0; i < invertendo.size(); i++)
    {
        pilha_1.push(invertendo.at(i));
    }
    //passando a quantidade de elementos iniciais da pilha 2 para ela
    for(int i = 0; i < aux; i++)
    {
        pilha_2.push(pilha_1.top());
        pilha_1.pop();
    }
    // printando em formato de pilha fica assim:
    cout << "Pilha 1: \n";
    while(!pilha_1.empty())
    {
        cout << pilha_1.top() << "\n";
        pilha_1.pop();
    }
    cout << "Pilha 2: \n";
    while(!pilha_2.empty())
    {
        cout << pilha_2.top() << "\n";
        pilha_2.pop();
    }
    //lembrando que as pilhas estao sendo printadas seguindo o pricipio do FILO
    // First in, last out.
    return 0;
}