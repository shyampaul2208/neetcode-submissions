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

    int help(TreeNode* root, int pathMax){
        if(root==NULL) return 0;
        int count =0;
        if(root->val >= pathMax){
            count++;
            pathMax=root->val;
        }

        count+=help(root->left,pathMax);
        count+=help(root->right,pathMax);
        return count;
    }





    int goodNodes(TreeNode* root) {
        return help(root,root->val);
        
    }
};
