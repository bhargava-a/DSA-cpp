//NKN BINARY SEARCH 
#include<iostream>
using namespace std;
int main()
{
    int n,mid,key,low,high,test=1;
    cout<<"Enter the size of array : ";cin>>n;
    int a[n];
    cout<<"Enter the array elements : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the search element : ";cin>>key;
    low=0;high=n;
    bool found=false;
    while(low<=high){
        mid=(low+high)/2;
        if(key==a[mid]){
            cout<<"The search element found at location a["<<mid<<"]";
            found=true;
            break;
        }
        else if(key>a[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(!found){
        cout<<"The search element not found!!!";
    }
  
    return 0;
}