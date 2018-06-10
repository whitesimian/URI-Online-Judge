#include "bits/stdc++.h"
#define f(inicio, fim) for(int i = inicio; i < fim; i++)
#define ff(inicio, fim) for(int j = inicio; j < fim; j++)
#define fff(inicio, fim) for(int k = inicio; k < fim; k++)
#define print(vetor) for(auto elem : vetor) cout << elem << " "

using namespace std;

int matriz[5][5];
bool visitado[5][5];

bool dfs(int x, int y){
    visitado[x][y] = true;
    if(x == 4 && y == 4)
        return true;

    if(x + 1 < 5)
        if(matriz[x + 1][y] == 0 && !visitado[x + 1][y])
            if(dfs(x + 1, y))
                return true;
    if(y + 1 < 5)
        if(matriz[x][y + 1] == 0 && !visitado[x][y + 1])
            if(dfs(x, y + 1))
                return true;
    if(x - 1 >= 0)
        if(matriz[x - 1][y] == 0 && !visitado[x - 1][y])
            if(dfs(x - 1, y))
                return true;
    if(y - 1 >= 0)
        if(matriz[x][y - 1] == 0 && !visitado[x][y - 1])
            if(dfs(x, y - 1))
                return true;
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    fff(0, t){
        f(0, 5)
        ff(0, 5){
            cin >> matriz[i][j];
            visitado[i][j] = false;
        }

        if(dfs(0, 0))
            cout << "COPS\n";
        else
            cout << "ROBBERS\n";
    }

    return 0;
}
