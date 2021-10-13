#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

map<int, int> inter, suff;
vector<int> b, e;

void solve() {
    inter.clear();
    suff.clear();

    int n; cin >> n;
    b.resize(n);
    e.resize(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> e[i];
    for(int i = 0; i < n; i++) {
        if(inter.count(b[i]) == 0) {
            inter[b[i]] = e[i];
        }
        else inter[b[i]] = min(inter[b[i]], e[i]);
    }
    
    suff[inter.rbegin()->first] = 1;
    int last = inter.rbegin()->first;
    for(auto i = next(inter.rbegin()); i != inter.rend(); i++) {
        if(i->second <= last) {
            suff[i->first] = suff[last]+1;
            last = i->first;
        }
        else suff[i->first] = suff[last];
    }

    int pref = 0;
    int ans = 0;
    for(auto i = inter.begin(); i != inter.end(); i++) {
        if(i == inter.begin()) {
            auto j = suff.lower_bound(i->second);
            if(j != suff.end()) ans = max(ans, suff[j->first]+1);
            else ans = 1;
        }
        else {
            // prev exist
            if(prev(i) -> second <= i->first) pref++;
            auto j = suff.lower_bound(i->second);
            if(j != suff.end()) ans = max(ans, pref + suff[j->first] + 1);
            else ans = max(ans, pref + 1);
        }
    }

    cout << ans << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}