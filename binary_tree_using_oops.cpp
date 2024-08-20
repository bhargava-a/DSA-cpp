#include <iostream>
using namespace std;
class node{
    public:
    node *left;
    int data;
    node *right;
};
node *root=NULL;

// Function to create a new node
node *create(){
    node *newnode=new node();
    cout<<"Enter data : ";
    cin>>newnode->data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

// Function to insert a node into the Binary tree
node *insert(node *root,node *newnode){
    if(root==NULL){
        return newnode;
    }
    if(newnode->data < root->data){
        root->left=insert(root->left,newnode);
    }else if(newnode->data > root->data){
        root->right=insert(root->right,newnode);
    }
    return root;
}
int main() {
    int ch;
    while(1){
        cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Preorder\n5.Inorder\n6.Post-order\n7.Exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1 :node *newnode=create();  //create a newnode 
                    root=insert(root,newnode);  //Insert a newnode into the binary tree
                    break;

            case 2 :dele();break;
            case 3 :search();break;
            case 4 :preorder();break;
            case 5 :inorder();break;
            case 6 :postorder();break;
            case 7 :exit(0);
            default:cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}
