#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    void displayAdjList() {
        cout << "\nAdjacency List:\n";
        for(int i=0; i<V; i++) {
            cout << i << ": ";
            for(int j : adjList[i])
                cout << j << " ";
            cout << endl;
        }
    }

    int inDegree(int v) {
        int count = 0;
        for(int i=0; i<V; i++)
            if(adjMatrix[i][v] == 1) count++;
        return count;
    }

    int outDegree(int v) {
        return adjList[v].size();
    }

    void adjacentVertices(int v) {
        cout << "Adjacent vertices of " << v << ": ";
        for(int x : adjList[v]) cout << x << " ";
        cout << endl;
    }

    int totalEdges() {
        int count = 0;
        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
                if(adjMatrix[i][j] == 1) count++;
        return count / 2;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);

    g.displayAdjMatrix();
    g.displayAdjList();

    cout << "\nIn-degree of 2: " << g.inDegree(2);
    cout << "\nOut-degree of 2: " << g.outDegree(2) << endl;

    g.adjacentVertices(3);

    cout << "\nTotal Edges: " << g.totalEdges() << endl;
    return 0;
}
