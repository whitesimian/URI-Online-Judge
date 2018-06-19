#include "bits/stdc++.h"
#define f(inicio, fim) for(int i = inicio; i < fim; i++)
#define ff(inicio, fim) for(int j = inicio; j < fim; j++)
#define fff(inicio, fim) for(int k = inicio; k < fim; k++)
#define print(vetor) for(auto elem : vetor) cout << elem << " "

using namespace std;

int n, m, c, matriz[1001][1001];

bool colunas(int col, bool sim){
    bool entrou = false;
    f(0, n){
        if(matriz[i][col] != 0){
            entrou = true;
            if(sim)
                return true;
        }
    }
    if(entrou)
        sim = true;
    else
        sim = false;
    if(col + 1 < m)
        return colunas(col + 1, sim);
    return false;
}

bool dist(int col){
    long long int pos = INT_MIN;
    f(0, n){
        if(matriz[i][col] == 1){
            if(i - pos <= c)
                return true;
            pos = i;
        }
    }

    pos = INT_MIN;
    f(0, n){
        if(matriz[i][col] == 2){
            if(i - pos <= c)
                return true;
            pos = i;
        }
    }

    if(col + 1 < m)
        return dist(col + 1);
    return false;
}

int main() {

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n >> m >> c;
    f(0, n)
    ff(0, m)
    cin >> matriz[i][j];


    if(colunas(0, false) || dist(0))
        cout << "N\n";
    else
        cout << "S\n";

    return 0;
}
