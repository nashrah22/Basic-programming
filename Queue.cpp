#include <iostream>
using namespace std;

template <class T>
 class Node {
     public:
 T data;
 Node *next;

 Node(T data){

 this->data = data;
 next = NULL;
}

 };

template <class T>
class Queue {

 public:
    Node<T> *head, *tail;

     Queue(){

     head = NULL;
     tail = NULL;
    }


void enqueue(T data){
Node<T> *n = new Node<T>(data);
//Node<T> *tmp;

//Insert at last

    if(head == NULL){
            head = n;
            tail = n;

    }
    else{
           // tmp=tail;
            tail->next = n;
            tail= n;

        //tail = n-> next;

    }
}

void dequeue(){
// Delete from first
Node<T> *tmp;

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

void display(){
Node<T> *tmp;
tmp = head;

while(tmp != NULL){
    cout << tmp->data<< endl;
    tmp= tmp->next;
}
}

 };

 int main(){

 //Node *n = new Node(5);
 Queue<char> q;

 q.enqueue('A');
 q.enqueue('B');
 //q.dequeue();
 //q.dequeue();
//q.dequeue();
q.display();


 //cout<< ob>data << endl;


 }
