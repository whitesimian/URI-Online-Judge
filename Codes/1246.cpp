#include "bits/stdc++.h"
#define fr(inicio, fim) for(int i = inicio; i < fim; i++)
#define frr(inicio, fim) for(int j = inicio; j < fim; j++)
#define frrr(inicio, fim) for(int k = inicio; k < fim; k++)

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tam, n;
    while(cin >> tam >> n){
        vector<string> vaga;
        vaga.assign(tam, "0000");

        int quant = 0;
        map<string, int> m;

        fr(0, n){
            char op;
            int comp;
            string placa;
            cin >> op >> placa;
            if(op == 'C'){
                cin >> comp;
                m[placa] = comp;
                bool pode = false;

                frr(0, vaga.size()){
                    if(vaga[j] == "0000"){
                        int ini = j, cont = 0;
                        while(vaga[j] == "0000" && j < vaga.size() && cont < comp){
                            cont++;
                            j++;
                            if(j >= vaga.size())
                                break;
                        }

                        if(cont == comp){
                            pode = true;
                            frrr(ini, j)
                                vaga[k] = placa;
                            break;
                        }
                    }
                }
                if(pode)
                    quant++;
            }
            else{
                frr(0, vaga.size())
                    if(vaga[j] == placa)
                        vaga[j] = "0000";
            }
        }
        cout << quant * 10 << "\n";
    }

}
