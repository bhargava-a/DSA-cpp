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
    return root;
}

node *del(node *root,int node){
    return root;
}

node *search(node *root,int key){
    if(root==NULL||root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
    return root;
}

void preorder(node *root){
    if(root!=NULL){
        cout<<root->data<<"\t";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root){
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
                int node;
                cout<<"Enter the node : ";
                cin>>node;
                root=del(root,node);
            }
            case 3 :{
                int key;
                cout<<"Enter the search node : ";
                cin>>key;
                node *found=NULL;
                found=search(root,key);
                if(found!=NULL){
                    cout<<"Node found"<<endl;
                }else{
                    cout<<"Node not found"<<endl;
                }
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
