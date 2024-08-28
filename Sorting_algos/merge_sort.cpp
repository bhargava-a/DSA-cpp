#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=ub;
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
