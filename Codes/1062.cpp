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
        vector<int> vetor;
        vector<bool> vbool;
        vbool.resize(n + 1);

        while(cin >> foo && foo){
            stack<int> pilha;
            fr(0, n + 1) vbool[i] = true;
            vetor.clear();

            vetor.push_back(foo);
            fr(1, n){
                cin >> foo;
                vetor.push_back(foo);
            }

            bool possivel = true;
            for(auto elem : vetor){
                if(!vbool[elem]){
                    if(pilha.top() == elem)
                        pilha.pop();
                    else{
                        possivel = false;
                        break;
                    }
                }
                else{
                    vbool[elem] = false;
                    fr(1, elem){
                        if(vbool[i]){
                            pilha.push(i);
                            vbool[i] = false;
                        }
                    }
                }
            }
            if(possivel)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        cout << "\n";
    }

  return 0;
}
