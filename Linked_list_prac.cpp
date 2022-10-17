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

 class linked_list {

 public:
    Node *head, *tail;

    linked_list(){

     head = NULL;
     tail = NULL;
    }


void insert_at_begin(Node *n){

    if(head == NULL){
            head = n;
            tail = n;

    }
    else{
        n ->next= head;
        head = n;
        tail = n-> next;

    }
}
 };
 int main(){

 Node *n = new Node(5);
 linked_list ob;
 ob.insert_at_begin(n);
 //n-> data= 5;

 cout<< n->data << endl;


 }
