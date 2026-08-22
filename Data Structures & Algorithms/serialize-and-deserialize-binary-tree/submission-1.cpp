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

class Codec {
public:

    void help(TreeNode* root, string &s){
        if(root==NULL){
            s+='#';
            s+=',';
            return;
        }
        s+=to_string(root->val)+",";
        help(root->left,s);
        help(root->right,s);
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s ="";
        help(root,s);
        return s;
        
    }

    TreeNode* help2(string &data, int &idx){
        if(data[idx]=='#'){
            idx+=2;
            return nullptr;
        }


        string temp ="";
        while(data[idx]!=','){
            temp+=data[idx];
            idx++;
        }
        idx+=1;
        TreeNode* root = new TreeNode(stoi(temp));
        root->left = help2(data,idx);
        root->right=help2(data,idx);

        return root;


    }




    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.empty()) return nullptr;

        int idx = 0;
        TreeNode* root = help2(data,idx);
        return root;

    }
};
