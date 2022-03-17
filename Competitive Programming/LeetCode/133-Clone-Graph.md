## LeetCode 133. Clone Graph

### [Question](https://leetcode.com/problems/clone-graph/)

### [C++ Solution](https://leetcode.com/submissions/detail/468944167/)
```c++
class Solution {
public:
    unordered_map <Node*,Node*> visited;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(visited[node]) return visited[node];
        
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        
        for(auto k: node->neighbors)
            cloneNode->neighbors.push_back(cloneGraph(k));
        
        return cloneNode;
    }
};
```

### [Java Solution](https://leetcode.com/submissions/detail/659936567/)
```java
class Solution {
    HashMap<Node, Node> map = new HashMap<>();
    public Node cloneGraph(Node node) {
        if(node == null) return null;
        if(map.containsKey(node))
            return (Node)map.get(node);

        Node newNode = new Node(node.val);
        map.put(node, newNode);

        for(Node child: node.neighbors)
            newNode.neighbors.add(cloneGraph(child));

        return newNode;
    }
};
```