#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V,false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int x : adj[node]) {
            if(!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
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

    bfs(0, adj, V);
    return 0;
}
