#include<iostream>
using namespace std;
#define INF 99999

struct Edge { int src, dest, weight; };

void bellmanFord(Edge edges[], int V, int E, int src) {
    int dist[100];
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
        for (int j = 0; j < E; j++)
            if (dist[edges[j].src] != INF &&
                dist[edges[j].src] + edges[j].weight < dist[edges[j].dest])
                dist[edges[j].dest] = dist[edges[j].src] + edges[j].weight;

    for (int j = 0; j < E; j++)
        if (dist[edges[j].src] != INF &&
            dist[edges[j].src] + edges[j].weight < dist[edges[j].dest]) {
            cout << "Negative weight cycle detected!\n";
            return;
        }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) cout << i << "\t" << dist[i] << "\n";
}

int main() {
    int V = 5, E = 8;
    Edge edges[] = {{0,1,-1},{0,2,4},{1,2,3},{1,3,2},{1,4,2},
                    {3,2,5},{3,1,1},{4,3,-3}};
    bellmanFord(edges, V, E, 0);
    return 0;
}