#include "bits/stdc++.h"
#define f(inicio, fim) for(int i = inicio; i < fim; i++)
#define ff(inicio, fim) for(int j = inicio; j < fim; j++)
#define fff(inicio, fim) for(int k = inicio; k < fim; k++)

using namespace std;

set<string> lista;
unordered_set<string> listado;

void funcao(string texto){
    if(texto.size()==0)
        return;

    lista.insert(texto);
    listado.insert(texto);

    string aux = texto;

    f(0,texto.size())
    {
        texto.erase(texto.begin()+i);
        if(listado.find(texto) == listado.end())
            funcao(texto);
        texto = aux;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string texto;

    while(cin>>texto)
    {
        lista.clear();
        listado.clear();
        funcao(texto);
        for(set<string>::iterator it = lista.begin();it!=lista.end();it++)
            cout<<*it<<"\n";
        cout<<"\n";
    }

    return 0;
}
