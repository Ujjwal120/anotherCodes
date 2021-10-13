#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m;
const int maxn = 2e5+10;
int waqt = 0;
vector<int> adj[maxn];
int low[maxn], disc[maxn], parent[maxn];
bool visited[maxn];
vector<pair<int, int>> bridges;
bool cycle = false;
int cycleCount = 0;
int leftTree = 0;
int from, to;

void dfs1(int u) {
    visited[u] = 1;
    for(auto v : adj[u]) {
        if(u != from && v == to) {
            cycle = true;
            cycleCount++;
        } 
        if(!visited[v]) {
            dfs1(v);
        }
    }
}

void dfs(int u) {
    visited[u] = true;
    disc[u] = low[u] = ++waqt;

    for(auto v : adj[u]) {
        if(!visited[v]) {
            parent[v] = u;
            dfs(v);
            low[u]  = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                // bridge
                bridges.push_back()
            }
        }
        else if(v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void solve() {
    cin >> n >> m;
    waqt = 0;
    bridges.clear();

    for(int i = 0; i < m; i++) {
        int x, y; 
        cin >> x >> y;
        x--;  y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);
    for(int i = 0; i < n; i++) {
        low[i] = 0;
        disc[i] = 0;
        visited[i] = 0;
        parent[i] = 0;
        adj[i].clear();
    }
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
