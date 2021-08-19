// vector<int> ans;

// void dfs(Node *node, int h) {
//     if(node==NULL) return;
    
//     if(ans.size() < h) {
//         ans.push_back(node->data);
//     }
    
//     if(node->left != NULL) {
//         dfs(node->left, h+1);
//     }
    
//     if(node->right != NULL) {
//         dfs(node->right, h+1);
//     }
// }
// //Function to return a list containing elements of left view of the binary tree.
// vector<int> leftView(Node *root)
// {
//    // Your code here
//    ans.clear();
   
//    dfs(root, 1);
   
//    return ans;
// }