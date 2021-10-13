#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;
vector<int> a, suffix;

void solve() {
    int n; cin >> n;
    a.resize(n);
    suffix.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    suffix[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--) {
        suffix[i] = a[i] + suffix[i+1];
    }
    for(int i = n-2; i >= 0; i--) suffix[i] = max(suffix[i], suffix[i+1]);
    int ans = suffix[0];

    int temp = 0;
    for(int i = 0; i < n; i++) {
        temp += a[i];
        if(i != n-1) {
            ans = max(temp + suffix[i+1], ans); 
        }
        else ans = max(ans, temp);
    }

    cout << ans << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}