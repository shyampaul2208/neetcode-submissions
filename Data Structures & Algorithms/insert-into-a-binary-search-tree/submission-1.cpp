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

    void help(TreeNode* root, int val){
        if(root==NULL){
            root = new TreeNode(val);
            return;
        }

        if(val > root->val){
            if(root->right) help(root->right,val);
            else{
                root->right = new TreeNode(val);
            }
        }else if(val<root->val){
            if(root->left) help(root->left,val);
            else{
                root->left = new TreeNode(val);
            }
        }


    }









    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root==NULL) return new TreeNode(val);
        help(root,val);
        return root;

        
    }
};