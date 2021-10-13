#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
vector<string> text;

void solve() {
    int lines;
    cin >> lines;
    cin.ignore();
    text.clear();
    string s;
    for(int i = 0; i < lines; i++) {
        getline(cin, s);
        text.push_back(s);
    }

    int tno = 0;
    int sno = 0;
    vector<string> ans;

    for(auto x : text) {
        if(x[0] == '#') {
            if(x[1] == '#') {
                string t = to_string(tno) + "." + to_string(++sno) + ".";
                ans.push_back(t + x.substr(2));
            }
            else {
                ++tno;
                sno = 0;
                string t = to_string(tno) + ".";
                ans.push_back(t + x.substr(1));
            }
        }
        else continue;
    }

    for(auto x : ans) {
        for(auto i : x) cout << i;
        cout << "\n";
    }
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}