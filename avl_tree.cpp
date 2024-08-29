#include<iostream>
using namespace std;
class node{
    node * left,*right;
    int data;
}*root=NULL;
int main (){
    int choice;
    while(1){
        cout<<"\n1.insert\n2.delete"
        "\n3.search\n4.pre-order"
        "\n5.In-order\n6.post-order"
        "\n7.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
    }
}
