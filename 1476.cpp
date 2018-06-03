#include "bits/stdc++.h"
#define f(inicio, fim) for(int i = inicio; i < fim; i++)
#define ff(inicio, fim) for(int j = inicio; j < fim; j++)
#define fff(inicio, fim) for(int k = inicio; k < fim; k++)
#define print(vetor) for(auto elem : vetor) cout << elem << " "

using namespace std;

struct SubsetPair{
    int pai;
    int rank;
};

vector<SubsetPair> subset;

// Union-find By Rank And Path Compression

int busca(int valor){
    if(subset[valor].pai != valor)
        subset[valor].pai = busca(subset[valor].pai);
    return subset[valor].pai;
}

void uniao(int grupo1, int grupo2){
    if(subset[grupo1].rank < subset[grupo2].rank)
        subset[grupo1].pai = grupo2;
    else if(subset[grupo1].rank > subset[grupo2].rank)
        subset[grupo2].pai = grupo1;
    else
    {
        subset[grupo1].pai = grupo2;
        subset[grupo2].rank++;
    }

}

vector<bool> visited;
vector<pair<int, int>> camadas;
vector< pair<int, pair<int, int>> > edge;
int n, m, s;

void min_weight_path(int node1, int node2, int& weight){ // Lowest Common Ancestor
    vector<int> s1, s2;

    int tmp1 = node1, tmp2 = node2;

    while(true){
        s1.push_back(tmp1);
        if(camadas[tmp1].first == 0)
            break;
        tmp1 = camadas[tmp1].first;
    }
    while(true){
        s2.push_back(tmp2);
        if(camadas[tmp2].first == 0)
            break;
        tmp2 = camadas[tmp2].first;
    }

    vector<int>::reverse_iterator it1 = s1.rbegin(), it2 = s2.rbegin();
    while(*it1 == *it2 && it1 != s1.rend() && it2 != s2.rend()){
        it1++;
        it2++;
    }
    --it1;
    --it2;
    int common = *it1;

    tmp1 = node1;
    tmp2 = node2;

    while(true){
        if(tmp1 == common)
            break;
        weight = min(weight, camadas[tmp1].second);
        tmp1 = camadas[tmp1].first;
    }

    while(true){
        if(tmp2 == common)
            break;
        weight = min(weight, camadas[tmp2].second);
        tmp2 = camadas[tmp2].first;
    }
}

struct Elem{
    int node, aresta, pai;

    Elem(int a, int b, int c) : node(a), aresta(b), pai(c) {};
};

stack<Elem> pilha;

void bfs(const vector< vector<pair<int, int>> >& tree, int root){
    visited.assign(n + 1, false);
    camadas.resize(n + 1);
    pilha.push(Elem(root, 0, 0)); // Layer zero
    visited[root] = true;

    while(pilha.size() > 0){
        Elem tmp = pilha.top();
        pilha.pop();

        int node = tmp.node;
        camadas[node] = {tmp.pai, tmp.aresta};

        for(auto aux : tree[node]){
            if(!visited[aux.first]){
                pilha.push(Elem(aux.first, aux.second, node));
                visited[aux.first] = true;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> m >> s){
        vector< vector<pair<int, int>> > max_spannig_tree(n + 1);

        subset.resize(n + 1);
        f(0, n + 1){
            subset[i].pai = i;
            subset[i].rank = 0;
        }

        f(0, m){
            int a, b, p;
            cin >> a >> b >> p;
            edge.push_back({a, {b, p}});
        }
        sort(edge.begin(), edge.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){
                return a.second.second > b.second.second;
             });

        f(0, m){
            int g1 = busca(edge[i].first);
            int g2 = busca((edge[i].second.first));
            if(g1 != g2){
                max_spannig_tree[edge[i].first].push_back(edge[i].second);
                max_spannig_tree[edge[i].second.first].push_back({edge[i].first, edge[i].second.second});
                uniao(g1, g2); // Merge groups
            }
        }

        bfs(max_spannig_tree, edge[0].first);
        edge.clear();

        f(0, s){
            int point1, point2;
            cin >> point1 >> point2;

            int weight = INT_MAX;
            min_weight_path(point1, point2, weight);
            cout << weight << "\n";
        }
    }

return 0;
}
