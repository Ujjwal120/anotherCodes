#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 1e5 + 10;
int id = 0, n, m, outgoingEdges = 0;
vector<int> adj[maxn], ids(maxn), low(maxn);
vector<bool> vis(maxn), art(maxn);  // graph

void dfs(int root, int node, int par) {
    if(par == root) outgoingEdges++;

    vis[node] = 1;
    low[node] = ids[node] = ++id;

    for(int to : adj[node]) {
        if(to == par) continue;
        if(!vis[to]) {
            dfs(root, to, node);
            low[node] = min(low[node], low[to]);
            // the starting point of bridge is an articulation point
            if(ids[node] < low[to]) {
                art[node] = true;
            }
            // detect cycle 
            if(ids[node] == low[to]) {
                art[node] = true; // gets overidden if only one outgoing edges
            }
        }
        else {
            low[node] = min(low[node], ids[to]); // some parent may have lesser ids
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x); 
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            outgoingEdges = 0;
            dfs(i, i, -1);
            art[i] = (outgoingEdges > 1);
        }
    }

    for(int i = 0; i < n; i++) {
        adj[i].clear();
        art[i] = 0;
    }
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
