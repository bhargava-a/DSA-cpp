#include<iostream>
using namespace std;
void change(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main(){
    int n;
    cout<<"Enter the array size : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    return 0;
}