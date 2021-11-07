#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 1e5 + 10;
vector<int> adj[maxn];
vector<int> topsort;
vector<int> vis(maxn);

void dfs(int node) {
    vis[node] = 1;
    for(int x : adj[node]) {
        if(!vis[x]) {
            dfs(x);
        }
    }
    topsort.push_back(node);
}

void solve() {
    int n, m;
    cin >> n >> m;
    topsort.clear();

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }
    
    for(int i = n-1; i >= 0; i--) cout << topsort[i] << " ";
    cout << "\n";

    for(int i = 1; i <= n; i++) adj[i].clear();
    for(int i = 1; i <= n; i++) vis[i] = 0;
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}