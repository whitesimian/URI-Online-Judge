#include "bits/stdc++.h"
#define f(inicio, fim) for(int i = inicio; i < fim; i++)
#define ff(inicio, fim) for(int j = inicio; j < fim; j++)
#define fff(inicio, fim) for(int k = inicio; k < fim; k++)
#define print(vetor) for(auto elem : vetor) cout << elem << " "

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> vetor(n);
    f(0, n)
        cin >> vetor[i];

    int pos = 0, maior, biggest = 1;
    while(pos < n){
        maior = vetor[pos];
        while(pos - maior < -1) maior--;
        while(pos + maior > n) maior--;

        if(maior > 1){
            f(1, maior){
                if(vetor[pos - i] < maior - i){
                    maior = vetor[pos - i] + i;
                }
                if(vetor[pos + i] < maior - i){
                    maior = vetor[pos + i] + i;
                }
            }
        }
        biggest = max(biggest, maior);
        pos++;
    }
    cout << biggest << "\n";

    return 0;
}
