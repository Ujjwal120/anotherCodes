#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;
int cs = 0;
const int maxn = 5e5 + 10;
int pref[maxn], suff[maxn];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    pref[0] = -1;
    for(int i = 1; i < n; i++) {
        if(s[i-1] == '1') pref[i] = i-1;
        else pref[i] = pref[i-1];
    }


    suff[n-1] = -1;
    for(int i = n-2; i >= 0; i--) {
        if(s[i+1] == '1') suff[i] = i+1;
        else suff[i] = suff[i+1];
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        //all bins
        if(i == 0) {
            if(s[i] == '0') {
                ans += suff[i];
            }
        }
        else if(i == n-1) {
            if(s[i] == '0') {
                ans += n-1-pref[i];
            }
        }
        else {
            if(s[i] == '0') {
                if(pref[i] != -1 && suff[i] != -1) {
                    ans += min(i - pref[i], suff[i] - i);
                }
                else if(pref[i] != -1) {
                    ans += i - pref[i];
                }
                else if(suff[i] != -1) {
                    ans += suff[i] - i;
                }
            }
        }
    }

    cout << "Case #" << ++cs << ": " << ans << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
