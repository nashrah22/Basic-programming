#include <iostream>
using namespace std;

class EmptyStackException
{
public:
    EmptyStackException()
    {
        cout << "Stack is empty" <<endl;
    }

};

template <class T>
class Node{
    public:
//int data;
T data;
Node *next;

Node(T data){
this->data = data;
next = NULL;
}

};

template <class T>
class stack_imp {

public:
Node<T> *top,*tmp;

stack_imp(){

top = NULL;
}
void push(T data){
Node<T> *n = new Node<T>(data) ;

if(top == NULL){
    top = n;
}

else{
        n->next = top;
        top = n;
}
}

void pop(){
if(top == NULL){
    cout<< "stack is empty"<<endl;
}
else {
    tmp=top;
    top = tmp->next;
    delete tmp;
    //if(top== NULL){cout<<"last element deleted, stack is empty"<<endl;}
}

}


bool isEmpty(){

return top == NULL;
}

T top(){
if(isEmpty()) throw EmptyStackException();
    else return top->data;

}


void display(){
tmp = top;

while(tmp != NULL){
    cout << tmp->data<< endl;
    tmp= tmp->next;
}



}



};





int main(){
//Node *tmp;
stack_imp<char> stk;
stk.push('C');
stk.push('B');
stk.push('A');
stk.pop();
//stk.pop();
//stk.pop();
//stk.pop();

stk.display();


//stack_imp<int> s;
//s.push(5);
//s.push(2);
//s.push(1);
//s.pop();

//s.display();




//cout <<"frferf"<<endl;
}
