#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 

using namespace std;
vector<int> a, pref, suff;

void solve() {
    int n; cin >> n;
    a.resize(n);
    pref.resize(n);
    suff.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    pref[0] = a[0]/2;
    for(int i = 1; i < n; i++) pref[i] = (pref[i-1] + a[i])/2;
    suff[n-1] = a[n-1]/2;
    for(int i = n-2; i >= 0; i--) suff[i] = (suff[i+1] + a[i])/2;

    int ans = -1;
    for(int i = 0; i < n; i++) {
        int best = a[i];
        if(i-1 >= 0) {
            best += pref[i-1];
        }
        if(i+1 < n) {
            best += suff[i+1];
        }
        ans = max(ans, best);
    }

    cout << ans << "\n";
}

signed main() {
    fast int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}