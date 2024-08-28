#include <bits/stdc++.h>
using namespace std;
int n;
void merge(int arr[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=ub;
    int b[n];
    while(i<=mid&&j<=ub){
        if(arr[i]<=arr[j]){
            b[k]=arr[i];
            i++;
        }else{
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k]=arr[j];
            j++;k++;
        }
    }else{
        while(i<=mid){
            b[k]=arr[i];
            i++;k++;
        }
    }
    for(int i=0;i<n;i++){
        arr[i]=b[i];
    }
}
void mergesort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

int main(){
    cout<<"Enter the array size : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    return 0;
}
