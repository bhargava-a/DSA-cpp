#include<iostream>
using namespace std;

int partition(int arr[],int lowerbound,int upperbound){
    int pivot=arr[lowerbound];
    int start=lowerbound;
    int end=upperbound;
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            int temp=arr[end];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    int temp=arr[lowerbound];
    arr[lowerbound]=arr[end];
    arr[end]=temp;
    return end;
}
void Quicksort(int arr[],int lowerbound,int upperbound){
    if(lowerbound<upperbound){
        int loc=partition(arr,lowerbound,upperbound);
        Quicksort(arr,lowerbound,loc-1);
        Quicksort(arr,loc+1,upperbound);
    }
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    Quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    
    return 0;
}
