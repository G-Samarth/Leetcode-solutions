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
    bool bstCheck(TreeNode* root, long long left, long long right){
        if(!root)
            return true;
        if(root->val <= left || root->val >= right)
            return false;

        return bstCheck(root->left, left, root->val) && bstCheck(root->right, root->val, right);
    }
public:
    bool isValidBST(TreeNode* root) {
            return bstCheck(root, LLONG_MIN, LLONG_MAX);
    }
};