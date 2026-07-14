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
    int calculateDiff(TreeNode *root){
        if (root==NULL ) return  0;
        int lh= calculateDiff(root->left);
        int rh=  calculateDiff(root->right);
        
        return 1+max(lh,rh);

    }
    int calculateDiff2(TreeNode *root){
        if (root==NULL ) return  0;
        int lh= calculateDiff2(root->left);
        int rh=  calculateDiff2(root->right);
        
        return 1+min(lh,rh);

    }
    bool isBalanced(TreeNode* root) {
        int val1=calculateDiff(root);
        int val2=calculateDiff(root);
        int diff=val2-val1;
        if (abs(diff)<=1) return true;
        else return false;
        
    }
};