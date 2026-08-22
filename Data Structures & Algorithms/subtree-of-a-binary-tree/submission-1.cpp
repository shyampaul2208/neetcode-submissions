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
    bool isSametree(TreeNode* root, TreeNode* subRoot){
        if(root==NULL && subRoot ==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;

        return root->val==subRoot->val && isSametree(root->left,subRoot->left) && isSametree(root->right,subRoot->right);


    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root==NULL && subRoot ==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;

        return isSametree(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }
};
