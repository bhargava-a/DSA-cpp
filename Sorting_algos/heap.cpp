#include<iostream>
#include<vector>
using namespace std;
class Heap{
    private:
        void change(int *x,int *y){
            int temp=*x;
            *x=*y;
            *y=temp;
        }
         // Function to maintain the max heap property
        void MaxHeapify(vector<int> &arr,int n,int index){
            int largest = index;
            int left=2*index+1;
            int right=2*index+2;

            while(left<n && arr[left]>arr[largest]){
                largest=left;
            }
            while(right<n && arr[right]>arr[largest]){
                largest=right;
            }
            if(largest!=index){
                change(&arr[largest],&arr[index]);
                MaxHeapify(arr,n,largest);
            }
        }
    
    public:
        void HeapSort(vector<int> &arr){
            int n=arr.size();
            for(int i=(n/2)-1;i>=0;i--){
                MaxHeapify(arr,n,i);
            }
            for(int i=n-1;i>0;i--){
                change(&arr[0],&arr[i]);
                MaxHeapify(arr,i,0);
            }
        }

        void display(vector<int> &arr){
            for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<"\t";
            }
        }
};
int main(){
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Heap h;
    h.HeapSort(arr);
    h.display(arr);
    return 0;
}