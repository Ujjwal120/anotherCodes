#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve() {

}

vector<string> logs(vector<string> logs, int maxSpan) {
    map<int, vector<int>> mp;
    int a, b;

    for(auto x : logs) {
        // x is a string
        int ind = 0;
        a = -1, b = -1;
        mp.clear();

        for(int i = 0; i < x.size(); i++) {
            // x[i] character
            if(x[i] == ' ' && a == -1) {
                a = stoi(x.substr(ind, i));
                ind = i+1;
            }
            else if(x[i] == ' ' && b == -1) {
                b = stoi(x.substr(ind, i));
                ind = i+1;
                break;
            }
        }

        // push
        mp[a].push_back(b);
    }

    vector<string> ans;
    for(auto x : mp) {
        if(abs(x.second[0]-x.second[1]) <= maxSpan) {
            ans.push_back(to_string(x.first));
        }
    }

    return ans;
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}