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
    map<Node*, Node*> org_to_copy;
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return node;
        }
        if(org_to_copy.count(node)){
            return org_to_copy[node]; // important else goes into indefinite loop.
        }
        Node* copy = new Node();
        org_to_copy[node] = copy;
        copy->val = node->val;
        for(Node* x: node->neighbors){
            copy->neighbors.push_back(cloneGraph(x));
        }
        return copy;
    }

};
