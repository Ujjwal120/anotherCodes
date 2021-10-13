#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, b, c;
    cin >> n >> b >> c;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++) a[i] += a[i-1];

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            int x = lower_bound(a.begin() + i, a.end(), b) - a.begin();
            int y = upper_bound(a.begin() + i, a.end(), c) - a.begin();
            ans += y-x;
        }
        else {
            int x = lower_bound(a.begin() + i, a.end(), b + a[i-1]) - a.begin();
            int y = upper_bound(a.begin() + i, a.end(), c + a[i-1]) - a.begin();
            ans += y-x;
        }
    }

    cout << ans << "\n";
}

signed main() {
    int t = 1;
    while(t--) solve();
    return 0;
}