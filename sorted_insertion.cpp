#include <iostream>
using namespace std;

int main(){
//unsorted array
// Insertion of element in any desired position

int n, i,j,key,val,pos,arr[100];
cout <<"Enter no. of elements:"<<endl;
cin>>n;
cout<<"\nEnter array elements:"<<endl;
for(i=0;i<n;i++){
    cin>>arr[i];

}


    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    cout<<"\nPrint array:"<<endl;
for(i=0;i<n;i++){
cout<<"arr["<<i<<"]="<<arr[i]<<endl;
}
}


