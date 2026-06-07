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
int MaxSum=INT_MIN;
int solve(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int l=solve(root->left);
     int r=solve(root->right);
     int neche_mil_gya_ans= l+r+root->val;
     int koi_ek_ans = max(l,r)+root->val;
     int only_root_acha = root->val;
     MaxSum= max({MaxSum,neche_mil_gya_ans, koi_ek_ans, only_root_acha});
     return max(koi_ek_ans , only_root_acha );
}
    int maxPathSum(TreeNode* root) {
        
         solve(root);
         return MaxSum;
    }
};