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
    int curr = 0;
public:
    TreeNode* buildTree(int start, int end, vector<int>& preorder, vector<int>& inorder) {
        if(start > end)
            return NULL;

        int i = start;
        while(inorder[i] != preorder[curr])
            i++;

        TreeNode* root = new TreeNode(inorder[i]);
        curr++;
        
        root->left = buildTree(start, i-1, preorder, inorder);
        root->right = buildTree(i+1, end, preorder, inorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(0, inorder.size()-1, preorder, inorder);
    }
};