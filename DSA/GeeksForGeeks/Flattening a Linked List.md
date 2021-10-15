### GeeksForGeeks - Flattening a Linked List

[Question](https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=13d62ccc846e21c0d7aaee0f9955a1ca&pid=700192&user=amanguptarkg6)
| [Article](https://www.geeksforgeeks.org/flattening-a-linked-list/)

##### C++
```c++
Node* merge(Node* a, Node* b){
    if(a == NULL) return b;
    if(b == NULL) return a;
    Node* c;
    if(a->data < b->data)   c = a, c->bottom = merge(a->bottom, b);
    else                    c = b, c->bottom = merge(a, b->bottom);
    c->next = NULL;
    return c;
}

Node *flatten(Node *root){
    if(root == NULL || root->next == NULL)
        return root;
    
    root->next = flatten(root->next);
    root = merge(root, root->next);
    
    return root;
}
```
