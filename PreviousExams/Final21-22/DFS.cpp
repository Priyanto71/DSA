#include <iostream>
using namespace std;

int graph[10][10];
bool visited[10];
int n;

void dfs(int v) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    cout << "Enter nodes: "; cin >> n;
    int e;
    cout << "Enter edges: "; cin >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < n; i++) visited[i] = false;

    cout << "DFS: ";
    dfs(0);
    cout << endl;
    return 0;
}