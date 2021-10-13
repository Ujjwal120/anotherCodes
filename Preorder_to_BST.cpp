#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* bstFromPreorder(vector<int>& preorder) {
    vector<TreeNode *> st;
    int n = preorder.size();
    TreeNode *root = nullptr;
    
    for(int i = 0; i < n; i++) {
        TreeNode *cur = new TreeNode(preorder[i]);
        
        while(!st.empty() && st.back()->val < preorder[i]) {
            if(st.size() > 1) {
                // second last is greater?
                if(st[st.size() - 2]->val > preorder[i]) {
                    // attach right
                    st.back()->right = cur;
                    st.pop_back();
                    st.push_back(cur);
                }
                else if(st[st.size() - 2]->val > st.back()->val) {
                    st.pop_back();
                }
                else {
                    st.back()->right = cur;
                    st.pop_back();
                    st.push_back(cur);
                }
            }
            else {
                st.back()->right = cur;
                st.push_back(cur);
            }
        }
        
        if(st.empty()) {
            root = cur;
            st.push_back(cur);
        }
        else {
            if(st.back()->val > preorder[i]) {
                st.back()->left = cur;
                st.push_back(cur);
            }
        }
    }
    
    return root;
}