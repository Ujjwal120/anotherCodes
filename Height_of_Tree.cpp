// class Solution{
//     public:
//     //Function to find the height of a binary tree.
//     int height(struct Node* node){
//         // code here 
//         dfs(node);
//     }
    
//     int dfs(struct Node* node) {
    
//         if(node == NULL) return 0;
        
//         int h1 = 1, h2 = 1;
        
//         if(node->left != NULL) {
//             h1 += dfs(node->left);
//         }
//         if(node->right != NULL) {
//             h2 += dfs(node->right);
//         }
        
//         return max(h1, h2);
//     } 
// };