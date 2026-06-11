#include<iostream>
using namespace std;

int parent[100], rankArr[100];

int find(int i) {
    if (parent[i] != i) parent[i] = find(parent[i]);
    return parent[i];
}

void unionSets(int x, int y) {
    int px = find(x), py = find(y);
    if (rankArr[px] < rankArr[py]) parent[px] = py;
    else if (rankArr[px] > rankArr[py]) parent[py] = px;
    else { parent[py] = px; rankArr[px]++; }
}

struct Edge { int src, dest, weight; };

void kruskal(Edge edges[], int E, int V) {
    // Sort edges by weight (bubble sort)
    for (int i = 0; i < E - 1; i++)
        for (int j = 0; j < E - i - 1; j++)
            if (edges[j].weight > edges[j+1].weight) {
                Edge t = edges[j]; edges[j] = edges[j+1]; edges[j+1] = t;
            }

    for (int i = 0; i < V; i++) { parent[i] = i; rankArr[i] = 0; }

    cout << "Edges in MST:\n";
    int totalCost = 0;
    for (int i = 0; i < E; i++) {
        int u = find(edges[i].src), v = find(edges[i].dest);
        if (u != v) {
            cout << edges[i].src << " - " << edges[i].dest
                 << " : " << edges[i].weight << "\n";
            totalCost += edges[i].weight;
            unionSets(u, v);
        }
    }
    cout << "Total MST cost: " << totalCost << endl;
}

int main() {
    Edge edges[] = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    int V = 4, E = 5;
    kruskal(edges, E, V);
    return 0;
}