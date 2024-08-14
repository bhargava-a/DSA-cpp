#include<iostream>
using namespace std;
class node{
    public:
    node *left; int data; node *right;
}*root=NULL;

node *create(){
    node* newnode=new node();
    cout<<"Enter the data : ";
    cin>>newnode->data;

    cout<<"Enter left child : ";
    newnode->left=create();
    cout<<"Enter the right child : ";
    newnode->right=create();
    return newnode;
}

int main(){
    root=create();
    return 0;
}