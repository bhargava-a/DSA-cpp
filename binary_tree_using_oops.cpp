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

int main() {
    int ch;
    while(1){
        cout<<"\n1.insert\n2.delete\n3.search\n4.preorder\n5.insert\n6.insert\n7.Exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1 : insert();break;
            case 2 : delete();break;
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
