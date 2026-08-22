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

    void help(TreeNode* root, int h, int &maxh,vector<int> &ans){
        if(root==NULL) return;
        if(h>maxh){
            ans.push_back(root->val);
            maxh = h;
        }

        help(root->right,h+1,maxh,ans);
        help(root->left,h+1,maxh,ans);
    }



    vector<int> rightSideView(TreeNode* root) {
        int h =0;
        int maxh = -1;
        vector<int> ans;
        help(root,h,maxh,ans);
        return ans;

    }
};
