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
TreeNode* build(vector<int>& nums,int left,int right){
    if(left>right) return NULL;
int mid=(left+right)/2;
if(left>right) return NULL;
TreeNode* root=new TreeNode(nums[mid]);
root->left=build(nums,left,mid-1);
root->right=build(nums,mid+1,right);
return root;

}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left=0; int right=nums.size()-1;
        return build(nums,left,right);
    }
};