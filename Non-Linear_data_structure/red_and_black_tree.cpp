#include <iostream> // cd C++\DSA-cpp\Non-Linear_data_structure
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
void init_NIL(){
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
void left_rotation(node *&root,node *x){
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
void right_rotation(node *&root,node *y){
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
// Function to fix Red-Black Tree after deletion
void fixDelete(node *&root, node *x) {
    while (x != root && x->color == "black") {
        if (x == x->parent->left) {
            node *sibling = x->parent->right;
            if (sibling->color == "red") {
                sibling->color = "black";
                x->parent->color = "red";
                left_rotation(root, x->parent);
                sibling = x->parent->right;
            }
            if (sibling->left->color == "black" && sibling->right->color == "black") {
                sibling->color = "red";
                x = x->parent;
            } else {
                if (sibling->right->color == "black") {
                    sibling->left->color = "black";
                    sibling->color = "red";
                    right_rotation(root, sibling);
                    sibling = x->parent->right;
                }
                sibling->color = x->parent->color;
                x->parent->color = "black";
                sibling->right->color = "black";
                left_rotation(root, x->parent);
                x = root;
            }
        } else {
            node *sibling = x->parent->left;
            if (sibling->color == "red") {
                sibling->color = "black";
                x->parent->color = "red";
                right_rotation(root, x->parent);
                sibling = x->parent->left;
            }
            if (sibling->left->color == "black" && sibling->right->color == "black") {
                sibling->color = "red";
                x = x->parent;
            } else {
                if (sibling->left->color == "black") {
                    sibling->right->color = "black";
                    sibling->color = "red";
                    left_rotation(root, sibling);
                    sibling = x->parent->left;
                }
                sibling->color = x->parent->color;
                x->parent->color = "black";
                sibling->left->color = "black";
                right_rotation(root, x->parent);
                x = root;
            }
        }
    }
    x->color = "black";
}

// Helper function to transplant subtrees during deletion
void rbTransplant(node *&root, node *u, node *v) {
    if (u->parent == NULL) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}


// finding the min element in right subtree
node *findmin(node *root){
    while(root->left!=NULL){    //while(root->right!=NULL){
        root=root->left;        //root=root->left;
    }                           //}
    return root;
}

// Function to delete a node from the Red-Black Tree
void rbDelete(node *&root, node *z) {
    node *y = z;
    string yOriginalColor = y->color;
    node *x;

    if (z->left == NIL) {
        x = z->right;
        rbTransplant(root, z, z->right);
    } else if (z->right == NIL) {
        x = z->left;
        rbTransplant(root, z, z->left);
    } else {
        y = findmin(z->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            rbTransplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rbTransplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    delete z;
    
    if (yOriginalColor == "black") {
        fixDelete(root, x);
    }
}
int main() {
    init_NIL();  // Initialize the NIL node
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
                node *z = search(root, n);  // You can implement search if it's not yet done
                if (z != NIL){
                    rbDelete(root, z);
                }
                else {
                    cout << "Node not found!\n";
                }
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
