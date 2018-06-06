#include "bits/stdc++.h"
#define fr(inicio, fim) for(int i = inicio; i < fim; i++)
#define frr(inicio, fim) for(int j = inicio; j < fim; j++)
#define frrr(inicio, fim) for(int k = inicio; k < fim; k++)

using namespace std;


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, foo;
    while(cin >> n && n){
        vector<char> vetor, fim;
        stack<char> pilha;

        fr(0, n){
            char letra;
            cin >> letra;
            vetor.push_back(letra);
        }
        string res = "";
        fr(0, n){
            char letra;
            cin >> letra;
            fim.push_back(letra);
        }

        int pos = 0, posfim = 0;
        bool possivel = true;

        while(posfim < n){
            while(pilha.size() > 0 && pilha.top() == fim[posfim]){
                pilha.pop();
                res += "R";
                posfim++;
            }

            while(vetor[pos] != fim[posfim] && pos < n){
                pilha.push(vetor[pos]);
                res += "I";
                pos++;
            }

            if(pos < n){
                res += "IR";
                pos++;
                posfim++;
            }
            else if(pilha.size() > 0 && fim[posfim] == pilha.top()){
                res += "R";
                pilha.pop();
                posfim++;
            }
            else if(pilha.size() > 0){
                possivel = false;
                break;
            }
        }
        cout << res;
        if(!possivel)
            cout << " Impossible";
        cout << "\n";
    }

  return 0;
}
