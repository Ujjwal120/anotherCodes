/*
   Travel at most k integer in the array by travelling max distance
   Can't repeat a particular integer twice and can move from i -> i+1 only
*/

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

vector<vector<int>> a;

void solve() {
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < k; i++) a[i].clear();
    vector<vector<int>> dp(n, vector<int>(2, 0));

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        x--;
        a[x].push_back(i);
    }

    int ans = 0;
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int i = 1; i < k; i++) {
        if(a[i].size() == 0) {
            ans = max(dp[i-1][0], dp[i-1][1]);
            break;
        }
        dp[i][0] = max({dp[i-1][0] + abs(a[i][0]-a[i-1][0]),
                       dp[i-1][1] + abs(a[i][0] - a[i-1][a[i-1].size()-1])});
        dp[i][1] = max({dp[i-1][0] + abs(a[i][a[i].size() - 1]-a[i-1][0]),
                       dp[i-1][1] + abs(a[i][a[i].size() - 1] - a[i-1][a[i-1].size()-1])});
    }

    cout << max({ans, dp[k-1][0], dp[k-1][1]}) << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}