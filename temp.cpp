#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

const int maxn = 1e5+10;
vector<int> a;

void solve() {
    int n; cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = -1e18;
    int ind = -1;
    for(int gap = 1; gap <= n; gap++) {
        int temp = 0;
        for(int i = gap-1; i < n; i += gap) {
            temp += a[i];
        }
        if(ans < temp) {
            ind = gap;
            ans = temp;
        }
    }

    cout << ind << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
