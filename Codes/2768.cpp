#include "bits/stdc++.h"
#define fr(inicio, fim) for(int i = inicio; i < fim; i++)
#define frr(inicio, fim) for(int j = inicio; j < fim; j++)
#define frrr(inicio, fim) for(int k = inicio; k < fim; k++)

using namespace std;

struct Elem{
    int matriz[110][110];
};

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while(cin >> n >> m){
        vector<Elem> fw;
        fw.resize(110);
        fr(0, n + 1){
            frr(0, n + 1){
                frrr(0, n + 1){
                    fw[i].matriz[j][k] = INT_MAX;
                }
            }
        }

        fr(0, m){
            int a, b, c;
            cin >> a >> b >> c;
            frr(0, n + 1){
                fw[j].matriz[a][b] = c;
                fw[j].matriz[b][a] = c;
            }
        }

        for(int valor = 1; valor <= n; ++valor){
            frrr(1, valor + 1){ // k
                fr(1, n + 1){ // i
                    frr(1, n + 1){ // j
                        if(fw[valor].matriz[i][k] < 10000 && fw[valor].matriz[k][j] < 10000)
                            fw[valor].matriz[i][j] = min(fw[valor].matriz[i][j], fw[valor].matriz[i][k] + fw[valor].matriz[k][j]);
                    }
                }
            }
        }

        int quant;
        cin >> quant;
        fr(0, quant){
            int a, b, k;
            cin >> a >> b >> k;
            if(a == b)
                cout << "0\n";
            else if(fw[k].matriz[a][b] == INT_MAX)
                cout << "-1\n";
            else
                cout << fw[k].matriz[a][b] << "\n";
        }
    }

  return 0;
}
