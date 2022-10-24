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
~stack_imp()
    {
        Node<T> *temp = this->top;
        while(temp != NULL)
        {
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }
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



bool isEmpty()
    {
        return this->top==NULL;
    }
    T Top()
    {
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
//Node *top;
//stack_imp ob;
stack_imp<char> stk;
stack_imp<char> *st;
string s;
bool ans= false;
cout<<"Input parentheses to check:" <<endl;
cin>> s;
stk.display();
int i;

for(i=0; i< s.length(); i++){

if(s[i] == '{' or s[i]=='(' or s[i]== '[')
    { stk.push(s[i]);
}
else if ((s[i] == ')' && stk.Top() == '(')
                 || (s[i] == '}' && stk.Top() == '{' )
                 || ( s[i] == ']') && stk.Top() == '[')
{ stk.pop();

}
}

if(stk.isEmpty())
    ans= true;
if(ans)
  {
      cout<<"balanced parenthesis" <<endl;
  }
else cout<<"unbalanced"<<endl;


return 0;


}
