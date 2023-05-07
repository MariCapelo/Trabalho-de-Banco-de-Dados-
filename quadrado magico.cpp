#include <bits/stdc++.h>

using namespace std;

int main()
{
    int casos, q, quant_m;
    cin >> casos;
    for (int i = 1; i <= casos; i++)
    {
        cin >> q;
        int *rodas = new int[q];
        for(int j = 0; j < q; j++)
        {
            cin >> rodas[j];
        }
        for(int j = 0; j < q; j++)
        {
            cin >> quant_m;
            string movimentos;
            cin >> movimentos;
            for(int k = 0; k < movimentos.size(); k++)
            {
                if(movimentos[k] == 'U')
                {
                    movimentos[k] = 'D';
                }
                if(movimentos[k] == 'D')
                {
                    movimentos[k] = 'U';
                }
            }
            int a = 0;
            for(int k = movimentos.size() - 1; k >= 0; k--)
            {
                movimentos[a] = movimentos[k];
                a++;
            }
            for(int k = 0; k < movimentos.size(); k++)
            {
                if(movimentos[k] == 'U')
                {
                    if(rodas[j] == 9)
                    {
                        rodas[j] = 0;
                        continue;
                    }
                    rodas[j]++;
                }
                if(movimentos[k] == 'D')
                {
                    if(rodas[j] == 0)
                    {
                        rodas[j] = 9;
                        continue;
                    }
                    rodas[j]--;
                }
            }
        }
        for(int j = 0; j < q; j++)
        {
            if(j == q - 1)
            {
                cout << rodas[j] << endl;
                break;
            }
            cout << rodas[j] << " ";
        }
        delete[]rodas;
        rodas = NULL;
    }
    return 0;
}