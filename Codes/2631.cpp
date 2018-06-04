#include "bits/stdc++.h"
#define f(inicio, fim) for(int i = inicio; i < fim; i++)
#define ff(inicio, fim) for(int j = inicio; j < fim; j++)
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

void uniao(int v1, int v2){
    int grupo1 = busca(v1);
    int grupo2 = busca(v2);
    if(grupo1 != grupo2)
    {
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
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    bool entrou = false;

    while(cin >> n >> m >> q){
        if(entrou)
            cout << "\n";
        entrou = true;
        subset.resize(n + 1);
        f(0, n + 1){
            subset[i].pai = i;
            subset[i].rank = 0;
        }
        f(0, m){
            int a, b;
            cin >> a >> b;
            uniao(a, b);
        }
        f(0, q){
            int a, b;
            cin >> a >> b;
            if(busca(a) == busca(b))
                cout << "S\n";
            else
                cout << "N\n";
        }
    }

return 0;
}
