#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
int countOfNodes(ListNode* head) {
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}
ListNode* deleteMid(ListNode* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    ListNode* copyHead = head;
    int count = countOfNodes(head);
    int mid = count / 2;
    while (mid-- > 1) {
        head = head->next;
    }
    head->next = head->next->next;
    return copyHead;
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
    head = deleteMid(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

