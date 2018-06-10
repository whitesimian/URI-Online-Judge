#include "bits/stdc++.h"
#define f(inicio, fim) for(int i = inicio; i < fim; i++)
#define ff(inicio, fim) for(int j = inicio; j < fim; j++)
#define fff(inicio, fim) for(int k = inicio; k < fim; k++)
#define print(vetor) for(auto elem : vetor) cout << elem << " "

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    int canos[2001], prom[5001];
    f(0, c + 1){
        canos[i] = 0;
        prom[i] = 0;
    }

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        prom[a] = max(prom[a], b);
    }

    f(0, n){ // Para cada promocao
        if(prom[i] > 0)
            for(int j = 0; j + i <= c; j++){
                canos[j + i] = max(canos[j + i], canos[j] + prom[i]);
            }
    }

    cout << canos[c] << "\n";

    return 0;
}
