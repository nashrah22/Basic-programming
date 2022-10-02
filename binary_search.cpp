#include <iostream>
using namespace std;
 #define size 100

// class bin_search{
 //private:
   // int n,first,middle,last,item;
    //int loc=0;
    //int arr[13]={10,12,15,20,21,25,29,33,35,38,42,46,50};

   // public:
//int insert_ele();
   // int binary_search();

// };

int binary_search(int arr[], int first, int last, int item)
{
    if (last>= first) {
        int middle = first + (last - first) / 2;


        if (arr[middle] == item)
            return middle;

        if (arr[middle] > item)
            return binary_search(arr, first, middle - 1, item);


        return binary_search(arr, middle + 1, last, item);
    }


    return -1;
}

int main(){
int n,y,first,middle,last,item,x;
int arr[13]={10,12,15,20,21,25,29,33,35,38,42,46,50};
n=sizeof(arr)/sizeof(arr[0]);
cout<<"enter item to search :"<<endl;
cin>>item;
y= binary_search(arr, 0, n-1,item);
if (y == -1)
    cout<<"Not found"<<endl;
  else
    cout<<"item found in array pos :"<< y<<endl;


}
