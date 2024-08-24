#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
using namespace std;
void change(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{               
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                change(&arr[j],&arr[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}