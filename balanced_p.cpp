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
Node<T> *top;

stack_imp(){

top = NULL;
}
~stack_imp()
    {
        Node<T> *tmp = this->top;
        while(tmp != NULL)
        {
            Node<T> *next = tmp->next;
            delete tmp;
            tmp = next;
        }
    }

//Push function
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



// Pop function
void pop(){
Node<T> *tmp;
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



bool isEmpty()
    {
        return top==NULL;
    }

T Top()
    {
        if(isEmpty()) throw EmptyStackException();
        else return top->data;
    }


void display(){
Node<T> *tmp;
tmp = top;

while(tmp != NULL){
    cout << tmp->data<< endl;
    tmp= tmp->next;
}
}
};



int main(){

stack_imp<char> stk;
//stack_imp<char> *st;
string st;
int i;
bool bal_par = false;
cout<<"Input parentheses to check:\n" <<endl;
cin>> st;
stk.display();


for(i=0; i< st.length(); i++){

if(st[i] == '{' || st[i]=='(' || st[i]== '[')
    { stk.push(st[i]);
    break;
}
else if ((st[i] == ')' && stk.Top() == '(')|| (st[i] == '}' && stk.Top() == '{' )|| ( st[i] == ']' && stk.Top() == '['))
{ stk.pop();
break;

}
else {
        stk.push(st[i]);
        break;
}

}

if(stk.isEmpty())
    bal_par = true;
if( bal_par)
  {
      cout<<"\nBalanced parenthesis" <<endl;
  }
else cout<<"\nParenthesis are unbalanced"<<endl;


return 0;


}
