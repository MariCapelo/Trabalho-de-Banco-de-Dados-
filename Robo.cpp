#include <iostream>
#include <stack> // biblioteca da stack

using namespace std;

stack <int> somas; // stack universal para facilitar

int DeQuantosModos(int n)
{
    int modos = 0;
    if(n == 1)
    {
        while(!somas.empty())
        {
            if(somas.top() == 2)
            {
                modos++;
            }
            somas.pop();
        }
        return modos + 1; /* a quantidade de numeros 2 quue serão divididos
        em um + a formação inicial da stack antes de serem tirado elementos*/ 
    }
    if(n != 1)
    {
        if(n % 2 == 0)
        {
            somas.push(2);
            DeQuantosModos(n/2);
        }
        else if(n % 2 != 0)
        {
            somas.push(1);
            DeQuantosModos(n-1);
        }
    }
}

int main()
{
    int numero;
    cout << "Digite um numero: ";
    cin >> numero;
    cout << DeQuantosModos(numero);
    return 0;
}