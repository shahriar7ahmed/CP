#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, wt;
};

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edges(e);

    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    int src = 1; // Assuming source is vertex 1
    vector<int> dis(n + 1, INT_MAX);
    dis[src] = 0;

    // Relax all edges (n - 1) times
    for (int i = 1; i <= n - 1; i++) {
        for (auto &edge : edges) {
            if (dis[edge.u] != INT_MAX && dis[edge.u] + edge.wt < dis[edge.v]) {
                dis[edge.v] = dis[edge.u] + edge.wt;
            }
        }
    }

    // Optional: Negative weight cycle detection
    bool hasNegativeCycle = false;
    for (auto &edge : edges) {
        if (dis[edge.u] != INT_MAX && dis[edge.u] + edge.wt < dis[edge.v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Graph contains a negative weight cycle\n";
    } else {
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX)
                cout << "INF ";
            else
                cout << dis[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
