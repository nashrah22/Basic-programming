#include<iostream>
using namespace std;

class Fact{
public:
int fact(int n){
if(n==0){
    return 1;
}
else
    return n*fact(n-1);
}
};
int main(){
int n,factorial;
Fact ob;
factorial=ob.fact(7);
//cout<<"enter number to calculate factorial:"<<endl;
//cin>>n;
//factorial = fact(n);
cout<<"\nFactorial is: " <<factorial<<endl;


}
