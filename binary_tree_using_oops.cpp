#include <iostream> // cd C++\DSA\DSA-cpp
using namespace std;
class node{
    public:
    node *left;
    int data;
    node *right;
};
node *root=NULL;;

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
// Function to find the minimum value node in a subtree
node* findMin(node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
     return root;
}
// Function to delete a node from the Binary tree
node* dele(node* root, int n) {
    if (root == NULL) {
        return root; // Node not found
    }
    
    // Traverse the tree to find the node to delete
    if (n < root->data) {
        root->left = dele(root->left, n);
    } else if (n > root->data) {
        root->right = dele(root->right, n);
    } else {
        // Node to be deleted found
        
        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        
        // Case 2: Node has one child
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 3: Node has two children
        // Find the in-order successor (smallest in the right subtree)
        node* temp = findMin(root->right);
        
        // Copy the in-order successor's content to this node
        root->data = temp->data;
        
        // Delete the in-order successor
        root->right = dele(root->right, temp->data);
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

            case 2 :int n;
                    cout<<"Enter the node : ";
                    cin>>n;
                    dele(root,n);break;

            case 3 :int key;
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

            case 4 :preorder(root);break;
            case 5 :inorder(root);break;
            case 6 :postorder(root);break;
            case 7 :exit(0);
            default:cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}
