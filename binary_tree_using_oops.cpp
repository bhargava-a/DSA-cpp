#include <iostream>
using namespace std;
class node{
    public:
    node *left;
    int data;
    node *right;
}*root,*newnode;

node *create(){
    newnode=new node();
    cout<<"Enter fat data : ";
    cin>>newnode->data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node *insert(node *root,node *newnode){
    if(root==NULL){
        root=create();
    }
    if(newnode->data < root->data){
        root->left=insert(root->left,newnode);
    }
    if(newnode->data > root->data){
        root->right=insert(root->right,newnode);
    }
    return root;
}
int main() {
    int ch;
    while(1){
        cout<<"\n1.insert\n2.delete\n3.search\n4.preorder\n5.insert\n6.insert\n7.Exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1 : root=insert();break;
            case 2 : dele();break;
            case 3 : search();break;
            case 4 : preorder();break;
            case 5 : inorder();break;
            case 6 : postorder();break;
            case 7 : exit(0);break;
            default:cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}
