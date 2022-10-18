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

 class stack_imp {

 public:
    Node *top, *tail;

    stack_imp(){

     top = NULL;
   //  tail = NULL;
    }

//void insert_at_begin(int data)
void Push_stk(int data){
Node *n = new Node(data);
Node *tmp;

    if(top == NULL){
            top = n;
            //tail = n;

    }
    else{
        tmp = top;
        n->next = tmp;
        top = n;
        //n ->next= top;
       // top= n;
        //tail = n-> next;

    }
}

void Pop_stk(){
Node *tmp;
//tmp=top;

if(top == NULL){

    cout<<"stack is empty "<< endl;

}
else if(top->next == NULL){
    tmp=top;
    top= NULL;
    delete tmp;
cout << "Now stack is empty, last element deleted"<<endl;
}
else{
    tmp = top;
    top = tmp->next;
    delete tmp;
}

}
 };

 int main(){

 Node *tmp;
 //Node *n = new Node(5);
 stack_imp  ob;
 //linked_list l1;

//ob.insert_at_begin(new Node(6));
//ob.insert_at_begin(new Node(5));
//ob.insert_at_begin(new Node(2));

ob.Push_stk(5);
ob.Push_stk(3);
ob.Push_stk(1);
ob.Pop_stk();
ob.Pop_stk();
ob.Pop_stk();
ob.Pop_stk();

 //l.insert_at_end(4);
 //l.insert_at_end(7);
 //l.delete_at_begin();
 //ob.Pop_stk();


 tmp = ob.top;
 while (tmp != NULL){
    cout << tmp->data << endl;
    tmp=tmp->next;
 }

 //cout<< ob>data << endl;


 }


