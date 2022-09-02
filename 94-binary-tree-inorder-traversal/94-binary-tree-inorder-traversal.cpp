/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>nodes;
        
        if(root==NULL)
            return nodes;
        
        if(root->left){
            vector<int>left=inorderTraversal(root->left);
            for(auto it: left)
                nodes.push_back(it);
        }
        
        nodes.push_back(root->val);
        
        if(root->right){
            vector<int>right=inorderTraversal(root->right);
            for(auto it: right)
                nodes.push_back(it);
        }
         
        return nodes;
        
    }
};