
#include <bits/stdc++.h>
using  namespace std;


class Node {
    public:
    int data;
    Node* next;
    Node* back;
    Node(int val) {
        data = val;
        next = nullptr;
        back = nullptr;
    }
    Node(int val, Node* nextNode, Node* backNode) {
        data = val;
        next = nextNode;
        back = backNode;
    }
};

void printDLL(Node* head) {
    Node* current = head;
    while(current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    return ;
}

Node* convertArr2DLL(vector<int>& arr) {
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        prev->next = newNode;
        prev->next->back = prev;
        prev = prev->next;
    }
    // for(int i = 1; i<arr.size(); i++) {
    //     Node* newNode = new Node(arr[i], nullptr, prev);
    //     prev->next = newNode;
    //     prev = newNode;
    // }
    return head;
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
    if(head->next == nullptr) {
        delete head;
        return nullptr; // If it was the only node
    }
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;
    delete prev;

    return head;
}


Node* deleteTail(Node* head) {
    if(head == nullptr) return nullptr;
    if(head->next == nullptr) {
        delete head;
        return nullptr; // If it was the only node
    }
    Node *tail = head;
    while(tail->next != nullptr) {
        tail = tail -> next;
    }

    Node* newTail = tail->back;
    
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    
    return head;
}

Node* deleteNodeAtK(Node* head, int k) {
    if(head == nullptr || k <= 0) return head;
    int cnt = 0;
    Node* current = head;
    while(current != nullptr){
        cnt++;
        if(cnt == k) break;
        current = current->next;
    }

    // out of bounds)   
    if(current == nullptr) return head;

    Node* prev = current->back;
    Node* front = current->next;

    if(prev == nullptr && front == nullptr) {
        delete current;
        return nullptr;
    }
    else if(prev == nullptr) 
        return deleteHead(head);
    else if(front == nullptr)
        return deleteTail(head);
    
    prev->next = front;
    front->back = prev;

    current->next = nullptr;
    current->back = nullptr;
    delete current;
    
    return head;
}

Node* deleteNodeWithValue(Node* head, int value) {
    if(head == nullptr) return head;
    if(head->data == value) {
        return deleteHead(head);
    }

    Node* current = head;
    while(current != nullptr) {
        if(current->data == value) break;
        current = current->next;
    }

    if(current == nullptr) {
        return head; // Value not found
    }

    Node* prev = current->back;
    Node* front = current->next;

    if(prev == nullptr && front == nullptr) {
        delete current;
        return nullptr; // Only one node
    }
    else if(prev == nullptr) 
        return deleteHead(head);
    else if(front == nullptr)
        return deleteTail(head);

    
    prev->next = front;
    front->back = prev;

    current->next = nullptr;
    current->back = nullptr;
    delete current;
    
    return head;
}

void deleteNode(Node* node){
    if(node == nullptr) return; 
    Node* prev = node->back;
    Node* front = node->next;

    if(prev != nullptr) {
        prev->next = front;
    }

    if(front != nullptr) {
        front->back = prev;
    }

    node->next = nullptr;
    node->back = nullptr;
    delete node;
    return; 
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2DLL(arr);
    printDLL(head);
    head = deleteHead(head);
    printDLL(head);
    head = deleteTail(head);
    printDLL(head);


    cout << endl;
}