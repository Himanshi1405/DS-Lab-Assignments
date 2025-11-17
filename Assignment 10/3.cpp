#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for(int x : adj[node]) {
        if(!visited[x])
            dfsUtil(x, adj, visited);
    }
}

void dfs(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V,false);
    cout << "DFS Traversal: ";
    dfsUtil(start, adj, visited);
    cout << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0]={1,4};
    adj[1]={0,2};
    adj[2]={1,3};
    adj[3]={2,4};
    adj[4]={3,0};

    dfs(0, adj, V);
    return 0;
}
