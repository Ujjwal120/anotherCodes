#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

// no need of backtracing
vector<int> magic;
vector<int> a;

void solve() {
    magic.clear();
    int n; cin >> n;

    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    reverse(a.begin(), a.end());
    
    // now appy the logic of LSIS;
    for(int x : a) {
        auto it = lower_bound(magic.begin(), magic.end(), x);
        if(it == magic.end()) {
            magic.push_back(x);
        }
        else {
            *it = x;
        }
    }

    cout << magic.size() << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}