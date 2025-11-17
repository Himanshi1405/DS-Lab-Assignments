#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minDist(vector<int>& dist, vector<bool>& visited, int V){
    int minVal = INT_MAX, index;
    for(int i=0; i<V; i++)
        if(!visited[i] && dist[i] < minVal)
            minVal = dist[i], index = i;
    return index;
}

void dijkstra(int V, vector<vector<int>>& graph, int src){
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    dist[src] = 0;

    for(int i=0; i<V-1; i++){
        int u = minDist(dist, visited, V);
        visited[u] = true;

        for(int v=0; v<V; v++){
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX
               && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    cout << "Shortest distances:\n";
    for(int i=0; i<V; i++)
        cout << src << " -> " << i << " = " << dist[i] << endl;
}

int main(){
    int V = 5;
    vector<vector<int>> graph = {
        {0,10,0,30,100},
        {10,0,50,0,0},
        {0,50,0,20,10},
        {30,0,20,0,60},
        {100,0,10,60,0}
    };

    dijkstra(V, graph, 0);
    return 0;
}
