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
 class info {
    public:
    int maxi;
    int mini;
    bool isBST;
    int sum;
 };
class Solution {
    info solve(TreeNode* root, int &ans){
        if(root == NULL){
            return {INT_MIN, INT_MAX,true,0};
        }

        info left = solve(root->left, ans);
        info right = solve(root->right, ans);

        info curr;

        curr.maxi = max(root->val, right.maxi);
        curr.mini = min(root->val , left.mini);
        curr.sum = left.sum + right.sum + root->val;

        if(left.isBST && right.isBST && left.maxi < root->val && right.mini > root->val){
            curr.isBST = true;
        }
        else{
            curr.isBST =false;
        }

        if(curr.isBST){
            ans = max(ans, curr.sum);
        }
        return curr;
    }
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        info temp = solve(root, maxSum);
        return maxSum;
    }
};