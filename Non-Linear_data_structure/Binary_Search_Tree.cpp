#include <iostream> // cd C++\DSA-cpp
using namespace std;
class node{
    public:
    node *left;
    int data;
    node *right;
};

class bst{
    private:
    node *root;
    // finding the min element in right subtree
    node *findmin(node *root){
        while(root->left!=NULL){    //while(root->right!=NULL){
            root=root->left;        //root=root->left;
        }                           //}
        return root;
    }
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
    node *inst(node *root,int data){
        if(root==NULL){
            return create();
        }
        if(data < root->data){
            root->left=inst(root->left,data);
        }else if(data > root->data){
            root->right=inst(root->right,data);
        }
        return root;
    }
    // Function to print pre-order elements
    void pre(node *root){
        if(root!=NULL){
            cout<<root->data<<"\t";
            pre(root->left);
            pre(root->right);
        }
    }

    // Function to print in-order elements
    void in(node *root){
        if(root!=NULL){
            in(root->left);
            cout<<root->data<<"\t";
            in(root->right);
        }
    }

    // Function to print post-order elements
    void post(node *root){
        if(root!=NULL){
            post(root->left);
            post(root->right);
            cout<<root->data<<"\t";
        }
    }

    // Function to search for a node in the Binary tree
    node *lookup(node *root,int key){
        if(root==NULL||root->data==key){
            return root;
        }
        if(key<root->data){
            return lookup(root->left,key);
        }else{
            return lookup(root->right,key);
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
    public:
    bst():root(nullptr){};

    void insert(int data){
        root=inst(root,data);
    }
    void del(int data){
        root=dele(root,data);
    }
    node* search(int key){
        return lookup(root,key);
    }
    void preorder(){
        cout<<"Pre-Order : ";
        pre(root);
        cout<<endl;
    }
    void inorder(){
        cout<<"In-Order : ";
        in(root);
        cout<<endl;
    }
    void postorder(){
        cout<<"Post-Order : ";
        post(root);
        cout<<endl;
    }
};

int main() {
    int ch;
    bst binary_search_tree;
    while(1){
        cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Preorder\n5.Inorder\n6.Post-order\n7.Exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1 :{
                int n;
                cout<<"Enter the data : ";
                cin>>n;
                binary_search_tree.insert(n);
                break;
            }

            case 2 :{
                int n;
                cout<<"Enter the node to be deleted : ";
                cin>>n;
                binary_search_tree.del(n);
                break;
            }

            case 3 :{
                int key;
                cout<<"Enter the node to be searched : ";
                cin>>key;
                if(binary_search_tree.search(key)){
                    cout<<"Node found"<<endl;
                }else{
                    cout<<"Node not found"<<endl;
                }
                break;
            }
            case 4:{
                binary_search_tree.preorder();
                break;
            }
            case 5:{
                binary_search_tree.inorder();
                break;
            }
            case 6:{
                binary_search_tree.postorder();
                break;
            }
            case 7 :exit(0);
            default:cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
  }
