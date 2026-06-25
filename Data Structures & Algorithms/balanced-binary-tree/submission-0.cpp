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


    pair<bool,int> help(TreeNode* root){

        if(root==NULL) return{true,0};
        auto lh = help(root->left);
        auto rh = help(root->right);

        if(abs(lh.second - rh.second) >1) return {false,max(lh.second,rh.second)+1};

        return {lh.first && rh.first , max(lh.second,rh.second)+1};



    }



    bool isBalanced(TreeNode* root) {
        pair<bool,int> ans = help(root);
        return ans.first;
    }
};
