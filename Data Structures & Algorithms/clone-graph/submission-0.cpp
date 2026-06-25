/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:

    Node* dfs(Node* node, unordered_map<int,Node*> &s){

        Node* new_graph = new Node(node->val);
        s[node->val] = new_graph;

        for(auto x: node->neighbors){
            if(s.find(x->val)!=s.end()){
                new_graph->neighbors.push_back(s[x->val]);
            }else{
                Node* new_child = dfs(x,s);
                new_graph->neighbors.push_back(new_child);

            }
        }
        return new_graph;

    }

    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<int, Node*> s;
        return dfs(node,s);
    }
};


// think recursively

// 1        1 
//         []=
// []=234


// i will have adjacency list node in dfs;

// every time it traverse a adjacent node 
// u put it in adjacency list and call dfs recuresively;

// time complexity is (v+e);





// 1-2
// |
// 3-2