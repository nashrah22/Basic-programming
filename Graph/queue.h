#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>
using namespace std;

class Node {
public:
 int data;
 Node *next;

 Node(int data){

 this->data = data;
 next = NULL;
}

 };

 class Queue {

 public:
    Node *head, *tail;

    Queue(){

     head = NULL;
     tail = NULL;
    }

//void insert_at_begin(int data)


void enqueue(int data){
Node *n = new Node(data);
Node *temp;

    if(head == NULL){
            head = n;
            tail = n;

    }
    else{
            temp=tail;
            temp->next = n;
            tail= temp->next;

        //tail = n-> next;

    }
}


void dequeue(){
Node *tmp;
tmp=head;
head= tmp->next;
delete tmp;


}


 };


#endif // QUEUE_H_INCLUDED
