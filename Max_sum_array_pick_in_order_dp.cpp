#include<bits/stdc++.h>
#define int long long 
using namespace std;

int x, y, n;
int dp[1000][1000];
int A[1010], B[1010];
const int p = 1e18;

int rec(int index, int total_taken) {
    // cannot take add any more
    if(total_taken > x+y || index >= n) return 0;

    if(dp[index][total_taken] != -p) 
        return dp[index][total_taken];

    dp[index][total_taken] = 
        max({ rec(index+1, total_taken), 
              A[index] + rec(index+1, total_taken+1), 
              B[index] + rec(index+1, total_taken+1) });

    return dp[index][total_taken];
}

void solve() {
    long long ans = 0;
    cin >> n >> x >> y; 
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }

    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) dp[i][j] = -p;
    }

    cout << rec(0, 0) << "\n"; 
}

signed main() {
    solve();
    return 0;
}
