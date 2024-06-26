#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* rest = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

ListNode* createList(){
	int n;
	cin >> n;
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	for(int i = 0; i < n; ++i){
	       int val;
               cin >>val;
          if(head == nullptr){
                 head = new ListNode(val);
                 tail = head;
	  }
	  else{
		  tail->next = new ListNode(val);
		  tail = tail = tail->next;
	  }
	}
	return head;
}
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = createList();
    printList(head);
    ListNode* reversedHead = reverseList(head);
    printList(reversedHead);
}

