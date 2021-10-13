#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/bitwise-and-of-numbers-range/

long long two[32] = {0};
int countOne(int bit, int x) {
    long long d = max(0ll, x - two[bit] + 1);
    return two[bit] * (d / two[bit + 1]) + min(two[bit], d % two[bit + 1]);
}

int rangeBitwiseAnd(int left, int right) {
    if(two[0] == 0) {
        two[0] = 1;
        for(int i = 1; i <= 31; i++) two[i] = 2 * two[i-1];
    }
    
    int ans = 0;
    for(int bit = 0; bit < 31; bit++) {
        int bef = countOne(bit, left - 1);
        int after = countOne(bit, right);
        if(after - bef - 1 == right - left) {
            ans += (1 << bit);
        }
    }
    
    return ans;
}