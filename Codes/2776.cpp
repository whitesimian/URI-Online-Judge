#include "bits/stdc++.h"
#define fr(inicio, fim) for(int i = inicio; i < fim; i++)
#define frr(inicio, fim) for(int j = inicio; j < fim; j++)
#define frrr(inicio, fim) for(int k = inicio; k < fim; k++)

using namespace std;

int main() {

    int n, c;
    int prom[2001];

    while(cin >> n >> c)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int latas[2001];
        bool full[2001];
        fr(0, c + 1){
            latas[i] = 0;
            prom[i] = 0;
            full[i] = false;
        }
        full[0] = true;

        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            prom[a] = max(prom[a], b);
            full[a] = true;
        }

        fr(1, c + 1){
            for(int j = i; j >= 1; --j){
                if(full[i - j] && prom[j] != 0 && latas[i - j] + prom[j] > latas[i])
                {
                    latas[i] = latas[i - j] + prom[j];
                    full[i] = true;
                }
            }
        }

        cout << latas[c] << "\n";
    }

    return 0;
}
