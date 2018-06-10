#include "bits/stdc++.h"
#define f(inicio, fim) for(int i = inicio; i < fim; i++)
#define ff(inicio, fim) for(int j = inicio; j < fim; j++)
#define fff(inicio, fim) for(int k = inicio; k < fim; k++)
#define print(vetor) for(auto elem : vetor) cout << elem << " "

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    fff(0, t){
        int n, m;
        cin >> n >> m;
        vector<int> blocos(n);
        vector<int> res;
        res.assign(m + 1, INT_MAX);
        res[0] = 0;

        f(0, n)
            cin >> blocos[i];
        f(0, n){ // For each block size
            ff(0, m + 1){
                if(j + blocos[i] <= m && res[j] != INT_MAX)
                    res[j + blocos[i]] = min(res[j + blocos[i]], res[j] + 1);
            }
        }
        cout << res[m] << "\n";
    }

    return 0;
}
