#include "Queue.h"
#include <stdlib.h>

Queue::Queue(){
    this->size = 0;
    this->head = NULL;
    this->tail = NULL;
}

Queue::~Queue(){
    Node* temp;
    while(this->head){
        temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

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
int Queue::dequeue(){
    int ref;
    if(isEmpty()) ref = -1;
    else{
        ref = this->head->key;
        this->head = this->head->next;
        if(!this->head) this->tail = NULL;
    }
    --(this->size);
    return ref
}
int Queue::getHead(){
    return this->head->key; 
}

int Queue::getTail(){
    return this->tail->key;
}
bool Queue::isEmpty(){
    return 0 == this->size;
}
