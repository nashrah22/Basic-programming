#include<iostream>
using namespace std;
int main(){
int n, i,j,val,pos,arr[100];
// Insertion of element in any desired position

cout <<"Enter no. of elements:"<<endl;
cin>>n;
cout<<"\nEnter array elements:"<<endl;
for(i=0;i<n;i++){
    cin>>arr[i];
}
cout<<"\nPrint array:"<<endl;
for(i=0;i<n;i++){
cout<<"arr["<<i<<"]="<<arr[i]<<endl;
}
cout<< "\nEnter position and value:"<<endl;
cin>>pos>>val;

for(i=n-1;i>=pos-1;i--){
    arr[i+1]=arr[i];

}
arr[pos-1]=val;

//After inserting new value
cout<<"\nPrint array:"<<endl;
for(i=0;i<=n;i++){
    cout<<"arr["<<i<<"]="<<arr[i]<<endl;
}
}
