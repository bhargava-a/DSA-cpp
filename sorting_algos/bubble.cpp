#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
using namespace std;
int main()
{               
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int a[n];
    cout<<"Enter the array elements : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int counter =1;
    while(counter<n){
        for(int i=0;i<n-counter;i++){
            if(a[i]>a[i+1]){
                int temp =a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }counter++;
    }
    for(int j=0;j<n;j++){
    cout<<"\t"<<a[j];
    }
    return 0;
}