#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* mergeLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    while(l1 && l2){
	    if(l1->val <= l2->val){
		    current->next = l1;
		    l1 = l1->next;
	    }
	    else{
		    current->next = l2;
		    l2 = l2->next;
	    }
	    current = current->next;

    }
    if(l1){
	    current->next = l1;
    }
    else{
	    current->next = l2;
    }
    return dummy.next;
}
ListNode* sortList(ListNode* head) {
    if(!head || !head->next){
	    return head;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast && fast->next){
	    slow  = slow->next;
	    fast = fast->next->next;
    }
    ListNode* secondhalf = slow->next;
    slow->next = nullptr;
    ListNode* sortedFirstHalf = sortList(head);
    ListNode* sortedSecondHalf= sortList(secondhalf);
    return mergeLists(sortedFirstHalf, sortedSecondHalf);
}
ListNode* createListFromInput() {
    ListNode dummy(0);
    ListNode* current = &dummy;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy.next;
}
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = createListFromInput();
    printList(head);
    head = sortList(head);
    printList(head);
}

