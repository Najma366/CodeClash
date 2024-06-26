#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(struct ListNode* head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next; 
        fast = fast->next->next; 
        if (slow == fast) {
            return true;
        }
    }
    return false; 
}
struct ListNode* createLinkedList(){
	int n;
	cin >> n;
	struct ListNode* head = NULL;
	struct ListNode* tail = NULL;
	for(int i = 0; i < n; ++i){
		int val;
		cin >> val;
		struct ListNode* newListNode = new ListNode(val);
		if(!head){
			head = newListNode;
			tail = newListNode;
		}
		else{
			tail->next = newListNode;
			tail = newListNode;
		}
	}
	int pos;
	cin >>pos;
	if(pos >= 0 && pos < n){
		struct ListNode* temp =head;
		for(int i = 0; i < pos; ++i)
			temp = temp->next;
		tail->next = temp;
	}
	return head;
}

int main() {
    struct ListNode* head = createLinkedList();
    head->next->next->next->next = head->next; 
    if(hasCycle(head))
	    cout << "True";
    else
	    cout << "False";
}

