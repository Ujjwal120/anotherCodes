#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int p= 1e9+7;

int power[31];

int mul(int a, int b) {
    long long x = a*1ll*b;
    return (x >= p) ? x%p : x;
}

int add(int a, int b) {
    return (a+b >= p) ? a+b-p : a+b;
}

int sub(int a, int b) {
    return (a-b < 0) ? a-b+p : a-b; 
}

int countOne(int a, int bit) {
    if(power[bit] > a) return 0;
    int d = a-power[bit]+1;
    return power[bit]*(d/power[bit+1]) + min(power[bit], d%power[bit+1]);
}

vector<pair<int, int>> range;
vector<int> ones;

void solve() {
    int n, k;
    cin >> n >> k;
    range.resize(n);
    for(int i = 0; i < n; i++) cin >> range[i].first >> range[i].second;

    int ans = 0;
    for(int bit = 0; bit < 31; bit++) {
        ones.clear();
        for(int i = 0; i < n ; i++) {
            int a = countOne(range[i].first-1, bit);
            int b = countOne(range[i].second, bit);
            ones.push_back(b-a);
        }

        // cout << bit << " : ";
        // for(int i = 0; i < n; i++) cout << ones[i] << " ";
        // cout << "\n"; 
        // zero from left till k-1 first
        int l1 = 1;
        for(int i = 0; i < k; i++) {
            l1 = mul(l1, range[i].second - range[i].first + 1 - ones[i]);
        }
        // one from k to n-1
        int temp1 = 1;
        int r1 = 1;
        for(int i = k; i < n; i++) {
            temp1 = mul(temp1, range[i].second - range[i].first + 1);
            r1 = mul(r1, range[i].second - range[i].first + 1 - ones[i]);
        }

        r1 = sub(temp1, r1);

        int l2 = 1; 
        for(int i = 0; i < k; i++) {
            l2 = mul(l2, ones[i]);
        }

        int r2 = 1;
        for(int i = k; i < n; i++) {
            r2 = mul(r2, ones[i]);
        }

        r2 = sub(temp1, r2);

        ans = add(ans, mul(power[bit], add(mul(l1, r1), mul(l2, r2))));
        cout << bit << " : " << ans << "\n";
    }

    cout << ans << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    power[0] = 1;
    for(int i = 1; i < 31; i++) power[i] = 2*power[i-1];
    while(t--) solve();
    return 0;
}

