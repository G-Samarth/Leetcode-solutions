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
    bool isValid(TreeNode* root, long min, long max){
        if(!root)
            return true;

        bool l = isValid(root->left, min, root->val);
        bool r = isValid(root->right, root->val, max);

        return l && r && (root->val > min && root->val < max);
    }
public:
    bool isValidBST(TreeNode* root) {
        long min = LONG_MIN, max = LONG_MAX;

        return isValid(root, min, max);
    }
};