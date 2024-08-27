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
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while (j>=0&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    cout<<"Sorted array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}