# [Detect The Cycle](https://www.codingninjas.com/studio/problems/detect-the-cycle_1822910)

# Solution:
```c++
bool detectCycle(Node *head){
	Node* slow = head;
	Node* fast = head;

	while(fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;

		if(fast == slow) {
			return true;
		}
	}

	return false;
}
```