#include<iostream>
using namespace std;
class dll{
    public: 
        dll* prev;
        int data;
        dll* next;
};
void dis(){

}
int len(){

}

void insert_at_begin(){

}

void insert_at_end(){

}

void insert_at_loc(){

}

void delete_at_begin(){

}

void delete_at_end(){

}

void delete_at_loc(){

}

void reverse(){

}

int main(){
    int choice;
    while(1){
        cout<<"\n\n1.insert at beginning\n2.insert at end\n3.insert at specific location"
        "\n4.delete at beginning\n5.delete at end\n6.delete at specific location"
        "\n7.display\n8.reverse\n9.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:insert_at_begin();break;
            case 2:insert_at_end();break;
            case 3:insert_at_loc();break;
            case 4:delete_at_begin();break;
            case 5:delete_at_end();break;
            case 6:delete_at_loc();break;
            case 7:dis();break;
            case 8:reverse();break;
            case 9:exit(0);break;
            default:cout<<"Invalid choice"<<endl;
        }
    }
}