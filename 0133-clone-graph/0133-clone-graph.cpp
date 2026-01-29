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
    Node* helper(Node* node, unordered_map<Node*, Node*>& map){
        if(!node)
            return NULL;
        
        if(map[node]){
            return map[node];
        }else{
            Node* temp = new Node(node->val);
            map[node] = temp;
            
            for(auto adj : node->neighbors){
                temp->neighbors.push_back(helper(adj, map));
            }
            
            return temp;
        }
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        return helper(node, map);
    }
};