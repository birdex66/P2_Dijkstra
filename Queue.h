#ifndef QUEUE_H
#define QUEUE_H

struct Node{
    int key;
    Node* next;
};

class Queue{
    private:
        int size;
        Node* head;
        Node* tail;
    public:
        Queue();
        ~Queue();
        void enqueue(int);
        int dequeue();
        int getHead();
        int getTail();
        bool isEmpty();
};


#endif

