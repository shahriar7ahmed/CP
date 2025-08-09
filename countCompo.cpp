#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>v[], vector<bool>&visited)
{
    visited[node] = true;
    for(int i = 0; i < v[node].size(); i++)
    {
        int child = v[node][i];
        if(!visited[child])
        {
            dfs(child, v, visited);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int>v[n+1];

    while(e--)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x); // Undirected
    }

    vector<bool>visited(n+1, false);
    int components = 0;

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i, v, visited);
            components++;
        }
    }

    cout << "Number of connected components: " << components << endl;

    return 0;
}
