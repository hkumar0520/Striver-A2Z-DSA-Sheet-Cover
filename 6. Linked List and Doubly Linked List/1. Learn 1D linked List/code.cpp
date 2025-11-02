
#include <bits/stdc++.h>
using namespace std;


class Node{
    public: 
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = nullptr;
        }
        Node(int val, Node* nextNode) {
            data = val;
            next = nextNode;
        }
};

// TC: O(n)
// SC: O(n)
Node* convertArrayToLinkedList(vector<int>& arr) {
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;

    for(int i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

// TC: O(n)
// SC: O(1)
void printLinkedList(Node* head) {
    Node* current = head;
    while(current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// TC: O(n)
// SC: O(1)
int lengthOfLinkedList(Node* head) {
    Node* current = head;
    int length = 0;
    while(current != nullptr) {
        current = current->next;
        length++;
    }
    return length;
}

// TC: O(n)
// SC: O(1)
bool checkIfPresent(Node* head, int val) {
    Node* current = head;
    while(current != nullptr) {
        if(current->data == val) {
            return true;
        }
        current = current->next;
    }
    return false;
}

/*
    Deletion in Linked List:
    1. Delete the head node
    2. Delete The last node
    3. Delete a node with a specific value
    4. Delete a node at a specific position
*/

Node* deleteHead(Node* head) {
    if(head == nullptr) return nullptr;
    Node*  temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteLast(Node* head) {
    if(head == nullptr) return nullptr;
    if(head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* current = head;
    while(current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    return head;
}


// 1 based indexing
Node* deleteAtK(Node* head, int k){
    if(head == nullptr || k <= 0) return head;
    if( k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* current = head, *prev = nullptr;
    while(current != nullptr ){
        cnt++;
        if(cnt == k){
            prev->next = current->next;
            delete current;
            break;
        }
        prev = current;
        current = current->next;
    }
    return head;
}

Node* deleteAtValue(Node* head, int Element){
    if(head == nullptr ) return head;
    if( head->data == Element) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* current = head, *prev = nullptr;
    while(current != nullptr ){
        if(current->data == Element){
            prev->next = current->next;
            delete current;
            break;
        }
        prev = current;
        current = current->next;
    }
    return head;
}

/*
    Insertion in Linked List:
    1. Insert at head
    2. Insert at tail
    3. Insert at a specific position (1 based indexing)
    4. Insert before a specific value
*/

Node* InsertAtHead(Node* head, int val){
    return new Node(val, head);
}

Node* InsertAtTail(Node* head, int val){
    if(head == nullptr) {
        return new Node(val);
    }
    Node* current = head;
    while(current->next != nullptr) {
        current = current->next;
    }
    current->next = new Node(val);
    return head;
}

Node* InsertAtK(Node* head, int k, int val){
    if( k <= 0) return head;
    if(head == nullptr) {
        if(k == 1) {
            return new Node(val);
        } else {
            return head; // Invalid position
        }
    }
    if(k == 1) {
        return new Node(val, head);
    }
    Node* current = head;
    int cnt = 0;
    while(current != nullptr){
        cnt++;
        if(cnt == k - 1) {
            current->next = new Node(val, current->next);
            return head;
        }
        current = current->next;
    }

    return head;
}

Node* InsertBeforeValue(Node* head, int Element, int val) {
    if(head == nullptr) {
        return head;
    }
    if(head->data == Element) {
        return new Node(val, head);
    }
    Node* current = head;
    while(current->next != nullptr){
        if(current->next->data == Element) {
            current->next = new Node(val, current->next);
            return head;
        }
        current = current->next;
    }

    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArrayToLinkedList(arr);
    printLinkedList(head);
    cout << "Length of Linked List: " << lengthOfLinkedList(head) << endl;
    cout << "Is 3 present in Linked List? " << (checkIfPresent(head, 3) ? "Yes" : "No") << endl;
    cout << "Is 6 present in Linked List? " << (checkIfPresent(head, 6) ? "Yes" : "No") << endl;

    head = InsertAtHead(head, 0);
    printLinkedList(head);  
    head = InsertAtTail(head, 6);
    printLinkedList(head);
    head = InsertAtK(head, 3, 22);
    printLinkedList(head);  
    head = InsertBeforeValue(head, 22, 21);
    printLinkedList(head);

    cout<< "Deleting nodes..." << endl;

    head = deleteHead(head);
    printLinkedList(head);
    head = deleteLast(head);
    printLinkedList(head);
    head = deleteAtK(head, 3);
    printLinkedList(head);
    head = deleteAtValue(head, 21);
    printLinkedList(head);

}