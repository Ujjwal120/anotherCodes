// vector<int> ans;
// map<int, pair<int, int>> l;

// class Solution
// {
//     public:
//     //Function to return a list of nodes visible from the top view 
//     //from left to right in Binary Tree.
//     vector<int> topView(Node *root)
//     {
//         //Your code here
//         ans.clear();
//         l.clear();
        
//         l[0] = {root->data, 0};
//         dfs(root, 0, 0);
        
//         for(auto i = l.begin(); i != l.end(); i++) {
//             ans.push_back(i->second.first);
//         } 
        
//         return ans;
//     }
    
//     void dfs(Node *node, int h, int len) {
//         if(node==NULL) return;
        
//         if(l.count(h) == 0 || l[h].second > len) {
//             l[h].second = len;
//             l[h].first = node->data;
//         }
        
//         if(node->left != NULL) {
//             dfs(node->left, h-1, len+1);
//         }
        
//         if(node->right != NULL) {
//             dfs(node->right, h+1, len+1);
//         }
//     }

// };