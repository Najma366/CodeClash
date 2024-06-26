#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node* next;
    Node(char x) {
        data = x;
        next = NULL;
    }
};
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
bool compareLists(struct Node* list1, struct Node* list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->data != list2->data)
            return false;
        list1 = list1->next;
        list2 = list2->next;
    }
    return true;
}
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return true; 
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev_slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }
    if (fast != NULL)
        slow = slow->next;
    reverse(&slow);
    return compareLists(head, slow);
}
struct Node* createLinkedList() {
    int n;
    cin >> n;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < n; ++i) {
        char val;
        cin >> val;
        struct Node* newNode = new Node(val);
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
    struct Node* head = createLinkedList();
    if (isPalindrome(head))
        cout << "True";
    else
        cout << "False";
}

