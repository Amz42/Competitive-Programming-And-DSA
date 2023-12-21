# [Detect And Remove Cycle](https://www.codingninjas.com/studio/problems/detect-and-remove-cycle_920523)

## Solution:
```c++
bool detectAndRemoveCycle(Node* head) {
	Node* fast = head;
	Node* slow = head;
	Node* prev = nullptr;

	while(fast != nullptr && fast->next != nullptr) {
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;

		if(fast == slow) {
			slow = head;
			while(fast != slow) {
				prev = prev->next;
				fast = fast->next;
				slow = slow->next;
			}
			prev->next = nullptr;

			return true;
		}
	}

	return false;
}
```