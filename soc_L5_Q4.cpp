#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reorderList(ListNode* head) {
    if (!head || !head->next)
        return head; 
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
ListNode* createLinkedList() {
    int n;
    cin >> n;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
       	else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    ListNode* head = createLinkedList();
    head = reorderList(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}

