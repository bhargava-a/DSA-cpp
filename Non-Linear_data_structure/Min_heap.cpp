#include<iostream>
#include<vector>
using namespace std;

class MinHeap{
    private:
        vector<int> array;

        void swapi(int *x,int *y){
            int temp=*x;
            *x=*y;
            *y=temp;
        }

        void heapify(){
            
        }

        void heapify_Down(){
            
        }
    public:
        //insert an element into heap
        void insert(){
            
        }
        //delete the root element in heap
        int  extract_max(){
            
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
    MinHeap mini;
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
                mini.insert(n);
                break;
            }
            case 2:{
                cout<<"the deleted MAximum node : "<<mini.extract_max();
                break;
            }
            case 3:mini.print();break;
            case 4:exit(0);
            default:cout<<"Invalid choice";
        } 
    }
    
}