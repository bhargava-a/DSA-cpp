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
    
    
};
int main(){
    
    return 0;
}