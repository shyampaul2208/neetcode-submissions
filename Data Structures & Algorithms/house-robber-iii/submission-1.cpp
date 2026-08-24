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

    int help(TreeNode* root, int taken, unordered_map<TreeNode*,vector<int>> &mp){

        if (!mp.count(root)) {
            mp[root] = vector<int>(2, -1);
        }
        if(mp.count(root)&& mp[root][taken] != -1) return mp[root][taken];
        if(root==NULL) return 0;
        if(taken==0){
            return mp[root][taken] = max(root->val + help(root->left,1,mp)+help(root->right,1,mp), help(root->left,0,mp)+help(root->right,0,mp));
        }

        return mp[root][taken] = help(root->left,0,mp)+help(root->right,0,mp);
        
        
    }


    int rob(TreeNode* root) {

        unordered_map<TreeNode*,vector<int>> mp;
        return help(root,0,mp);
    }
};