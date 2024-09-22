#include <iostream> // cd C++\DSA-cpp\Non-Linear_data_structure
#include <algorithm>
using namespace std;
class node{
    public:
    int data;
    node *left,*parent,*right;
    string color;
};
node *root=NULL;
node *NIL=new node();

//Function to values for NIL node(NULL node)
void ini_NIL(){
    NIL->color="black";
    NIL->left=NULL;
    NIL->right=NULL;
    NIL->parent=NULL;
}
// Function to create a new node
node *create(){
    node *newnode=new node();
    cout<<"Enter data : ";
    cin>>newnode->data;
    newnode->color="red";
    newnode->left=NIL;
    newnode->right=NIL;
    newnode->parent=NULL;
    return newnode;
}

// Function for left rotation
node *left_rotation(node *x){
    node *y = x->right;
    x->right = y->left;
    if (y->left != NIL){
        y->left->parent = x;
    }
    y->parent = x->parent;
    
    if (x->parent == NULL) {
        root = y;
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    
    y->left = x;
    x->parent = y;
}
// Function to right rotation
node *right_rotation(node *y){
    node *x = y->left;
    y->left = x->right;
    if (x->right != NIL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    
    if (y->parent == NULL){
        root = x;
    }
    else if (y == y->parent->right){
        y->parent->right = x;
    }
    else {
        y->parent->left = x;
    }
    
    x->right = y;
    y->parent = x;
}

// Function to fix Red-Black Tree after insertion
void fixInsert(node *&root, node *newnode) {
    while (newnode != root && newnode->parent->color == "red"){
        if (newnode->parent == newnode->parent->parent->left){
            node *uncle = newnode->parent->parent->right;
            
            if (uncle->color == "red") {
                // Case 1: Uncle is red
                newnode->parent->color = "black";
                uncle->color = "black";
                newnode->parent->parent->color = "red";
                newnode = newnode->parent->parent;
            } else {
                // Case 2 and 3: Uncle is black
                if (newnode == newnode->parent->right) {
                    newnode = newnode->parent;
                    left_rotation(root, newnode);
                }
                newnode->parent->color = "black";
                newnode->parent->parent->color = "red";
                right_rotation(root, newnode->parent->parent);
            }
        } else {
            // Symmetric case: parent is right child
            node *uncle = newnode->parent->parent->left;
            if (uncle->color == "red") {
                newnode->parent->color = "black";
                uncle->color = "black";
                newnode->parent->parent->color = "red";
                newnode = newnode->parent->parent;
            } else {
                if (newnode == newnode->parent->left) {
                    newnode = newnode->parent;
                    right_rotation(root, newnode);
                }
                newnode->parent->color = "black";
                newnode->parent->parent->color = "red";
                left_rotation(root, newnode->parent->parent);
            }
        }
    }
    root->color = "black";  // Ensure root is always black
}

// Function to insert a node into the Binary tree
node *insert(node *root,node *newnode){
        node *y = NULL;
    node *x = root;

    while (x != NIL) {
        y = x;
        if (newnode->data < x->data){
            x = x->left;
        }
        else {
            x = x->right;
        }
    }

    newnode->parent = y;
    if (y == NULL){
        root = newnode;
    }
    else if (newnode->data < y->data){
        y->left = newnode;
    } 
    else {
        y->right = newnode;
    }

    fixInsert(root, newnode);  // Fix Red-Black Tree properties
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

// finding the min element in right subtree
node *findmin(node *root){
    while(root->left!=NULL){    //while(root->right!=NULL){
        root=root->left;        //root=root->left;
    }                           //}
    return root;
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
