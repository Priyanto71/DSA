#include <iostream>
using namespace std;

#define MAX 10
#define INF 99999

int dist[MAX][MAX];
int n;

void warshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    cout << "Enter nodes: "; cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }

    int e;
    cout << "Enter edges: "; cin >> e;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    warshall();

    cout << "Shortest distance matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}