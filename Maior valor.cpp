#include <bits/stdc++.h>

using namespace std;

string soma(string a)
{
    string b = "0";
    for(int j = 0; j < a.size(); j++)
    {
        b = b + a[j];
    }
    return b;
}

int main()
{
    int n, m, num;
    string N, s;
    cin >> n >> m >> s;
    num = 0;
    for(int i = n; i <= m; i++)
    {
        N = "i";
        if(soma(N) == s)
        {
            if(num < i)
            {
                num = i;
                cout << num << endl;
            }
        }
    }
    cout << num;
    return 0;
}