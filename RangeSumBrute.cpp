#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;
int cs = 0;
vector<int> adj[1010];

void solve() {
    int d, n, k;
    cin >> d >> n >> k;

    for(int i = 0; i < d; i++) {
        adj[i].clear();
    }

    for(int i = 0; i < n; i++) {
        int x, y, h;
        cin >> h >> x >> y;
        x--; y--;
        for(int j = x; j <= y; j++) adj[j].push_back(h);
    }

    for(int i = 0; i < d; i++) {
        if(adj[i].size() > 1) sort(adj[i].begin(), adj[i].end(), greater<int>()); 
    }

    int ans = 0;
    for(int i = 0; i < d; i++) {
        int temp = 0;
        for(int j = 0; j < min(k, (int)adj[i].size()); j++) {
            temp += adj[i][j];
        }
        ans = max(ans, temp);
    }

    cout << "Case #" << ++cs << ": " << ans << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
