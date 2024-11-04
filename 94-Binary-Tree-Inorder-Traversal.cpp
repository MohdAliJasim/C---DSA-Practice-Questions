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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }
            else{
                if(st.empty()) break;
                TreeNode* temp = st.top();
                st.pop();
                res.push_back(temp->val);
                temp= temp->right;
                curr = temp;
            }
        }
        return res;
    }
};