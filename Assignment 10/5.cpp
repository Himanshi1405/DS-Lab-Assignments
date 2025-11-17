#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minKey(vector<int> key, vector<bool> inMST, int V) {
    int minVal = INT_MAX, index;
    for(int i=0; i<V; i++)
        if(!inMST[i] && key[i] < minVal)
            minVal = key[i], index = i;
    return index;
}

void prim(int V, vector<vector<int>>& graph) {
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    key[0] = 0;

    for(int i=0; i<V-1; i++) {
        int u = minKey(key, inMST, V);
        inMST[u] = true;

        for(int v=0; v<V; v++) {
            if(graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Prim MST:\n";
    for(int i=1; i<V; i++)
        cout << parent[i] << " -- " << i << " = " << graph[i][parent[i]] << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    prim(V, graph);
    return 0;
}
