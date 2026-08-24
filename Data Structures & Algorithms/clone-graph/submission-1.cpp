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

    Node* help(Node* node, unordered_map<Node*,Node*> &mp){
        if(node==nullptr) return nullptr;

        if(mp.count(node)>0){
            return mp[node];
        }

        Node* clone = new Node(node->val);
        mp[node]=clone;

        for(auto adj: node->neighbors){
            clone->neighbors.push_back(help(adj,mp));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {

        unordered_map<Node*,Node*> mp;
        return help(node,mp);
    }
};
