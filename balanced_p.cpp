#include <iostream>
using namespace std;

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
//stk.display();


for(i=0; i< st.length(); i++){

if(st[i] == '(' || st[i]=='{' || st[i]== '[')
    { stk.push(st[i]);
    //break;
}else if(stk.top== NULL){
stk.push(st[i]);
}

 else if ((st[i] == ')' && stk.top->data == '(')|| (st[i] == '}' &&  stk.top->data == '{' )|| ( st[i] == ']' &&  stk.top->data  == '['))
//else if ((st[i] == ')' && stk.Top() == '(')|| (st[i] == '}' && stk.Top() == '{' )|| ( st[i] == ']' && stk.Top() == '['))
{stk.pop();
}

else {
        stk.push(st[i]);
        //break;
}
}
cout<<endl;
//cout<<"Show stack:"<<endl;
//stk.display();
//} catch (EmptyStackException){
  //    stk.push(st[i]);}

if(stk.is_Empty())
    bal_par = true;
if( bal_par)
  {
     // cout<<"Stack is empty"<<endl;
      cout<<"\nBalanced parentheses" <<endl;
  }
else {
    cout<<"Show stack: "<<endl;
    stk.display();
    cout<<"\nParentheses are unbalanced"<<endl;
}

return 0;


}
