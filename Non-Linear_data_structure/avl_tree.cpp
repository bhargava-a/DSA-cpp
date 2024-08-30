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
        switch(choice){
            case 1 :{
                
            }
            case 2 :{
                
            }
            case 3 :{
                
            }
            case 4 :preorder(root);break;
            case 5 :inorder(root);break;
            case 6 :postorder(root);break;
            case 7 :exit(0);break;
            default: cout<<"Invalid choice nigga"<<endl;
        }
    }
   return 0;
}
