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


    int help(TreeNode* root, int &ans){

        if(root->left==NULL && root->right==NULL){
            ans = max(ans, root->val);
            return root->val;
        }else if(root->left==NULL){
            int rs = help(root->right,ans);
            ans = max({ans, rs, rs+root->val,root->val});
            return max(rs+root->val, root->val);
        }else if(root->right==NULL){
            int ls = help(root->left,ans);
            ans = max({ans, ls, ls+root->val,root->val});
            return max(ls+root->val, root->val);
        }else{
            int rs = help(root->right,ans);
            int ls = help(root->left,ans);
            ans = max({ans,rs,ls,rs+root->val,ls+root->val,ls+rs+root->val,root->val});
            return max({ls+root->val,rs+root->val,root->val});

        }

        return -10000;


    }




    int maxPathSum(TreeNode* root) {
        int ans =INT_MIN;
        help(root,ans);
        return ans;
    }
};
