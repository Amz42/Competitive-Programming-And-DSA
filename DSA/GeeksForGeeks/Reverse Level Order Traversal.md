## [Reverse Level Order Traversal](https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1)

### Solution 1: Java - Using level order traversal
```java
class Tree {
    public ArrayList<Integer> reverseLevelOrder(Node node) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        Queue<Node> q = new LinkedList<>();
        
        q.add(node);
        
        while(q.size() > 0) {
            Node n = q.remove();
            list.add(n.data);
            
            if(n.right != null) q.add(n.right);
            if(n.left != null) q.add(n.left);
        }
        
        Collections.reverse(list);
        
        return list;
    }
}
```