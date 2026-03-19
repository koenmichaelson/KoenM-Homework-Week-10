#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

// All coding should be done on the header

#ifndef TESTING
int main(){
    //Queue starts empty
    Queue queue;
    queue.print();

    //Queue with one node
    queue.enqueue("Apple");
    cout << queue.size() << " item(s): ";
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