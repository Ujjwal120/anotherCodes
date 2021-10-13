#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;

vector<int> a, pref, suff;

// void kadaneAlgo() {
//     int n; cin >> n;
//     a.resize(n);
//     pref.resize(n);
//     for(int i = 0; i < n; i++) cin >> a[i];

//     int sum = 0;
//     int ans = 0;

//     for(int i = 0; i < n; i++) {
//         pref[i] = 0; // initialize
//         sum += a[i];
//         pref[i] = max(pref[i], sum);
//         ans = max(pref[i], ans);
//         sum = max(sum, 0ll);
//     }

//     cout << ans << "\n";
// }

void solve() {
    int n; cin >> n;
    a.resize(n);
    pref.resize(n);
    suff.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int sum = 0;

    // Kadane on prefix array
    for(int i = 0; i < n; i++) {
        pref[i] = 0; // initialize
        sum += a[i];
        pref[i] = max(pref[i], sum);
        sum = max(sum, 0ll);
    }

    sum = 0;
    // Kadane on suffix array
    for(int i = n-1; i >= 0; i--) {
        suff[i] = 0; // initialize
        sum += a[i];
        suff[i] = max(suff[i], sum);
        sum = max(sum, 0ll);
    }

    int prefBest = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, prefBest + suff[i]);
        prefBest = max(prefBest, pref[i]);
    }

    // edge case when no suff left to be chosen
    ans = max(ans, prefBest);

    cout << ans << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}