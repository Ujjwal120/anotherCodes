#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int n;
    vector<pair<int, int>> segtree;

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        n = nums.size();
        segtree.resize(2*n);
        
        for(int i = 0; i < n; i++) {
            segtree[i+n] = {nums[i], i};
        }
        
        for(int i = n-1; i > 0; i--) {
            auto child1 = segtree[i<<1];
            auto child2 = segtree[i<<1|1];
            if(child1.first > child2.first) {
                segtree[i] = child1;
            }
            else segtree[i] = child2;
        }
        
        return rec(0, n-1, nums);
        
    }
    
    int query(int l, int r) {
        l += n; r += n;
        pair<int, int> res = {-1, -1};
        for(; l < r; l >>= 1, r >>= 1) {
            if(l&1) {
                if(segtree[l].first > res.first) {
                    res = segtree[l];
                }
                l++;
            }
            if(r&1) {
                --r;
                if(segtree[r].first > res.first) {
                    res = segtree[r];
                }
            }
        }
        
        return res.second;
    }
    
    TreeNode* rec(int l, int r, vector<int>& nums) {
        TreeNode *a = new TreeNode();
        if(l == r) {
            a->val = nums[l];
            return a;
        }
        
        int div_ind = query(l, r+1);
        a->val = nums[div_ind];
        
        if(div_ind != l) a->left = rec(l, div_ind-1, nums);
        if(div_ind != r) a->right = rec(div_ind+1, r, nums);
        
        return a;
        
    }
};