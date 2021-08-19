// vector<int> adj[10001];
// int cnt = 0;
// int diam, leaflen;

// class Solution {
//   public:
//     // Function to return the diameter of a Binary Tree.
//     int diameter(Node* root) {
//         // Your code here
//         for(int i = 0; i < 10001; i++) {
//             adj[i].clear();
//         }        
        
//         cnt = 0;
//         dfs(root);
        
//         diam = 0;
        
//         leaflen = 0;
//         dfs_1(0, -1, 0);
        
//         dfs_1(diam, -1, 0);
        
//         return leaflen+1;
//     }
    
//     void dfs_1(int node, int par, int len) {
//         if(adj[node].size() == 1) {
//             if(len > leaflen) {
//                 diam = node;
//                 leaflen = len;
//             }
//         }
        
//         for(int x : adj[node]) {
//             if(x != par) {
//                 dfs_1(x, node, len+1);
//             }
//         }
        
//     }
    
//     void dfs(Node* node) {
//         if(node == NULL) return;
        
//         int rem = cnt;
//         if(node->left != NULL) {
//             adj[rem].push_back(cnt+1);
//             adj[cnt+1].push_back(rem);
//             cnt+=1;
//             dfs(node->left);
//         }
        
//         if(node->right != NULL) {
//             adj[rem].push_back(cnt+1);
//             adj[cnt+1].push_back(rem);
//             cnt+=1;
//             dfs(node->right);
//         }
//     }
// };