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
  class queue_imp {

 public:
    Node *head, *tail;

     queue_imp(){

     head = NULL;
     tail = NULL;
    }


void enqueue(int data){
Node *n = new Node(data);
Node *temp;

//insert at last

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
// delete from first
Node *tmp;

if(head == NULL){

    cout<<"queue is empty "<< endl;

}
//else if(head->next == NULL){
   // tmp=head;
    //head= NULL;
    //delete tmp;
//cout << "Now queue is empty, last element deleted"<<endl;
//}
else{
    tmp = head;
    head = tmp->next;
    delete tmp;
}


}

 };

 int main(){

 Node *tmp;
 //Node *n = new Node(5);
 queue_imp q;

 q.enqueue(4);
 q.enqueue(5);
 q.dequeue();
 //q.dequeue();


 tmp = q.head;
 while (tmp != NULL){
    cout << tmp->data << endl;
    tmp=tmp->next;
 }

 //cout<< ob>data << endl;


 }

