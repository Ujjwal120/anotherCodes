#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int maxn = 1e5+10;
vector<int> adj[maxn], queries[maxn];
int dp[18][maxn], lvl[maxn];

void dfs(int node, int par) {
    for(int i = 1; i < 18; i++) {
        dp[i][node] = dp[i-1][dp[i-1][node]];
    }

    for(int x : adj[node]) {
        if(x != par) {
            dp[0][x] = node;
            lvl[x] = lvl[node]+1;
            dfs(x, node);
        }
    }
}

int lca(int u, int v) {
    if(lvl[u] > lvl[v]) swap(u, v);

    for(int i = 17; i >= 0; i--)
        if(lvl[v]-(1<<i) >= lvl[u]) v = dp[i][v];

    if(u == v) return u;
    
    for(int i = 17; i >= 0; i--) {
        if(dp[i][u] != dp[i][v]) {
            u = dp[i][u];
            v = dp[i][v];
        }
    }
    return dp[0][u];
}

bool yes[maxn];

int dfs1(int node, int par) {
    int ans = 0;
    for(auto x: adj[node]) {
        if(x != par) {
            ans += dfs1(x, node);
        }
    }

    if((yes[node] != 1 && ans != 0) || yes[node] == 1) return ans+1;
    else return ans;
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n-1; i++) {
        int v; cin >> v;
        v--;
        adj[i+1].push_back(v);
        adj[v].push_back(i+1);
    }

    for(int i = 0; i < 18; i++) dp[i][0] = 0;

    dfs(0, -1);
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        queries[x].push_back(y);
    }

    for(int i = 0; i < t; i++) {
        if(queries[i].size() != 0) {
            for(int x : queries[i]) yes[x] = 1;
            int root = queries[i][0];
            for(int j = 1; j < queries[i].size(); j++) {
                root = lca(root, queries[i][j]);
            }

            cout << dfs1(root, -1) << " ";
            for(int x : queries[i]) yes[x] = 0;
        }
        else break;
    }
    cout << "\n";

    for(int i = 0; i < t; i++) {
        if(queries[i].size() != 0) {
            queries[i].clear();
        }
        else break;
    }

    for(int i = 0; i < n; i++) adj[i].clear();
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}