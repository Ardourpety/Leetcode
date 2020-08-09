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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return sumnode(root,0,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
    
    int sumnode(TreeNode* root,int total,int target){
        if(!root) return 0;
        int current=total+root->val;
        return (current==target) + sumnode(root->right,current,target)+sumnode(root->left,current,target);
    }
};
