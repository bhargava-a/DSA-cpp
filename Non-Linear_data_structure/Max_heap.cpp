#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
    private:
        vector<int> array;
    
    public:
        void insert(int data){
            array.push_back(data);

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