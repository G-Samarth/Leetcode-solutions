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
    int maxPathSum(TreeNode* root, int& ans) {
        if(!root)
            return 0;

        int l = max(maxPathSum(root->left, ans), 0);
        int r = max(maxPathSum(root->right, ans), 0);

        int curr = root->val + l + r;
        ans = max(ans, curr);

        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;

        maxPathSum(root, ans);
        return ans;
    }
};