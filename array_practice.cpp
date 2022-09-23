#include <iostream>
using namespace std;
int main(){

int i,n,a1[10];
cout<<"Number of elements:"<<endl;
cin>> n;

cout<<"Enter array elements:"<<endl;
for(i=0; i<n; i++){
    cin>> a1[i];

}
cout <<"The array elements are:" << endl;
for(i=0; i<n; i++){
cout << a1[i] <<endl;
}
cout<< "Printing the elements in reverse order: "<<endl;

for(i=(n-1); i>=0; i--){
cout << a1[i] <<endl;
}
}
