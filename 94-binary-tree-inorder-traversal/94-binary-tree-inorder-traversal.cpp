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

//MORRIS INORDER TRAVERSAL

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                //find rightmost node of left subtree
                while(prev->right!=NULL && prev->right!=curr)
                    prev=prev->right;
                
                if(prev->right==curr){
                    //means left subtree has been visited so move right
                    inorder.push_back(curr->val);
                    prev->right=NULL;//remove thread
                    curr=curr->right;
                }
                else{
                    //means we have to visit left subtree so move left
                    prev->right=curr;//create thread
                    curr=curr->left;
                }
            }
        }
        return inorder;
    }
};