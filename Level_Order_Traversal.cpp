// class Solution
// {
//     public:
//     //Function to return the level order traversal of a tree.
//     vector<int> levelOrder(Node* node)
//     {
//       //Your code here
//       vector<int> ans;
      
//       queue<Node *> q;
      
//       q.push(node);
      
//       while(!q.empty()) {
//           Node *x = q.front();
//           q.pop();
          
//           ans.push_back(x->data);
          
//           if(x->left != NULL) q.push(x->left);
//           if(x->right != NULL) q.push(x->right);
          
//       }
      
//       return ans;
//     }
// };