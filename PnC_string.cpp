#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/letter-tile-possibilities/

set<string> all;
int fact[8] = {1, 1, 2, 6, 24, 120, 720, 5040};

int numTilePossibilities(string tiles) {
    sort(tiles.begin(), tiles.end());
    int n = tiles.size();
    for(int bitMask = 1; bitMask < (1<<n); bitMask++) {
        string s = "";
        for(int i = 0; i < n; i++) {
            if(bitMask & (1<<i)) s += tiles[n-1-i]; 
        }
        all.insert(s);
    }
    
    vector<int> f(26, 0);
    int ans = 0;
    for(auto x : all) {
        int temp = 0;
        for(auto ch : x) f[ch - 'A']++;
        temp = fact[x.size()];
        for(int j = 0; j < 26; j++) {
            temp /= fact[f[j]];
        }
        ans += temp;
        for(int j = 0; j < 26; j++) f[j] = 0;
    }
    
    return ans;
}