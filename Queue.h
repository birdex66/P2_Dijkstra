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
        void enqueue(int); // Add element to tail
        int dequeue(); //Remove element from head
        
        //Getter Methods
        int getHead(); 
        int getTail();

        bool isEmpty(); //Return if queue empty
};


#endif

