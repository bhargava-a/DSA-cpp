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

        void heapify(int index){
            if(index==0){
                return;
            }
            int parent=(index-1)/2;
            if(array[index]<array[parent]){
                swapi(&array[index],&array[parent]);
                heapify(parent);
            }
        }

        void heapify_Down(int index){
            int left=2*index+1;
            int right=2*index+2;
            int smallest=index;

            if(left<array.size() && array[left]<array[smallest]){
                smallest=left;
            }
            if(right<array.size() && array[right]<array[smallest]){
                smallest=right;
            }
            if(smallest!=index){
                swapi(&array[smallest],&array[index]);
                heapify_Down(smallest);
            }
        }
    public:
        //insert an element into heap
        void insert(int data){
            array.push_back(data);
            heapify(array.size()-1);
        }
        //delete the root element in heap
        int  extract_min(){
            int smallest=array[0];
            array[0]=array.back();
            array.pop_back();
            heapify_Down(0);

            return smallest;
        }

        //Function to display the max heap array
        void print(){
            if(array.size()==0){
                cout<<"The Min heap is empty";
            }else{
                cout<<"THE MIN HEAP : ";
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
                cout<<"the deleted MAximum node : "<<mini.extract_min();
                break;
            }
            case 3:mini.print();break;
            case 4:exit(0);
            default:cout<<"Invalid choice";
        } 
    }
    
}