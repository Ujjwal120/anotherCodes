#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string convert(string &s, int numRows) {
    // base case no zig-zag pattern allowed
    if (numRows == 1) return s;

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    string ret;
    for (string row : rows) ret += row;
    return ret;
}
signed main() {
    fast int t;
    // cin >> t;
    t = 1;
    string s; 
    cin >> s;
    while(t--) cout << convert(s, 3) << "\n";
    return 0;
}