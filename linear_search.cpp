#include <iostream>
using namespace std;
 #define size 100

 class Unsorted_array{
 private:
    int arr[size],n,item;
    //int loc=0;

    public:

    int insert_ele();
    int lin_search();

 };
 int Unsorted_array:: insert_ele(){

 //int i,n,item,data[100];
    cout<<"enter no elements:"<<endl;
    cin>>n;
    cout<<"enter elements:"<<endl;
    for(int i = 0; i<n; i++)
     {
     cin>>arr[i];

 }}

int Unsorted_array:: lin_search()
{cout<<"enter item to search :"<<endl;
    cin>>item;

for(int i = 0; i<n; i++)
     {
     if(arr[i] == item)
    return i;
    }
return -1;
}


//
//int lin_search(int data[],int n, int item)
//{ //cout<<"enter item:"<<endl;
    //cin>>item;

//for(int i = 0; i<n; i++)
     //{
     //if(data[i] == item)
    // return i;
    // }
//return -1;
//}


int main(){
    int y;

    Unsorted_array x;
    x.insert_ele();
    y= x.lin_search();
    cout<<"item found in array pos :"<< y<<endl;


}
