#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 1e5 + 10;
int id = 0, n, m;
vector<int> adj[maxn], ids(maxn), low(maxn);
vector<pair<int, int>> bridges;
vector<bool> vis(maxn);  // graph

void dfs(int node, int par) {
    vis[node] = 1;
    low[node] = ids[node] = ++id;

    for(int to : adj[node]) {
        if(to == par) continue;
        if(!vis[to]) {
            dfs(to, node);
            low[node] = min(low[node], low[to]);
            if(ids[node] < low[to]) {
                bridges.push_back({node, to});
            }
        }
        else {
            low[node] = min(low[node], ids[to]); // some parent may have lesser ids
        }
    }
}

void solve() {
    bridges.clear();
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i, -1);
    }

    for(int i = 0; i < n; i++) {
        cout << ids[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < n; i++) {
        cout << low[i] << " ";
    }
    cout << "\n";

    for(pair<int, int> x : bridges) {
        cout << x.first + 1 << " " << x.second + 1 << "\n";
    }
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
