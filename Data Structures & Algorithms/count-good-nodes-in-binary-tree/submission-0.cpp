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

    void help(TreeNode* root, int pathMax, int &count){
        if(root==NULL) return;
        if(root->val >= pathMax){
            count++;
            pathMax=root->val;
        }

        help(root->left,pathMax,count);
        help(root->right,pathMax,count);
    }





    int goodNodes(TreeNode* root) {
        int count =0;
        help(root,root->val,count);
        return count;

        
    }
};
