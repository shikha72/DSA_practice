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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>mp;
        
        stack<pair<int,pair<int, TreeNode*>>>st;//vert,level,node
        st.push({0,{0,root}});
        
        while(!st.empty()){
            auto it=st.top();
            st.pop();
            
            int vert=it.first;
            int levl=it.second.first;
            
            mp[vert][levl].insert(it.second.second->val);
            
            if(it.second.second->left!=NULL){
                st.push({vert-1,{levl+1,it.second.second->left}});
            }
            if(it.second.second->right!=NULL){
                st.push({vert+1,{levl+1,it.second.second->right}});
            }
        }
        
        for(auto it1:mp){
            vector<int>temp;
            for(auto it2:it1.second){
                temp.insert(temp.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};