#include <iostream>
#include <vector>
 
using namespace std;

void inserir(int ordenado[], int tamanho, int elemento){

    int i = tamanho - 1;
    while(elemento<ordenado[i] && i>=0)
    {
        ordenado[i+1] = ordenado[i];
        i--;
    }
    ordenado[i+1] = elemento;
}
 
int main() {
 
    int n;
    while(cin>>n)
    {
        bool prioridade = true, fila = true, pilha = true;
        bool impossivel = false;

        vector<int> vetor;
        vetor.clear();

        int ordenado[1001], tam = 0;

        for(int i=0;i<n;i++)
        {
            int op,elem;
            cin>>op>>elem;

            if(!impossivel)
            {
                if(op==1)
                {
                    vetor.push_back(elem);
                    if(prioridade)
                    {
                        inserir(ordenado,tam,elem);
                        tam++;
                    }
                }
                else //RETIRAR
                {
                    if(vetor.size()==0)
                    {
                        impossivel = true;
                        continue;
                    }

                    if(prioridade)
                    {
                        if(elem == ordenado[tam-1])
                            tam--;
                        else
                            prioridade = false;
                    }

                    if(vetor.size()==1)
                    {
                        if(elem == vetor[0])
                            vetor.erase(vetor.begin());
                        else
                        {
                            impossivel = true;
                            continue;
                        }
                    }
                    else
                    {
                        if(elem == vetor[0])
                        {
                            pilha = false;
                            vetor.erase(vetor.begin());
                        }
                        else if(elem == vetor[vetor.size()-1])
                        {
                            fila = false;
                            vetor.erase(vetor.begin()+vetor.size()-1);
                        }
                        else if(prioridade)
                        {
                            pilha = false;
                            fila = false;
                        }
                        else if(!prioridade)
                            impossivel = true;
                    }
                }
            }
        }

        if(impossivel)
            cout << "impossible\n";
        else
        {
            if(fila && !pilha && !prioridade)
                cout<<"queue\n";
            else if(pilha && !fila && !prioridade)
                cout<<"stack\n";
            else if(prioridade && !fila && !pilha)
                cout<<"priority queue\n";
            else
                cout<<"not sure\n";
        }
    }
 
    return 0;
}