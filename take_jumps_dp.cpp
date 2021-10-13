#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 
using namespace std;

int n, r1, r2;
string s;
const int maxn = 1e5+10;
const int p = 1e9+7;

bitset<maxn> bs;
vector<int> dp;
int primes[maxn], allowed[maxn], suffix[maxn];

void sieve() {
    bs.set();
    primes[2] = 1;

    for(int i = 3; i < maxn; i += 2) {
        if(bs[i]) {
            bs[i] = 0;
            primes[i] = 1;
            for(long long j = i*1ll*i; j < maxn; j += i) {
                bs[j] = 0;
            }
        }
    }

    for(int i = 1; i < maxn; i++) primes[i] += primes[i-1];
}

void solve() {
    cin >> r1 >> r2;
    cin >> n;
    cin >> s;

    for(int i = 0; i < n; i++) {
        allowed[i] = 0;
        suffix[i] = p;
        if(s[i] == '#') allowed[i] = 1;
    }

    suffix[n-1] = 0;
    for(int i = n-2; i >= 0; i--) {
        if(allowed[i]) {
            if((i+1) * r1 <= primes[i+1] * r2) {
                if(i + primes[i+1] < n && allowed[primes[i+1] + i]) {

                    suffix[i] = min(suffix[i], 1 + suffix[i+primes[i+1]]);
                }
            }

            if(i + 2 < n && allowed[i+2]) {
                suffix[i] = min(suffix[i], 1 + suffix[i+2]);
            }

            if(i + 1 < n && allowed[i+1]) {
                suffix[i] = min(suffix[i], 1 + suffix[i+1]);
            }
        }
    }

    if(suffix[0] == p) cout << "No way!\n";
    else cout << suffix[0] << "\n";
}

signed main() {
    fast int t = 1;
    sieve();
    cin >> t;
    while(t--) solve();
    return 0;
}