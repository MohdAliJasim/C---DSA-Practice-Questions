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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        while(temp!=nullptr){
            if(temp->val > val){
                if(!temp->left){
                    TreeNode* node = new TreeNode(val);
                    temp->left = node;
                    return root;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(!temp->right){
                    TreeNode* node = new TreeNode(val);
                    temp->right = node;
                    return root;
                }
                else temp = temp->right;
            }
        }   
        TreeNode* node = new TreeNode(val);
        root = node ;
        return root;
    }
};