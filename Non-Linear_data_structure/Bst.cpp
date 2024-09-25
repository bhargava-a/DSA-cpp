#include <iostream> // cd C++\DSA-cpp
using namespace std;
class node{
    public:
    node *left;
    int data;
    node *right;
};
node *root=NULL;
class bst{
private:
// finding the min element in right subtree
node *findmin(node *root){
    while(root->left!=NULL){    //while(root->right!=NULL){
        root=root->left;        //root=root->left;
    }                           //}
    return root;
}
public:
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
// Function to print pre-order elements
void preorder(node *root){
    if(root!=NULL){
        cout<<root->data<<"\t";
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to print in-order elements
void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<"\t";
        inorder(root->right);
    }
}

// Function to print post-order elements
void postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"\t";
    }
}

// Function to search for a node in the Binary tree
node *search(node *root,int key){
    if(root==NULL||root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}
//deleting the node 
node *dele(node *root,int data){
    if(root==NULL){
        return root;
    }
    if(data<root->data){
        root->left=dele(root->left,data);
    }else if(data>root->data){
        root->right=dele(root->right,data);
    }else{
        //case 1:if node does not have any child nodes
        if(root->left==NULL&&root->right==NULL){
            cout << "Node " << root->data << " deleted" << endl;
            delete root;
            return NULL;
        }
        //case 2:if node has only 1 node,either in left subtree or right subtree
        if(root->left==NULL){
            cout<<"Node "<<root->data<<"  deleted"<<endl;
            node *temp=root->right;
            delete root;
            return temp;
        }
        if(root->right==NULL){
            cout << "Node " << root->data << " deleted" << endl;
            node *temp=root->left;
            delete root;
            return temp;
        }
        //case 3:if node has 2 child nodes,then
        //find the inorder successor or pre-decessor of the node
        //(SMALLEST IN RIGHT SUBTREE OR BIGGEST IN LEFT SUBTREE)
        node *temp =findmin(root->right);   //or node *temp =findmin(root->left);
        //changing root node value with inorder's successor
        root->data=temp->data;     
        //deleting the inorder successor
        root->right=dele(root->right,temp->data);   //or root->left=dele(root->left,temp->data);
    }
    return root;
}
};






int main() {
    int ch;
    while(1){
        cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Preorder\n5.Inorder\n6.Post-order\n7.Exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1 :{
                node *newnode=create();  //create a newnode 
                root=insert(root,newnode);  //Insert a newnode into the binary tree
                break;
            }

            case 2 :{
                int n;
                cout<<"Enter the node : ";
                cin>>n;
                root=dele(root,n);
                break;
            }

            case 3 :{
                int key;
                cout<<"Enter the node to be searched : ";
                cin>>key;
                node *found=NULL;
                found=search(root,key);
                if(found!=NULL){
                    cout<<"Node found!!!!!woohooo"<<endl;
                }else{
                    cout<<"Node not found"<<endl;
                }
                break;
            }
            case 4:{
                cout<<"Preorder : ";
                preorder(root);
                break;
            }
            case 5:{
                cout<<"Inorder : ";
                inorder(root);
                break;
            }
            case 6:{
                cout<<"Postorder : ";
                postorder(root);
                break;
            }
            case 7 :exit(0);
            default:cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
  }
