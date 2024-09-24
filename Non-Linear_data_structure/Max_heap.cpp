#include<iostream>
#include<vector>
using namespace std;
int main(){
    int ch;
    while(1){
        cout<<"\n1.Insert"
          "\n2.Delete"
          "\n3.Print"
          "\n4.exit(0)";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:insert();break;
            case 2:del();break;
            case 3:print();break;
            case 4:exit(0);
            default:cout<<"Invalid choice";
        } 
    }
    
}