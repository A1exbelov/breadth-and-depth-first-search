#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int N = 6;

vector<int> adjList[N]; // список смежности
bool visited[N]; // массив, содержащий информацию о посещении вершин

void BFS(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " "; // посещаем вершину

        // добавляем в очередь все еще не посещенные соседние вершины
        for (int u : adjList[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

void DFS(int start) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        cout << v << " "; // посещаем вершину

        // добавляем в стек все еще не посещенные соседние вершины в обратном порядке
        for (int i = adjList[v].size() - 1; i >= 0; i--) {
            int u = adjList[v][i];
            if (!visited[u]) {
                visited[u] = true;
                s.push(u);
            }
        }
    }
}

int main() {
    // инициализируем список смежности
    adjList[0] = { 1, 2 };
    adjList[1] = { 0, 3, 4 };
    adjList[2] = { 0, 4 };
    adjList[3] = { 1, 5 };
    adjList[4] = { 1, 2, 5 };
    adjList[5] = { 3, 4 };

    // обход графа в ширину, начиная с вершины 0
    cout << "BFS traversal: ";
    BFS(0);

    // сброс массива visited перед обходом в глубину
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }

    // обход графа в глубину, начиная с вершины 0
    cout << "\nDFS traversal: ";
    DFS(0);

    return 0;
}
