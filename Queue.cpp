#include "Queue.h"
#include <stdlib.h>

Queue::Queue(){
    this->size = 0;
    this->head = NULL;
    this->tail = NULL;
}

// Destructor
Queue::~Queue(){
    while(!isEmpty()){
        dequeue();
    }

    while(this->head){ //Sets node to head, moves head to next node then deletes head pointer 
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

// Add element to tail
void Queue::enqueue(int ref){
    Node* n = new Node();
    n->key = ref;
    if(isEmpty()) this->head = this->tail = n;
    else{
        this->tail->next = n;
        this->tail = n;
    }
    ++(this->size);
}

// Remove element from head
int Queue::dequeue(){
    int ref;
    if(isEmpty()) ref = -1;
    else{
        Node* refN = this->head;
        ref = this->head->key;
        this->head = this->head->next;
        if(!this->head) this->tail = NULL;
        delete refN;
    }
    --(this->size);
    return ref;
}

/* Getter Methods */
int Queue::getHead(){
    return this->head->key; 
}

int Queue::getTail(){
    return this->tail->key;
}

//Returns if Queue is empty
bool Queue::isEmpty(){
    return 0 == this->size;
}
