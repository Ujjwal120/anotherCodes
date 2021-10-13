#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define int long long 
using namespace std;

const int maxn = 2e5+10;
int a[maxn], pref[maxn], suff[maxn];

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    suff[n-1] = 1;
    for(int i = n-2; i >= 0; i--) {
        suff[i] = (a[i+1] > a[i]) ? suff[i+1]+1 : 1;
    }

    pref[0] = 1;
    for(int i = 1; i < n; i++) {
        pref[i] = (a[i] > a[i-1]) ? pref[i-1]+1 : 1;
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            if(n == 1) {
                ans = 1;
            }
            else {
                ans = suff[i+1] + (a[0] < a[1]);
            }
        }
        else if(i == n-1) {
            ans = max(ans, pref[n-2] + (a[n-2] < a[n-1]));
        }
        else {
            if(a[i] > a[i-1] && a[i] < a[i+1]) {
                ans = max(ans, pref[i] + suff[i+1]);
            }
            else {
                ans = max(ans, pref[i-1] + (a[i] > a[i-1]));
                ans = max(ans, suff[i+1] + (a[i] < a[i+1])); 
                if(a[i-1] < a[i+1]) {
                    ans = max(ans, pref[i-1] + suff[i+1]);
                }
            }
        }
    }

    cout << ans << "\n";
}

signed main() {
    fast int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}