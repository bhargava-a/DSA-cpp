#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *create(int data){
    node *newnode=new node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node *insertnode(node *root, int data) {
    if (root == NULL) {
        return create(data);
    }
    if (data < root->data) {
        root->left = insertnode(root->left, data);
    } else if (data > root->data) {
        root->right = insertnode(root->right, data);
    }
    // If data == root->data, do nothing (no duplicates allowed)
    return root;
}

void preorder(node* root){
    if(root!=NULL){
        cout<<root->data<<"\t";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<"\t";
        inorder(root->right);
    }
}

void postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"\t";
    }
}
node* search(node *root,int key){
    if(root==NULL||root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}
int main(){
    node* root=NULL;
    root =insertnode(root,8);   
    root =insertnode(root,3);    
    root =insertnode(root,9);    
    root =insertnode(root,2);   
    root =insertnode(root,4);
    root =insertnode(root,8);
    root =insertnode(root,10);
    cout<<"preorder : ";preorder(root);
    cout<<endl;
    cout<<"inorder  : ";inorder(root);
    cout<<endl;
    cout<<"postorder: ";postorder(root);
    cout<<endl;
    
}
