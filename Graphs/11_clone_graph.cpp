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
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        
        // making the first node of the deep copy with no neighbors initially 
        Node* copy = new Node(node->val, {});
        
        // map to bind original graph nodes with deep copy nodes to make connections after 
        unordered_map<Node*, Node*>bindings;
        
        // mapping of first node of original and deep copies 
        bindings[node] = copy;
        
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            for(Node* neighbor : curr->neighbors){
                if(bindings.find(neighbor) == bindings.end()){
                    bindings[neighbor] = new Node(neighbor->val, {});
                    q.push(neighbor);
                }
                // making the mappings of neighbors of current node 
                bindings[curr]->neighbors.push_back(bindings[neighbor]);
            }
        }
        return copy; 
    }
};