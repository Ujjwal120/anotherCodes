#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define int long long 
using namespace std;

const int maxn = 1e5+10;
int isProperty[maxn];
int two[] = {1, 2, 4, 8, 6, 2, 4, 8, 6, 2, 4};
vector<int> dig;

bool test(int x) {
    dig.clear();
    while(x) {
        dig.push_back(x%10);
        x /= 10;
    }
    reverse(dig.begin(), dig.end());

    int sum = 0;
    for(int i = 0; i < dig.size(); i++) {
        sum += dig[i] * two[i];
    }

    return (sum&1);
}

void init() {
    int cnt = 0;
    for(int i = 1; i <= maxn; i++) {
        if(test(i)) {
            cnt++;
            isProperty[i] = 1;
        }
    }
    cout << cnt << endl;
}

void solve() {
    int k; cin >> k;
    for(int i = 901; i < 1000; i++) cout << isProperty[i] << " ";
    cout << "\n";
}

signed main() {
    fast int t = 1;
    cin >> t;
    init();
    while(t--) solve();
    return 0;
}