#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
    private:
        vector<int> array;

        void swapi(int *x,int *y){
            int temp=*x;
            *x=*y;
            *y=temp;
        }

        void heapify(int index){
            if(index==0){
                return;
            }
            int parent=(index-1)/2;
            if(array[index]>array[parent]){
                swapi(&array[index],&array[parent]);
                heapify(parent);
            }
        }

        void heapify_Down(int index){
            int left=2*index+1;
            int right=2*index+2;
            int largest=index;

            if(left<array.size() && array[left]>array[largest]){
                largest=left;
            }
            if(right<array.size() && array[right]>array[largest]){
                largest=right;
            }

            if(largest!=index){
                swapi(&array[largest],&array[index]);
                heapify_Down(largest);
            }
        }
    public:
        //insert an element into heap
        void insert(int data){
            array.push_back(data);
            heapify(array.size()-1);
        }
        //delete the root element in heap
        int  extract_max(){
            if (array.size()==0){
                cout<<"The heap is empty ";
                return -1;
            }
            int max_element=array[0];
            //assign last element in the heap to root node
            array[0]=array.back();
            //remove the last element from the heap
            array.pop_back();
            //fix the max Heap properties
            heapify_Down(0);
            
            return max_element;
        }

        //Function to display the max heap array
        void print(){
            if(array.size()==0){
                cout<<"The Max heap is empty";
            }else{
                cout<<"THE MAX HEAP : ";
                for(int i=0;i<array.size();i++){
                    cout<<array[i]<<"\t";
                }
                cout<<endl;
            }
        }
};

int main(){
    int ch;
    MaxHeap maxi;
    while(1){
        cout<<"\n1.Insert"
          "\n2.Delete"
          "\n3.Print"
          "\n4.exit(0)"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:{
                int n;
                cout<<"Enter the data : ";
                cin>>n;
                maxi.insert(n);
                break;
            }
            case 2:{
                cout<<"the deleted MAximum node : "<<maxi.extract_max();
                break;
            }
            case 3:maxi.print();break;
            case 4:exit(0);
            default:cout<<"Invalid choice";
        } 
    }
    
}