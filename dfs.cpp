// // #include <bits/stdc++.h>
// // using namespace std;

// // vector<int> graph[100];
// // int visited[100];

// // void dfs(int source) {
// //     visited[source] = 1;
// //    // cout << source << " ";  // Print current node
// //     for (auto next : graph[source]) {
// //         if (!visited[next]) {
// //             dfs(next);
// //         }
// //     }
// // }

// // int main() {
// //     int n, e;
// //     cin >> n >> e;

// //     for (int i = 0; i < e; i++) {
// //         int u, v;
// //         cin >> u >> v;
// //         graph[u].push_back(v);
// //         // graph[v].push_back(u); Add this line for undirected graph
// //     }

// //     int start;
// //     cin >> start; // Take starting node input
// //     dfs(start);

// //     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> graph[100];
// int visited[100];

// void dfs(int source) {
//     visited[source] = 1;
//     for (auto next : graph[source]) {
//         if (!visited[next]) {
//             dfs(next);
//         }
//     }
// }

// int main() {
//     int n, e;
//     cin >> n >> e;

//     for (int i = 0; i < e; i++) {
//         int u, v;
//         cin >> u >> v;
//         graph[u].push_back(v);
//         //graph[v].push_back(u); // for undirected graph
//     }

//     int componentCount = 0;

//     for (int i = 1; i <= n; i++) {
//         if (!visited[i]) {
//             componentCount++;
//             dfs(i);
//         }
//     }

//     cout << "Number of connected components: " << componentCount << endl;

//     return 0;
// }
//topological sort using DFS
#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100];
int visited[100];
void dfs(int source) {
    visited[source] = 1;
    for (auto next : graph[source]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}
int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        // graph[v].push_back(u); // for undirected graph
    }

    stack<int> s;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            s.push(i);
        }
    }

    cout << "Topological Sort Order: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}   
