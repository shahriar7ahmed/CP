//bfs code
#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
int visited[100];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Visiting: " << node << endl;

        for (auto neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}
int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
       // graph[v].push_back(u); // For undirected graph
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    bfs(start);

    return 0;
}