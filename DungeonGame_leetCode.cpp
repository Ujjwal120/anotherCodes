#include<bits/stdc++.h>
using namespace std;

int INF = 1e9;
int n, m;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    n = dungeon.size();
    m = dungeon[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -INF));

    dp[n-1][m-1] = dungeon[n-1][m-1];
    if(dp[n-1][m-1] > 0) dp[n-1][m-1] = 0;

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(i == n-1 && j == m-1) continue;
            if(i < n-1) dp[i][j] = max(dp[i][j], dp[i+1][j] + dungeon[i][j]);
            if(j < m-1) dp[i][j] = max(dp[i][j], dp[i][j+1] + dungeon[i][j]);
            if(dp[i][j] > 0) dp[i][j] = 0;
        }
    }

    return abs(dp[0][0]) + 1;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dj(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> dj[i][j];
    } 
    cout << calculateMinimumHP(dj);

    return 0;
}