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

int countOne(int a, int bit) {
    if(power[bit] > a) return 0;
    int d = a-power[bit]+1;
    return power[bit]*(d/power[bit+1]) + min(power[bit], d%power[bit+1]);
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = 0;

    for(int bit = 0; bit <= 30; bit++) {
        int one_a = countOne(a-1, bit);
        int one_b = countOne(b, bit);
        int a_b_one = one_b - one_a;
        int a_b_zero = b - a + 1 - a_b_one;
        int one_c = countOne(c-1, bit);
        int one_d = countOne(d, bit);
        int c_d_one = one_d - one_c;
        int c_d_zero = d - c + 1 - c_d_one;
        ans = add(ans, mul(add(mul(a_b_one, c_d_zero), mul(a_b_zero, c_d_one)), power[bit]));
    }

    cout << ans << "\n";

}

signed main () {
    fast int t;
    power[0] = 1;
    for(int i = 1; i < 31; i++) {
        power[i] = power[i-1]*2;
    }
    cin >> t;
    while(t--) solve();
    return 0;
}