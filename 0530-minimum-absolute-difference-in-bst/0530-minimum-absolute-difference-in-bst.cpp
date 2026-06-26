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
void inorder(TreeNode* root, int &diff, int &mini,TreeNode* &prev){
    if(root==NULL) return;
    inorder(root->left,diff,mini,prev);
    if (prev!=NULL){
        diff=(abs(root->val-prev->val));
        mini=min(mini,diff);
    }
    prev=root;
    inorder(root->right,diff,mini,prev);
    
}
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX; int diff=0; TreeNode*prev=NULL;
inorder(root,diff,mini,prev);
return mini;
    }
};