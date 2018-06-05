#include "bits/stdc++.h"
#define fr(inicio,fim) for(int i=inicio; i<fim; i++)
#define frr(inicio,fim) for(int j=inicio; j<fim; j++)
#define frrr(inicio,fim) for(int k=inicio; k<fim; k++)

#define PI 3.14159265358979323846

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    double angulo = (2.0 * PI) / n;
    int vetor[100001];
    fr(0, n)
        cin >> vetor[i];

    sort(vetor, vetor + n, [](const int& a, const int& b){return a > b;});
    list<int> lista;
    bool lado = true;
    fr(0, n)
    {
        if(lado)
        {
            lista.push_back(vetor[i]);
            lado = false;
        }
        else
        {
            lista.push_front(vetor[i]);
            lado = true;
        }
    }


    vector<double> x, y;
    double arc = 0;
    for(auto elem : lista)
    {
        x.push_back((double)elem * cos(arc));
        y.push_back((double)elem * sin(arc));
        arc += angulo;
    }
    double soma1 = 0, soma2 = 0;
    fr(1, n)
    {
        soma1 += x[i - 1] * y[i];
        soma2 += y[i - 1] * x[i];
    }
    soma1 += x[n - 1] * y[0];
    soma2 += y[n - 1] * x[0];

    double res = abs((soma1 - soma2) / 2);
    cout << fixed << setprecision(3) << res << "\n";

    return 0;
}
