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






TreeNode* help(vector<int> &A, vector<int> &B,int instart,int inend,int &preindex){

    if(instart>inend)
       return NULL;
    TreeNode* root=new TreeNode(A[preindex++]);
    
    int k;
    for(int i=instart;i<=inend;i++){
        if(B[i]==root->val)
        {
         k=i;
         break;
        } 
    }

    root->left=help(A,B,instart,k-1,preindex);
    root->right=help(A,B,k+1,inend,preindex);
   
   return root;
}



    TreeNode* buildTree(vector<int>& A, vector<int>& B) {

    int n=B.size()-1;
   int preindex=0;
   TreeNode* k= help(A,B,0,n,preindex);
    return k;
        
    }
};
