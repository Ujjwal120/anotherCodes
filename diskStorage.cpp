#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int maxn = 1e5+10;

void solve() {}

int segment(int x, vector<int> space) {
    map<int, int> cnt;
    int n = space.size();

    for(int i = 0; i < x; i++) {
        cnt[space[i]]++;
    }

    int ans = cnt.begin()->first;
    for(int i = x; i < n; i++) {
        cnt[space[i]]++;
        if(cnt[space[i-x]] == 1) {
            cnt.erase(space[i-x]);
        }
        else cnt[space[i-x]]--;
        ans = max(ans, cnt.begin()->first);
    }

    return ans;
}

signed main() {
    fast int t;
    cin >> t;

    cout << segment(2, {8, 2, 4, 6});
    while(t--) solve();
    return 0;
}