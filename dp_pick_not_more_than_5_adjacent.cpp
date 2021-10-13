#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, atmost, totalAdjacent;
vector<int> a;
vector<vector<vector<int>>> dp;

//  dp[index][bitmaskPrevFour][bitmaskFirstFour]

int rec(int ind, int bmask, int bmaskInit) {
    // base condition
    if(ind == n) return 0;

    if(dp[ind][bmask][bmaskInit] != -1) return dp[ind][bmask][bmaskInit];

    // keep count of how restricted is choice of few last index
    int cnt = 0;
    for(int i = 1; i < totalAdjacent; i++) {
        if(ind+i >= n) {
            // depends on init mask
            int circInd = (ind + i) % n;
            if(ind-(totalAdjacent-1) <= circInd) break;   // we have entered the range that we will already traverse in recursion

            int andWith = (1 << (totalAdjacent-2-circInd));

            if(andWith & bmaskInit) {
                // present so increase count
                cnt++;
            }
        }
    }

    int val = 0;

    if(__builtin_popcount(bmask) == atmost || cnt == atmost) {
        // have to skip this one
        int newBmask = (bmask&((1<<(totalAdjacent-2))-1))<<1;
        val += rec(ind + 1, newBmask, bmaskInit);
    }
    else {
        // can skip as well as take
        int newBmask = (bmask&((1<<(totalAdjacent-2))-1))<<1;
        int newBmaskInit = bmaskInit;
        if(ind < totalAdjacent-1) newBmaskInit += (1 << (totalAdjacent-2-ind));

        val += max(rec(ind + 1, newBmask, bmaskInit)
                , a[ind] + rec(ind + 1, newBmask+1, newBmaskInit));

    }

    return dp[ind][bmask][bmaskInit] = val;
}

void solve() {
    cin >> n;
    a.resize(n);

    cin >> atmost >> totalAdjacent;
    
    for(int i = 0; i < n; i++) cin >> a[i];
    dp.resize(n, vector<vector<int>>(1<<(totalAdjacent-1), vector<int>(1<<(totalAdjacent-1), -1)));

    cout << rec(0, 0, 0);
}

signed main() {
    fast int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
