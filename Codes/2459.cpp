#include "bits/stdc++.h"
#define f(inicio, fim) for(int i = inicio; i < fim; i++)
#define ff(inicio, fim) for(int j = inicio; j < fim; j++)
#define fff(inicio, fim) for(int k = inicio; k < fim; k++)
#define print(vetor) for(auto elem : vetor) cout << elem << " "

using namespace std;

struct SubsetPair{
    int pai;
    int rank;
};

vector<SubsetPair> subset;

int busca(int valor){
    if(subset[valor].pai != valor)
        subset[valor].pai = busca(subset[valor].pai);
    return subset[valor].pai;
}

void uniao(int grupo1, int grupo2){

    if(subset[grupo1].rank < subset[grupo2].rank)
        subset[grupo1].pai = grupo2;
    else if(subset[grupo1].rank > subset[grupo2].rank)
        subset[grupo2].pai = grupo1;
    else
    {
        subset[grupo1].pai = grupo2;
        subset[grupo2].rank++;
    }
}

struct Edge{
    int a, b, c;
};

vector< vector< pair<int, int> > > arvore_min;
vector<bool> visitado;

bool dfs(int vertice, int& maior, int ultimo, int goal){
    if(vertice == goal)
        return true;

    for(auto elem : arvore_min[vertice]){
        if(elem.first != ultimo){
            if(dfs(elem.first, maior, vertice, goal)){
                maior = max(maior, elem.second);
                return true;
            }
        }
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, rr;
    cin >> n >> r >> rr;
    subset.resize(n + 1);

    vector<Edge> aresta_f(r), aresta_r(rr);

    f(0, r)
        cin >> aresta_f[i].a >> aresta_f[i].b >> aresta_f[i].c;
    f(0, rr)
        cin >> aresta_r[i].a >> aresta_r[i].b >> aresta_r[i].c;


    sort(aresta_f.begin(), aresta_f.end(), [](const Edge& a, const Edge& b){
            return a.c < b.c;
         });

    sort(aresta_r.begin(), aresta_r.end(), [](const Edge& a, const Edge& b){
            return a.c < b.c;
         });

    f(0, n + 1){
        subset[i].pai = i;
        subset[i].rank = 0;
    }

    long long int minimo = 0;

    ff(0, r){
        int g1 = busca(aresta_f[j].a);
        int g2 = busca(aresta_f[j].b);

        if(g1 != g2){
            minimo += aresta_f[j].c;
            uniao(g1, g2);
        }
    }

    ff(0, rr){
        int g1 = busca(aresta_r[j].a);
        int g2 = busca(aresta_r[j].b);

        if(g1 != g2){
            minimo += aresta_r[j].c;
            uniao(g1, g2);
        }
    }

    cout << minimo << "\n";

return 0;
}
