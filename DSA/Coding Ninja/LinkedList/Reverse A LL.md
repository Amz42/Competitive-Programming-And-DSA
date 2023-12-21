# [Reverse A LL](https://www.codingninjas.com/studio/problems/reverse-a-ll_2271431)

## Solution:
```c++
Node* reverse(Node* node){
	if(node == nullptr || node->next == nullptr)
		return node;
	
	Node* newHead = reverse(node->next);
	node->next->next = node;
	node->next = nullptr;
	return newHead;
}

Node *reverseLL(Node *head, int low, int high) {
	Node *a, *b, *c, *d;
	a = b = c = d = nullptr;
	
	Node* curr = head;
	int pos = 1;
	while(curr != nullptr) {
		if(pos == low - 1) a = curr;
		if(pos == low) b = curr;
		if(pos == high) c = curr;
		if(pos == high + 1) d = curr;
		
		curr = curr->next;
		pos++;
	}

	if(a != nullptr)
		a->next = nullptr;
	c->next = nullptr;

	Node* newHead = reverse(b);
	if(a != nullptr)
		a->next = newHead;

	c = newHead;
	while(c->next != nullptr)
		c = c->next;
	c->next = d;
	
	return low == 1 ? newHead : head;
}
```