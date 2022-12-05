#include "Queue.h"


template<class T>
Queue<T>::Queue(int max)
{
    head = nullptr;
    tail = nullptr;
    this->max = max;
    numElems = 0;
}

template<class T>
Queue<T>::Queue()
{
    head = nullptr;
    tail = nullptr;
}

template<class T>
Queue<T>::~Queue()
{
    Node* currNode = head;
    while(currNode != nullptr){
        Node* temp = currNode;
        currNode = currNode->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

template<class T>
void Queue<T>::MakeEmpty()
{
    Node* currNode = head;
    while(currNode != nullptr){
        Node* temp = currNode;
        currNode = currNode->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

template<class T>
bool Queue<T>::IsEmpty() const
{
    if(head == nullptr){
        return true;
    }
    return false;
}

template<class T>
bool Queue<T>::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    if(numElems>=max){
        return true;
    }
    return false;
}

template<class T>
void Queue<T>::Enqueue(T newItem)
{
    // Function: Adds newItem to the rear of the queue.
    // Post: If (queue is full) FullQueue exception is thrown
    //       else newItem is at rear of queue.
    //Beg, empty, end, mid
    if(IsFull()){
        throw "Full Queue";
    }
    //create and initialize newnode
    Node* newNode = new Node;
    newNode->value = newItem;
    newNode->next = nullptr;
    numElems++;

    if(head == nullptr){//if there is no queue
        head == newNode;
        tail == newNode;
        return;
    } else{
        tail->next = newNode;
        tail = newNode;
    }
}

template<class T>
T Queue<T>::Dequeue()
{
    if(IsEmpty()){
        throw "Empty Queue";
    }
    T returnVal = head->value;
    Node* temp = head;
    head = head->next;
    delete temp;
    return returnVal;
}
