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
    public:
        void insert(int data){
            array.push_back(data);
            heapify(array.size()-1);
        }
};

int main(){
    int ch;
    MaxHeap maxi;
    while(1){
        cout<<"\n1.Insert"
          "\n2.Delete"
          "\n3.Print"
          "\n4.exit(0)";
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
            case 2:del();break;
            case 3:print();break;
            case 4:exit(0);
            default:cout<<"Invalid choice";
        } 
    }
    
}