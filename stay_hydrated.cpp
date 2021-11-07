#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int cs = 0;

void solve() {
    int k; cin >> k;
    vector<int> x, y;
    for(int i = 0; i < k; i++) {
        int X; cin >> X;
        int Y; cin >> Y;
        x.push_back(X);
        y.push_back(Y);
        cin >> X;
        cin >> Y;
        x.push_back(X);
        y.push_back(Y);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout << "Case #" << ++cs << ": " << x[k-1] << " " << y[k-1] << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}