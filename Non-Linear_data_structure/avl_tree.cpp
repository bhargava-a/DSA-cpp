#include<iostream>
using namespace std;
class node{
    public:
    node * left,*right;
    int data;
}*root=NULL;

node *create(){
    node *newnode=new node();
    cout<<"Enter the data : ";
    cin>>newnode->data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

node *insert(node *root,node *newnode){
    if(root=NULL){
        return newnode;
    }
    if(newnode->data<root->data){
        root->left=insert(root->left,newnode);
    }else if(newnode->data>root->data){
        root->right=insert(root->right,newnode);
    }

}
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
                node *newnode=create();
                root=insert(root,newnode);
                break;
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
