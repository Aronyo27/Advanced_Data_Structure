#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : adj[node]) {
            if (!vis[next]) {
                vis[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);

    return 0;
}