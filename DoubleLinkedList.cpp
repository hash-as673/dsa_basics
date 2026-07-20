#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    ListNode *next = nullptr;
    ListNode *prev = nullptr;
    int _val = 0;
    ListNode(int val) {
        _val = val;
    }
};

// --- Helper Functions for DLL Operations ---

// 1. Traverse and print the list from front to back
void displayForward(ListNode* head) {
    ListNode* temp = head;
    cout << "Forward:  ";
    while (temp != nullptr) {
        cout << temp->_val << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// 2. Traverse and print the list from back to front
void displayBackward(ListNode* tail) {
    ListNode* temp = tail;
    cout << "Backward: ";
    while (temp != nullptr) {
        cout << temp->_val << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

// 3. Insert a new node at the very beginning
void insertAtHead(ListNode* &head, ListNode* &tail, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// 4. Insert a new node at the very end
void insertAtTail(ListNode* &head, ListNode* &tail, int val) {
    ListNode* newNode = new ListNode(val);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// 5. Insert a node after a specific value
void insertAfterValue(ListNode* head, ListNode* &tail, int target, int val) {
    ListNode* temp = head;
    while (temp != nullptr && temp->_val != target) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value " << target << " not found. Insertion failed.\n";
        return;
    }

    ListNode* newNode = new ListNode(val);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    } else {
        tail = newNode; // If inserted after the last element, update tail
    }
    temp->next = newNode;
}

// 6. Delete the first node
void deleteHead(ListNode* &head, ListNode* &tail) {
    if (head == nullptr) return;

    ListNode* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr; // List became empty
    }
    delete temp;
}

// 7. Delete the last node
void deleteTail(ListNode* &head, ListNode* &tail) {
    if (tail == nullptr) return;

    ListNode* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr; // List became empty
    }
    delete temp;
}

// 8. Delete a node by its value
void deleteValue(ListNode* &head, ListNode* &tail, int target) {
    if (head == nullptr) return;

    ListNode* temp = head;
    while (temp != nullptr && temp->_val != target) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value " << target << " not found. Deletion failed.\n";
        return;
    }

    // If it's the head node
    if (temp == head) {
        deleteHead(head, tail);
        return;
    }
    // If it's the tail node
    if (temp == tail) {
        deleteTail(head, tail);
        return;
    }

    // If it's a middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

// 9. Search for a value in the list
bool search(ListNode* head, int target) {
    ListNode* temp = head;
    while (temp != nullptr) {
        if (temp->_val == target) return true;
        temp = temp->next;
    }
    return false;
}

int main() {
    // Initialize empty list pointers
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "=== INSERTION OPERATIONS ===\n";
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10); // List: 10 <-> 20
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40); // List: 10 <-> 20 <-> 30 <-> 40

    displayForward(head);

    cout << "\nInserting 25 after 20:\n";
    insertAfterValue(head, tail, 20, 25); // List: 10 <-> 20 <-> 25 <-> 30 <-> 40
    displayForward(head);
    displayBackward(tail);

    cout << "\n=== SEARCH OPERATION ===\n";
    cout << "Is 25 in the list? " << (search(head, 25) ? "Yes" : "No") << "\n";
    cout << "Is 99 in the list? " << (search(head, 99) ? "Yes" : "No") << "\n";

    cout << "\n=== DELETION OPERATIONS ===\n";
    cout << "Deleting head (10):\n";
    deleteHead(head, tail);
    displayForward(head);

    cout << "Deleting tail (40):\n";
    deleteTail(head, tail);
    displayForward(head);

    cout << "Deleting middle value (25):\n";
    deleteValue(head, tail, 25);
    displayForward(head);
    displayBackward(tail);

    // Clean up remaining memory before exiting
    while (head != nullptr) {
        deleteHead(head, tail);
    }

    return 0;
}