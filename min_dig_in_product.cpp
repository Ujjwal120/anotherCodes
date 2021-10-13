#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

const int maxn = 1e5+10;
bitset<maxn> bs;
vector<int> pr;
vector<pair<int, int>> prime;

void sieve() {
    bs.set();
    pr.push_back(2);
    for(int i = 3; i <= maxn; i += 2) {
        if(bs[i]) {
            bs[i] = 0;
            pr.push_back(i);
            for(int j = i*i; j <= maxn; j += i) {
                bs[j] = 0;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i < pr.size(); i++) {
        int cnt = 0;
        while(n > 1 && n % pr[i] == 0) {
            cnt++;
            n /= pr[i];
        }
        if(cnt != 0) prime.push_back({pr[i], cnt});
        if(n == 1) break;
    }

    if(n != 1) prime.push_back({n, 1});

    int pro = 1;
    vector<int> extra;
    for(int i = 0; i < prime.size(); i++) {
        if(prime[i].second&1) {
            extra.push_back(prime[i].first);
        }
        for(int j = 0; j < prime[i].second/2; j++) {
            pro *= prime[i].first;
        }
    }

    if(extra.size() == 0) {
        int ans = 0;
        while(pro) {
            pro /= 10;
            ans++;
        }
        cout << ans << "\n";
    }
    else {
        int ans = 1e18;
        int bitMask = 1<<(extra.size()-1);
        for(int i = 0; i <= bitMask; i++) {
            int a = 1, b = 1;
            for(int j = 0; j < extra.size(); j++)  {
                if(i&(1<<j)) b *= extra[j];
                else a *= extra[j];
            }

            int tempCount = 0;
            int temp = pro * max(a, b);
            while(temp) {
                temp /= 10;
                tempCount++; 
            }

            ans = min(ans, tempCount);
        }

        cout << ans << "\n";
    }
}

signed main() {
    fast int t = 1;
    // cin >> t;
    sieve();
    while(t--) solve();
    return 0;
}
