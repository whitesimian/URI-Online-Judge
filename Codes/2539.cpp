#include "bits/stdc++.h"

using namespace std;

void intercala_merge(int vetor[], int esq, int meio, int dir, long long int& soma){

    int tam_a = meio - esq + 1;
    int tam_b = dir - meio;
    int *vetor_a = new int [tam_a];
    int *vetor_b = new int [tam_b];

    for(int i=0;i<tam_a;i++)
        vetor_a[i] = vetor[esq+i];
    for(int i=0;i<tam_b;i++)
        vetor_b[i] = vetor[meio+i+1];

    int i = 0,j = 0,pos = esq;
    while(i<tam_a&&j<tam_b)
    {
        if(vetor_a[i]>vetor_b[j]){
            if(pos-esq>i)
                soma+=pos-esq-i;
            vetor[pos++] = vetor_a[i++];
        }
        else{
            if(pos-esq>tam_a+j)
                soma+=pos-esq-(tam_a+j);
            vetor[pos++] = vetor_b[j++];
        }
    }


    while(i<tam_a){
        if(pos-esq>i)
            soma+=pos-esq-i;
        vetor[pos++] = vetor_a[i++];
    }
    while(j<tam_b){
        if(pos-esq>tam_a+j)
            soma+=pos-esq-(tam_a+j);
        vetor[pos++] = vetor_b[j++];
    }

    delete [] vetor_a;
    delete [] vetor_b;
}


long long int merge_sort(int vetor[], int tamanho){

    int b=1,esq,dir,meio;
    long long int soma = 0;
    while(b<tamanho)
    {
        esq = 0;
        while(esq+b<tamanho)
        {
            dir = esq + 2*b - 1;
            meio = esq + b - 1;
            if(dir>=tamanho)
                dir = tamanho-1;
            intercala_merge(vetor,esq,meio,dir,soma);
            esq = dir + 1;
        }
        b*=2;
    }
    return soma;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n;
    while(cin>>n){

        int *vetor = new int [n];
        for(int i=0;i<n;i++)
            cin>>vetor[i];
        n = merge_sort(vetor,n);
        cout << n << "\n";

        delete [] vetor;
    }

return 0;
}
