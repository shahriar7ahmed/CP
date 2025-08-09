#include<bits/stdc++.h>
using namespace std;

//-----------------------------------------
// 1. Greedy Algorithm - Activity Selection
//-----------------------------------------
struct Activity {
    int st, ed;
};

bool cmp(Activity &x, Activity &y) {
    return x.ed < y.ed;
}

void activity_selection() {
    int n;
    cin >> n;
    vector<Activity> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].st;
    for(int i = 0; i < n; i++) cin >> v[i].ed;
    sort(v.begin(), v.end(), cmp);
    int last = v[0].ed, cnt = 1;
    for(int i = 1; i < n; i++) {
        if(v[i].st >= last) {
            cnt++;
            last = v[i].ed;
        }
    }
    cout << cnt << endl;
}

//-----------------------------------------
// 2. Greedy - Fractional Knapsack
//-----------------------------------------
struct Item {
    int val, wt;
};

bool cmpK(Item a, Item b) {
    return (double)a.val/a.wt > (double)b.val/b.wt;
}

double fractional_knapsack(int W, vector<Item> &arr) {
    sort(arr.begin(), arr.end(), cmpK);
    double total = 0.0;
    for(auto &i : arr) {
        if(W >= i.wt) {
            W -= i.wt;
            total += i.val;
        } else {
            total += (double)i.val * W / i.wt;
            break;
        }
    }
    return total;
}

//-----------------------------------------
// 3. Graph Traversal - BFS & DFS
//-----------------------------------------
const int N = 1e5;
vector<int> adj[N];
bool vis[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for(int v : adj[u]) {
            if(!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void dfs(int u) {
    vis[u] = true;
    cout << u << " ";
    for(int v : adj[u]) {
        if(!vis[v]) dfs(v);
    }
}

//-----------------------------------------
// 4. MST - Prim's Algorithm (using Min-Heap)
//-----------------------------------------
typedef pair<int, int> pii;
vector<pii> prim[N];
bool taken[N];

int prims(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    int cost = 0;
    while(!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if(taken[u]) continue;
        cost += w;
        taken[u] = true;
        for(auto [v, wt] : prim[u]) {
            if(!taken[v]) pq.push({wt, v});
        }
    }
    return cost;
}

//-----------------------------------------
// 5. Dijkstra's Algorithm
//-----------------------------------------
vector<pii> graph[N];
int dist[N];

void dijkstra(int src, int n) {
    for(int i = 0; i <= n; i++) dist[i] = INT_MAX;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w] : graph[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

//-----------------------------------------
// 6. Floyd-Warshall Algorithm
//-----------------------------------------
const int INF = 1e9;
int fw[105][105];

void floyd_warshall(int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(fw[i][k] < INF && fw[k][j] < INF)
                    fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
            }
        }
    }
}

//-----------------------------------------
// 7. N-Queen Problem (Backtracking)
//-----------------------------------------
const int MAXN = 10;
int board[MAXN];

bool isSafe(int row, int col, int n) {
    for(int i = 0; i < row; i++) {
        if(board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void nqueen(int row, int n) {
    if(row == n) {
        for(int i = 0; i < n; i++) cout << board[i] << " ";
        cout << endl;
        return;
    }
    for(int col = 0; col < n; col++) {
        if(isSafe(row, col, n)) {
            board[row] = col;
            nqueen(row + 1, n);
        }
    }
}

//-----------------------------------------
// 8. Convex Hull - Graham Scan
//-----------------------------------------
struct Point {
    int x, y;
};

int orientation(Point a, Point b, Point c) {
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return val == 0 ? 0 : (val > 0 ? 1 : 2);
}

vector<Point> convex_hull(vector<Point>& pts) {
    int n = pts.size();
    if(n < 3) return {};
    sort(pts.begin(), pts.end(), [](Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    vector<Point> hull;
    for(int i = 0; i < 2; i++) {
        vector<Point> temp;
        for(auto &p : pts) {
            while(temp.size() >= 2 && orientation(temp[temp.size()-2], temp.back(), p) != 2)
                temp.pop_back();
            temp.push_back(p);
        }
        temp.pop_back();
        for(auto &p : temp) hull.push_back(p);
        reverse(pts.begin(), pts.end());
    }
    return hull;
}

//-----------------------------------------
// 9. Euclid's Algorithm & Modular Exponentiation
//-----------------------------------------
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int mod_exp(int a, int b, int m) {
    int res = 1;
    a %= m;
    while(b > 0) {
        if(b & 1) res = (1LL * res * a) % m;
        a = (1LL * a * a) % m;
        b >>= 1;
    }
    return res;
}

//-----------------------------------------
// Main function for testing (optional)
//-----------------------------------------
int main() {
    // Call individual functions for testing here if needed
    return 0;
}
 