#include <iostream>
#include <vector> //biblioteca para incluir vector
#include <cstdlib> // biblioteca para gerar numeros aleatorios

using namespace std;

void inverterLista(vector <int> n, int j) // função para inverter uma dada lista 
{
    if(j >= 0)
    {
        cout << n.at(j) << " ";
        inverterLista(n, j - 1);
    }
}

int main()
{
    vector <int> numeros;
    int size;
    cin >> size;
    cout << "Lista normal:" << "\n";
    for(int i = 0; i < size; i++)
    {
        srand(i); /* essa função vai garantir que o numero "aleatorio" a cada execução nao seja
        igual ao anterior*/ 
        numeros.push_back(rand()); // rand: gerador de numeros aleatorios
        cout<< numeros.at(i) << " ";
    }
    cout << endl;
    cout << "Lista invertida:" << "\n";
    inverterLista(numeros, size - 1);
    return 0;
}