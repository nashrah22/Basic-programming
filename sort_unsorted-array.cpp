#include <iostream>
using namespace std;

int main(){
//unsorted array
// Insertion of element in any desired position

int n, i,j,temp,val,pos,arr[100];
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

//Sort array:

for(j=0;j<n-2;j++){
    for(i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        } //else cout<<"sorted array"<<endl;
    }
}

cout<<"\nPrint sorted array:"<<endl;
for(i=0;i<n;i++){
cout<<"arr["<<i<<"]="<<arr[i]<<endl;
}

}
