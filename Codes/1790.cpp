#include "bits/stdc++.h"
#define fr(inicio, fim) for(int i = inicio; i < fim; i++)
#define frr(inicio, fim) for(int j = inicio; j < fim; j++)
#define frrr(inicio, fim) for(int k = inicio; k < fim; k++)

using namespace std;

int c, p, quantos;
bool grafo[51][51], marcado[51];

void dfs(int vertice){
    marcado[vertice] = true;
    quantos++;

    fr(1, c + 1){
        if(grafo[vertice][i] && !marcado[i])
            dfs(i);
    }
}

int main ()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    while(cin >> c >> p){
        vector< pair<int, int> > aresta;
        fr(1, c + 1){
            frr(1, c + 1)
                grafo[i][j] = false;
        }
        fr(0, p){
            int a, b;
            cin >> a >> b;
            aresta.push_back(pair<int, int>(a, b));
            grafo[a][b] = true;
            grafo[b][a] = true;
        }

        int quant = 0;
        for(auto elem : aresta){
            fr(1, c + 1)
                marcado[i] = false;
            quantos = 0;
            grafo[elem.first][elem.second] = false;
            grafo[elem.second][elem.first] = false;
            dfs(1);
            if(quantos != c)
                quant++;
            grafo[elem.first][elem.second] = true;
            grafo[elem.second][elem.first] = true;
        }
        cout << quant << "\n";
    }

  return 0;
}
