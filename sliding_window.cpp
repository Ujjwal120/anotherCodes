#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    int a[26] = {0};
    vector<pair<int, int>> p(n, {-1, -1});
    for(int i = 0; i < n; i++) a[s[i] - 'A']++;
    for(int i = 0; i < n; i++) {
        if(p[s[i] - 'A'].first == -1) {
            p[s[i] - 'A'] = {i, i};
        }
        else {
            p[s[i] - 'A'].second = i; 
        }
    }

    bool poss = false;
    int ind = -1, range = INT_MAX;
    for(int i = 0; i < 26; i++) {
        if(a[i] > n/2 && a[i] > 1) {
            // pass
            poss = true;
            if(p[i].second - p[i].first < range) {
                range = p[i].second - p[i].first;
                ind = i;
            }
        }
    }

    if(poss) {
        for(int i = p[ind].first; i <= p[ind].second; i++) {
            cout << s[i];
        }
        cout << "\n";
    }
    else cout << "-1\n";
}

signed main() {
    fast int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}