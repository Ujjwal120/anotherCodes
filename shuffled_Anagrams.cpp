#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s;
vector<pair<char, int>> ch;
int cs = 0;

void solve() {
    cin >> s;
    ch.clear();
    int n = s.size();
    vector<int> alpha(26, 0);
    bool poss = true;

    for(int i = 0; i < n; i++) {
        alpha[s[i]-'a']++;
        ch.push_back({s[i], i});
        if(alpha[s[i]-'a'] > n/2) {
            poss = false;
            break;
        }
    }

    if(!poss) {
        cout << "Case #" << ++cs << ": IMPOSSIBLE\n";
        return;
    }

    sort(ch.begin(), ch.end());
    for(int i = 0; i < n/2; i++) {
        swap(ch[i].first, ch[i+n/2].first);
    }

    if(n&1) {
        for(int i = n-1; i > n/2; i--) {
            swap(ch[i].first, ch[i-1].first);
        }
    }

    for(int i = 0; i < n; i++) {
        s[ch[i].second] = ch[i].first;
    }

    cout << "Case #" << ++cs << ": " << s << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
