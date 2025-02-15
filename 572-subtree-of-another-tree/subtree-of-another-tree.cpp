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
    bool isSame(TreeNode* p, TreeNode *q){
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        if(p->val != q->val)
            return false;

        bool l = isSame(p->left, q->left);
        bool r = isSame(p->right, q->right);

        return l && r;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode *temp = root;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *top = q.front();
            q.pop();

            if(top->val == subRoot->val){
                if(isSame(top, subRoot))
                    return true;
            }

            if(top->left)
                q.push(top->left);
            if(top->right)
                q.push(top->right);
        }

        return false;
    }
};