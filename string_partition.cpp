#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-labels/

int checkSubstr(string &s, int i, vector<int> &l, vector<int> &r) {
    int right = r[s[i] - 'a'];
    for (auto j = i; j <= right; ++j) {
        if (l[s[j] - 'a'] < i)
            return -1;
        right = max(right, r[s[j] - 'a']);
    }
    return right;
}

vector<int> partitionLabels(string s) {
    vector<int> l(26, INT_MAX), r(26, INT_MIN);
    vector<int> res;
    for (int i = 0; i < s.size(); ++i) {
        l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
        r[s[i] - 'a'] = i;
    }

    int right = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (i == l[s[i] - 'a'] && i > right) {
            int new_right = checkSubstr(s, i, l, r);
            if (new_right != -1) {
                if (i > right) 
                    res.push_back(-1);                     
                right = new_right;
                res.back() = right - i + 1;
            }
        }
    }
    return res;   
}