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
    
    vector<vector<int>> ans;
    
    queue<TreeNode*> q;
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        q.push(root);
        
        while(!q.empty()){
               vector<int> levels; 
            
                for(int i=q.size();i>0;i--){
                    auto cur = q.front();q.pop();
                    levels.push_back(cur->val);              
                    
                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }
                ans.push_back(levels);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
