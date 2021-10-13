#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

map<int, int> ind, cnt;

int solve(int numComputer, vector<int> hardDiskSpace, int segmentLength) {  
    cnt.clear();
    ind.clear();

    int ans = -1;
    for(int i = 0; i < segmentLength; i++) {
        ind[i] = hardDiskSpace[i];
        cnt[hardDiskSpace[i]]++;
    }

    ans = cnt.begin()->first;

    for(int i = segmentLength; i < numComputer; i++) {
        int rem = ind.begin()->second;
        ind.erase(ind.begin());
        auto it = cnt.lower_bound(rem);
        if(it->second == 1) {
            // remove
            cnt.erase(it);
        }
        else {
            it->second--;
        }

        ind[i] = hardDiskSpace[i];
        cnt[hardDiskSpace[i]]++;

        ans = max(ans, cnt.begin()->first);
    }

    return ans;
}

signed main () {
    fast int t = 1;
    // cin >> t;
    int n;
     cin >> n;

    vector<int> a(n);
     for(int i = 0; i < n; i++) cin >> a[i];

    int len;
    cin >> len; 
    while(t--) solve(n, a, len);
    return 0;
}