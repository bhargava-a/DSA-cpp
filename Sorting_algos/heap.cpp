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

        void MaxHeapify(vector<int> arr,int n,int index){
            int largest = index;
            int left=2*index;
            int right=2*index+1;

            while(left<=n && arr[left]>arr[largest]){
                largest=left;
            }
            while(right<=n && arr[right]>arr[largest]){
                largest=right;
            }
            if(largest!=index){
                change(&arr[largest],&arr[index]);
                MaxHeapify(arr,n,largest);
            }
        }
    
    public:
        void HeapSort(vector<int> arr,int n,int index){
            for(int i=n/2;i>=1;i--){
                MaxHeapify(arr,n,i);
            }
            for(int i=n;i>=1;i--){
                change(&arr[i],&arr[index]);
                MaxHeapify(arr,n,1);
            }
        }
};
int main(){
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    vector<int> arr[n];
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i].push_back(x);
    }
    Heap h;
    h.HeapSort(arr,n,(n/2)+1);
    return 0;
}