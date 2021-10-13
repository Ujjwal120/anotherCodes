#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    bool poss = false;
    for(int i = 0; i <= n; i++) {
        int num = k - i*m;
        int den = n - 2*i;
        if(num < 0 || den < 0 || den == 0) break;
        if((num % den) == 0 && (num/den) <= m) {
            poss = true;
            break;
        }
    }

    if(poss) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    fast int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}