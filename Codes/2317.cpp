#include "bits/stdc++.h"
#define f(inicio, fim) for(int i = inicio; i < fim; i++)
#define ff(inicio, fim) for(int j = inicio; j < fim; j++)
#define fff(inicio, fim) for(int k = inicio; k < fim; k++)
#define print(vetor) for(auto elem : vetor) cout << elem << " "

using namespace std;

int n, m;
bool visitado[251][251];
char matriz[252][252];

void dfs(int x, int y, bool& good, int& ovelhas, int& lobos){
    visitado[x][y] = true;

    if(good){
        if(matriz[x][y] == 'v')
            lobos++;
        else if(matriz[x][y] == 'k')
            ovelhas++;
    }

    if(x - 1 >= 0){
        if(!visitado[x - 1][y])
            dfs(x - 1, y, good, ovelhas, lobos);
    }
    else
        good = false;

    if(x + 1 < n){
        if(!visitado[x + 1][y])
            dfs(x + 1, y, good, ovelhas, lobos);
    }
    else
        good = false;

    if(y - 1 >= 0){
        if(!visitado[x][y - 1])
            dfs(x, y - 1, good, ovelhas, lobos);
    }
    else
        good = false;

    if(y + 1 < m){
        if(!visitado[x][y + 1])
            dfs(x, y + 1, good, ovelhas, lobos);
    }
    else
        good = false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    f(0, n){
        ff(0, m){
            cin >> matriz[i][j];
            if(matriz[i][j] == '#')
                visitado[i][j] = true;
        }
    }

    int total_lamb = 0, total_wolf = 0;
    f(0, n){
        ff(0, m){
            bool good = true;
            int lamb = 0, wolf = 0;
            if(!visitado[i][j]){
                dfs(i, j, good, lamb, wolf);
                if(good){
                    if(lamb > wolf)
                        total_lamb += lamb;
                    else
                        total_wolf += wolf;
                }
            }
        }
    }

    cout << total_lamb << " " << total_wolf << "\n";



return 0;
}
