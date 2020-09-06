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
    
    void find(vector<int> &a, TreeNode* root){
        if(!root) return;
        
        find(a,root->left);
        a.push_back(root->val);
        find(a,root->right);
    }
    
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> ans1;       
        find(ans1,root1);
        vector<int> ans2;
        find(ans2,root2);
        
        int p1=0,p2=0;
        vector<int> ret;
        
        while(p1<ans1.size() && p2<ans2.size()){
            if(ans1[p1]<ans2[p2]) ret.push_back(ans1[p1++]);
            else ret.push_back(ans2[p2++]);
        }
        while(p1<ans1.size()) ret.push_back(ans1[p1++]);
        while(p2<ans2.size()) ret.push_back(ans2[p2++]);
        
        
        return ret;
        
    }
};
