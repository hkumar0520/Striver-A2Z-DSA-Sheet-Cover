
#include <bits/stdc++.h>
using namespace std;

class StackUsingArray {
    private:
        int top = -1;
        int arr[10];
    public:

    void push(int x) {
        if (top + 1 >= 10) {
            cout << "Stack overflow" << endl;
        }
        top += 1;
        arr[top] = x;
    }

    int topElement(){
        if(top == -1) {
            cout << "Stack is empty" << endl;
            return -1; // or throw an exception
        }

        return arr[top];
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        top -= 1;
    }
    int size() {
        return top + 1;
    }

    bool isEmpty() {
        return top == -1;
    }
    // O(1) time complexity for all operations

};


class QueueUsingArray {
    private: 
        int front = -1;
        int rear = -1;
        int currSize = 0;
        int size = 10;
        int arr[10];
    public:
        void enqueue(int x) {
            if( currSize >= size) {
                cout << "Queue overflow" << endl;
                return;
            }
            if (currSize == 0) {
                front = 0;
                rear = 0;
            }
            else {
                rear = (rear + 1) % size; // Circular increment
            } 
            arr[rear] = x;
            currSize++;
        }
        int dequeue() {
            if (currSize == 0) {
                cout << "Queue underflow" << endl;
                return -1; // or throw an exception
            }
            int x = arr[front];
            if(currSize == 1) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % size; // Circular increment
            }
            currSize--;
            return x;
        }
        int  frontElement() {
            if (currSize == 0) {
                cout << "Queue is empty" << endl;
                return -1; // or throw an exception
            }
            return arr[front];
        }
        int sizeOfQueue() {
            return currSize;
        }
        
        bool isEmpty() {
        return currSize == 0;
        }

        // O(1) time complexity for enqueue, dequeue, frontElement and sizeOfQueue operations
};

class StackUsingLinkedList {
    private:
        struct Node {
            int data;
            Node* next;
        };

        Node *top = nullptr;
        int size = 0;
    public:
        void push(int x) {
            Node* newNode = new Node();
            newNode->data = x;
            newNode->next = top;
            top = newNode;
            size++;
        }

        void pop(){
            if (top == nullptr) {
                cout << "Stack underflow" << endl;
                return;
            }
            Node* temp = top;
            top = top->next;
            size--;
            delete temp;                        
        }
        int topElement() {
            if (top == nullptr) {
                cout << "Stack is empty" << endl;
                return -1; // or throw an exception
            }
            return top->data;
        }
        int getSize() {
            return size;
        }

        bool isEmpty() {
            return top == nullptr;
        }

        // O(1) time complexity for push, pop, topElement and getSize operations
};

class QueueUsingLinkedList {
    private:
        struct Node {
            int data;
            Node* next;
        };

        Node *front = nullptr;
        Node *rear = nullptr;
        int size = 0;
    public:
        void enqueue(int x) {
            Node* newNode = new Node();
            newNode->data = x;
            newNode->next = nullptr;

            if (rear == nullptr) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }

        int dequeue() {
            if (front == nullptr) {
                cout << "Queue underflow" << endl;
                return -1; // or throw an exception
            }
            int x = front->data;
            Node* temp = front;
            front = front->next;

            if (front == nullptr) {
                rear = nullptr; // If the queue is now empty
            }
            delete temp;
            size--;
            return x;
        }

        int frontElement() {
            if (front == nullptr) {
                cout << "Queue is empty" << endl;
                return -1; // or throw an exception
            }
            return front->data;
        }

        int sizeOfQueue() {
            return size;
        }

        bool isEmpty() {
            return front == nullptr;
        }

        // O(1) time complexity for enqueue, dequeue, frontElement and sizeOfQueue operations
};

int main(){
    cout<< "---------------Stack using array---------------------" << endl;
    StackUsingArray stackUsingArray;
    stackUsingArray.push(10);
    stackUsingArray.push(20);
    stackUsingArray.push(30);
    cout << "Top element: " << stackUsingArray.topElement() << endl; // Should print 30
    cout << "Stack size: " << stackUsingArray.size() << endl; // Should print 3
    stackUsingArray.pop();
    cout << "Top element after pop: " << stackUsingArray.topElement() << endl; // Should print 20
    cout << "Stack size after pop: " << stackUsingArray.size() << endl; // Should print 2   

    cout<< "---------------Qeueu using array---------------------" << endl;

    QueueUsingArray queueUsingArray;
    queueUsingArray.enqueue(10);
    queueUsingArray.enqueue(20);
    queueUsingArray.enqueue(30);
    cout << "Front element: " << queueUsingArray.frontElement() << endl; // Should print 10 
    cout << "Queue size: " << queueUsingArray.sizeOfQueue() << endl; // Should print 3
    cout << "Dequeue element: " << queueUsingArray.dequeue() << endl; // Should print 10
    cout << "Front element after dequeue: " << queueUsingArray.frontElement() << endl; // Should print 20
    cout << "Queue size after dequeue: " << queueUsingArray.sizeOfQueue() << endl; // Should print 2
    queueUsingArray.enqueue(40);
    cout << "Front element after enqueue: " << queueUsingArray.frontElement() << endl; // Should print 20
    cout << "Queue size after enqueue: " << queueUsingArray.sizeOfQueue() << endl; // Should print 3
    cout << "Dequeue element: " << queueUsingArray.dequeue() << endl; // Should print 20


    cout<< "---------------Stack using Linked List---------------------" << endl;
    StackUsingLinkedList stackUsingLinkedList;
    stackUsingLinkedList.push(10);
    stackUsingLinkedList.push(20);
    stackUsingLinkedList.push(30);
    cout << "Top element: " << stackUsingLinkedList.topElement() << endl; // Should print 30
    cout << "Stack size: " << stackUsingLinkedList.getSize() << endl; // Should print 3
    stackUsingLinkedList.pop();
    cout << "Top element after pop: " << stackUsingLinkedList.topElement() << endl; // Should print 20
    cout << "Stack size after pop: " << stackUsingLinkedList.getSize() << endl; // Should print 2   

cout<< "---------------Qeueu using LinkedList---------------------" << endl;

    QueueUsingLinkedList queueUsingLinkedList;
    queueUsingLinkedList.enqueue(10);
    queueUsingLinkedList.enqueue(20);
    queueUsingLinkedList.enqueue(30);
    cout << "Front element: " << queueUsingLinkedList.frontElement() << endl; // Should print 10 
    cout << "Queue size: " << queueUsingLinkedList.sizeOfQueue() << endl; // Should print 3
    cout << "Dequeue element: " << queueUsingLinkedList.dequeue() << endl; // Should print 10
    cout << "Front element after dequeue: " << queueUsingLinkedList.frontElement() << endl; // Should print 20
    cout << "Queue size after dequeue: " << queueUsingLinkedList.sizeOfQueue() << endl; // Should print 2
    queueUsingLinkedList.enqueue(40);
    cout << "Front element after enqueue: " << queueUsingLinkedList.frontElement() << endl; // Should print 20
    cout << "Queue size after enqueue: " << queueUsingLinkedList.sizeOfQueue() << endl; // Should print 3
    cout << "Dequeue element: " << queueUsingLinkedList.dequeue() << endl; // Should print 20


    return 0;
}