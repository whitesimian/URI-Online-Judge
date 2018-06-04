#include "bits/stdc++.h"
#define fr(inicio, fim) for(int i = inicio; i < fim; i++)
#define frr(inicio, fim) for(int j = inicio; j < fim; j++)
#define frrr(inicio, fim) for(int k = inicio; k < fim; k++)

using namespace std;
typedef unsigned long long int ull;

typedef enum{white, gray, black} tipo;

unordered_map<int, pair<tipo, list<int> > > grafo;
int vetor[1001];
bool ciclo;

int dfs(const int& value){
    if(grafo[value].first == black)
        return vetor[value];
    if(grafo[value].first == gray)
    {
        ciclo = true;
        return 0;
    }

    grafo[value].first = gray;

    if(grafo[value].second.size() == 0)
    {
        grafo[value].first = black;
        vetor[value] = 1;
        return 1;
    }

    for(auto elem : grafo[value].second)
    {
        int retorno = dfs(elem);
        vetor[value] = max(vetor[value], retorno + 1);
    }
    grafo[value].first = black;
    return vetor[value];
}

int main (){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n)
    {
        fr(0, n + 1) vetor[i] = 0;
        grafo.clear();
        ciclo = false;

        fr(0, n)
        {
            int q;
            cin >> q;
            grafo[i + 1].first = white;
            frr(0, q)
            {
                int num;
                cin >> num;
                grafo[i + 1].second.push_front(num);
            }

        }

        fr(1, n + 1)
        {
            if(grafo[i].first == white)
                dfs(i);
        }
        if(ciclo)
            cout << "-1\n";
        else
            cout << *max_element(vetor, vetor + n + 1) << "\n";
    }

  return 0;
}
