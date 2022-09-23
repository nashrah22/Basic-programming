#include <iostream>
using namespace std;
int main(){
int i,j,m,n,a1[5][5];
cout<<"Input array dimension:"<<endl;
cin >> m >> n;

cout<<"Input array elements: "<<endl;
for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        cin>> a1[i][j];
    }
}
cout<<"\nPrint array: "<<endl;

for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        cout<<"a1["<<i<<"]["<<j <<"]= "<<a1[i][j]<<endl;
    }
}

}
