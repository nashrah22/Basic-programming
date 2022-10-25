#include <iostream>
using namespace std;

template <class Type>
class Node{
    public:
//int data;
Type data;
Node *next;

Node(Type data){
data = data;
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
        Node<Type> *tmp = this->top;
        while(tmp != NULL)
        {
            Node<Type> *next = tmp->next;
            delete tmp;
            tmp = next;
        }
    }

//Push function
void push(Type data){
Node<Type> *n = new Node<Type>(data) ;

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



bool is_Empty()
    {
        return top==NULL;
    }

//T Top()
  //  {
    //    if(is_Empty()) cout<< "stack is empty"<<endl;
      // else
        //    return top->data;
    //}


void display(){
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
//stack_imp<char> *st;
string st;
bool flag = false;
cout<<"Input parentheses to check:\n" <<endl;
cin>> st;
//stk.display();


for(int i=0; i< st.length(); i++){

if(st[i] == '(' || st[i]=='{' || st[i]== '[')
    { stk.push(st[i]);

}else if(stk.top == NULL){
stk.push(st[i]);
}

 else if ((st[i] == ')' && stk.top->data == '(')|| (st[i] == '}' &&  stk.top->data == '{' )|| ( st[i] == ']' &&  stk.top->data  == '['))
//else if ((st[i] == ')' && stk.Top() == '(')|| (st[i] == '}' && stk.Top() == '{' )|| ( st[i] == ']' && stk.Top() == '['))
{stk.pop();
}

else {
        stk.push(st[i]);

}
}
cout<<endl;
cout<<"Display stack:"<<endl;

stk.display();

if(stk.is_Empty())
    flag = true;
if(flag)
  {
      cout<<"\nBalanced parentheses" <<endl;
  }
else cout<<"\nParentheses are unbalanced"<<endl;


return 0;


}
