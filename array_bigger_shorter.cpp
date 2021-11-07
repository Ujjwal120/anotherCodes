#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        a[i] = {tmp, i};
    }

    sort(a.begin(), a.end());
    ordered_set<int> ind;
    
    vector<int> front(n), back(n);
    
    front[a[n-1].second] = 0;
    ind.insert(a[n-1].second);
    
    for(int i = n-2; i >= 0; i--) {
        int it = ind.order_of_key(a[i].second);
        front[a[i].second] = it;
        ind.insert(a[i].second);
    }

    ind.clear();
    back[a[0].second] = 0;
    ind.insert(a[0].second);

    for(int i = 1; i < n; i++) {
        int it = ind.order_of_key(a[i].second);
        back[a[i].second] = ind.size() - it;
        ind.insert(a[i].second);
    }

    for(int i : front) cout << i << " ";
    cout << "\n";

    for(int i : back) cout << i << " ";
    cout << "\n";
}

signed main() {
    fast int t = 1;
    while(t--) solve();
    return 0;
}