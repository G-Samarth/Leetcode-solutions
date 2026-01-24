/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        
        queue<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* top = st.front();
            st.pop();

            if(!top){
                ans += "#,";
            }else{
                ans += to_string(top->val) + ',';
                st.push(top->left);
                st.push(top->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 2)
            return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                top->left = NULL;
            }else{
                TreeNode* temp = new TreeNode(stoi(str));
                top->left = temp;
                q.push(temp);
            }

            getline(s, str, ',');
            if(str == "#"){
                top->right = NULL;
            }else{
                TreeNode* temp = new TreeNode(stoi(str));
                top->right = temp;
                q.push(temp);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));