#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

const int maxn = 1e5+10;

int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b%a, a);
}

void solve() {
    // int l, r, x, y;
    // cin >> l >> r >> x >> y;
    // int blx = (l-1) / x;
    // int trx = r / x;
    // int byx = trx - blx;
    // int bly = (l-1) / y;
    // int ty = r / y;
    // int byy = ty - bly;
    // int LCM = x*y/gcd(x, y);
    // int blcm = (l-1) / LCM;
    // int tlcm = r / LCM;
    // int bylcm = tlcm - blcm;
    // int tot = byx + byy - bylcm;
    // cout << r-l+1-tot << "\n";
    map<char, int> mp;
    mp['a']++;
    mp['a']++;
    mp['a']++;
    cout << mp.count('a') << "\n";
}

signed main() {
    fast int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
