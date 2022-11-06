#include <iostream>
using namespace std;

int binary_search(int arr[], int item, int first,int last){
if(first>last){
    return false;
}
else {
    int mid;
    mid = (first+last)/2;
    if(item<arr[mid]){
        return binary_search(arr,item,first,mid-1);
    }else if(item ==  arr[mid])
    return mid;
    else
        return binary_search(arr,item,mid+1,last);
}


}

int main(){
int item;
int arr[]={23,11,56,0,20,57,43,25,7,3};
cin>>item;

cout<<"item "<<item<<" found at pos: "<<binary_search(arr,item,0,9)<<endl;
}
