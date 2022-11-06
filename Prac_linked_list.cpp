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

//void insert_at_begin(int data)
void insert_at_begin(int data){
Node *n = new Node(data);

    if(head == NULL){
            head = n;
            tail = n;

    }
    else{
        n ->next= head;
        head = n;
        //tail = n-> next;

    }
}



void insert_at_end(int data){
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

void insert_at_pos(int data, int pos){
Node *n = new Node(data);
  if(pos == 0){

insert_at_begin(n->data);
}
  else{
    Node *tmp = head;
    int i= 1;
    while(tmp != NULL){

        if(i == pos){
            n->next = tmp->next;
            tmp->next = n;
            break;

        }
        else if(tmp->next == NULL){
            cout<<"only one element"<< endl;
            break;
        }

        tmp=tmp->next;
        i++;
    }
}


}

void delete_at_begin(){
Node *tmp;
tmp=head;
head= tmp->next;
delete tmp;


}

void delete_at_end(){
Node *n ;
Node *temp;
n=head;
while(n != tail){
    temp=n;
    n=n->next;
}

tail= temp;
temp->next= NULL;
delete n;
}


void show(){
Node *tmp;
tmp = head;
 while (tmp != NULL){
    cout << tmp->data << endl;
    tmp=tmp->next;
 }}

 };

 int main(){

 Node *tmp;
 //Node *n = new Node(5);
 linked_list l;
 linked_list l1;


l.insert_at_begin(5);
 l.insert_at_begin(3);
 l.insert_at_begin(1);
 l.insert_at_pos(2,1);

 //l.insert_at_end(4);
 //l.insert_at_end(7);
 //l.delete_at_begin();
 //l.delete_at_end();


l.show();
 //cout<< ob>data << endl;


 }
