#include <iostream>
using namespace std;

int graph[10][10];
bool visited[10];
int queue[100];
int front = 0, rear = 0;
int n;

void enqueue(int v) { queue[rear++] = v; }
int dequeue() { return queue[front++]; }
bool isEmpty() { return front == rear; }

void bfs(int start) {
    visited[start] = true;
    enqueue(start);

    while (!isEmpty()) {
        int v = dequeue();
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(i);
            }
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

    cout << "BFS: ";
    bfs(0);
    cout << endl;
    return 0;
}