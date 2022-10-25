#include <iostream>
using namespace std;

template <class Type>
class Node{
    public:
//int data;
Type data;
Node *next;

Node(Type data){
this->data = data;
next = NULL;
}

};

template <class Type>
class stack_imp {

public:
Node<Type> *top;

stack_imp(){

top = NULL;
}
~stack_imp()
    {
        Node<Type> *tmp = top;
        while(tmp != NULL)
        {
            Node<Type> *next = tmp->next;
            delete tmp;
            tmp = next;
        }
    }



void Push(Type data){
Node<Type> *node = new Node<Type>(data) ;

if(top == NULL){
    top = node;
}

else{
        node->next = top;
        top = node;
}
}

void Pop(){
Node<Type> *tmp;
if(top == NULL){
    cout<< "Stack is empty"<<endl;
}
else {
    tmp=top;
    top = tmp->next;
    delete tmp;
    //if(top== NULL){cout<<"last element deleted, stack is empty"<<endl;}
}

}


bool is_Empty(){

return top == NULL;
}

//T Top(){
//if(isEmpty()) throw EmptyStackException();
 //   else return top->data;

//}


void show(){
Node<Type> *tmp;
tmp = top;

while(tmp != NULL){
    cout << tmp->data<< endl;
    tmp= tmp->next;
}
}
};

int main(){

stack_imp<char> stk;
stk.Push('C');
stk.Push('B');
stk.Push('A');
//stk.pop();
//stk.pop();


stk.show();


}
