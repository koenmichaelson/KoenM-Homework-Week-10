#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

// All coding should be done on the header

struct Node {
public:
    string data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* back;
    int count;

public:
    Queue() {
        count = 0;
        front = nullptr;
        back = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(string data) {
        Node* node = new Node;
        node->data = data;
        node->next = nullptr;

        if (isEmpty()) {
            front = node;
            back = node;
        }
        else {
            back->next = node;
            back = node;
        }
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
        count--;

        if (front == nullptr) {
            back = nullptr;
        }
    }

    string peek() {
        if (!isEmpty()) {
            return front->data;
        }
        else {
            return "";
        }
    }

    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    void print() {
        if (isEmpty()) {
            cout << "List is Empty!\n";
        }
        else {

            cout << endl;

            Node* temp = front;

            while (temp != nullptr) {
                cout << temp->data << ", ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};


#ifndef TESTING
int main(){
    //Queue starts empty
    Queue queue;
    queue.print();


    //Queue with one node
    queue.enqueue("Apple");
    cout << queue.size() << " item(s):";
    queue.print();

    //Removing one node; queue becomes empty
    queue.dequeue();
    queue.print();

    //Trying to dequeue from empty (no crash)
    queue.dequeue();

    //Trying to peek empty queue (no crash)
    cout << queue.peek();

    //Adding three nodes
    queue.enqueue("Banana");
    queue.enqueue("Cherry");
    queue.enqueue("Date");
    cout << queue.size() << " item(s): ";
    queue.print();

    //Removing one node
    queue.dequeue();
    cout << queue.size() << " item(s): ";
    queue.print();

    //Adding one additional node
    queue.enqueue("Elderberry");
    cout << queue.size() << " item(s): ";
    queue.print();

    //Peeking first node
    cout << "Peek: " << queue.peek() << endl;

    return 0;
}
#endif