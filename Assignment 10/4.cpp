#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int v, vector<int>& parent) {
    if(parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}

void kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(V);
    for(int i=0; i<V; i++) parent[i] = i;

    cout << "Kruskal MST:\n";
    int cost = 0;
    for(auto e : edges) {
        int p1 = findParent(e.src, parent);
        int p2 = findParent(e.dest, parent);

        if(p1 != p2) {
            cout << e.src << " -- " << e.dest << " = " << e.weight << endl;
            parent[p1] = p2;
            cost += e.weight;
        }
    }
    cout << "Total Cost = " << cost << endl;
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}
    };

    kruskal(V, edges);
    return 0;
}

