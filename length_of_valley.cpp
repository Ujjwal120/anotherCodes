#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> a, l, r;
void solve() {
    int n;
    cin >> n;
    a.resize(n);
    l.resize(n);
    r.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    l[0] = 1;
    r[n-1] = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1]) l[i] = l[i-1] + 1;
        else l[i] = 1;
    }
    for(int i = n-2; i >= 0; i--) { 
        if(a[i] < a[i+1]) r[i] = r[i+1] + 1;
        else r[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        if(i == 0) cout << r[i] << " ";
        else {
            if(a[i-1] > a[i]) cout << l[i-1]+r[i] << " ";
            else cout << r[i] << " ";
        }
    }
    cout << "\n";
    
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}