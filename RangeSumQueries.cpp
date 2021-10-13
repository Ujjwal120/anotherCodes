#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;
int cs = 0;
const int maxn = 3e5 + 10;
int cnt[maxn];
multiset<int> ms;

void solve() {
    int d, n, k;
    cin >> d >> n >> k;
    ms.clear();

    for(int i = 0; i < d; i++) cnt[i] = 0;

    for(int i = 0; i < n; i++) {
        int x, y, h;
        cin >> h >> x >> y;
        x--; y--;
        cnt[x] += h;
        if(y+1 < d) cnt[y+1] -= h;
    }

    int ans = 0;
    if(cnt[0] != 0) ms.insert(cnt[0]);
    for(int i = 1; i < d; i++) {

        cnt[i] += cnt[i-1];
        ans = max(ans, cnt[i]);
    }

    cout << "Case #" << ++cs << ": " << ans << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
