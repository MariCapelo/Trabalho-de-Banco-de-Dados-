#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // criaçao das 3 pilhas de caixas
    stack <int> A; 
    stack <int> B; 
    stack <int> C;
    int caixa, tam;
    //loop para cada caixa recebida
    while(cin >> caixa)
    {
        if(A.empty())
        {
            A.push(caixa);
        }
        tam = A.size();
        /* loop para ver se precisa mover outras caixas para alocar a 
            que chegou */
        for(int i = 0; i < tam; i++)
        {
            if(caixa > A.top())
            {
                if(caixa == 5)
                {
                    B.push(A.top());
                    A.pop();
                }
                if(caixa == 3)
                {
                    C.push(A.top());
                    A.pop();
                }
            }
            if(caixa <= A.top())
            {
                A.push(caixa);
                break;
            }
        }
        /* mover as caixas que precisaram sair da pilha A de 
           volta para ela*/
        while(!B.empty())
        {
            A.push(B.top());
            B.pop();
        }
        while(!C.empty())
        {
            A.push(C.top());
            C.pop();
        }

        /* SE QUISER SABER A SITUAÇÃO DA PILHA BASTA DESCOMETAR O CODIGO ABAIXO 
           E ,ASSIM, COMEÇAR TUDO DE NOVO DEPOIS*/ 

        // while(!A.empty())
        // {
        //     cout << A.top() << " ";
        //     A.pop();
        // }
    }
    return 0;
}