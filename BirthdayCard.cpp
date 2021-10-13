#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> ans;
vector<int> coll;

void solve() {
    ans.clear();

    int n, d; cin >> n;
    coll.resize(n);

    for(int i = 0; i < n; i++) cin >> coll[i];
    sort(coll.begin(), coll.end());
    cin >> d;

    int cnt = 1;
    int ind = 0;
    while(ind < n && d >= cnt) {
        if(d == 0 || d < cnt) break;
        if(cnt != coll[ind]) {
            d -= cnt;
            ans.push_back(cnt);
        }
        else ind++;
        cnt++;
    }

    while(d >= cnt) {
        d -= cnt;
        ans.push_back(cnt);
        cnt++;
    }

    for(int x : ans) cout << x << " ";
    cout << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}