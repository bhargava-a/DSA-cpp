#include<iostream>
using namespace std;
class node{
    public:
    node * left,*right;
    int data;
    int height;
}*root=NULL;
// Function to get the height of the node
int height(node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}
node *create(){
    node *newnode=new node();
    cout<<"Enter the data : ";
    cin>>newnode->data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
// Function to right rotate subtree rooted with y
node* rightRotate(node* y) {
    node* x = y->left;
    node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;
// Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}
// Function to left rotate subtree rooted with x
node* leftRotate(node* x) {
    node* y = x->right;
    node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;
// Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}
// Get the balance factor of node N
int getBalance(node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
node *insert(node *root,node *newnode){
    if(root==NULL){
        return newnode;
    }
    if(newnode->data<root->data){
        root->left=insert(root->left,newnode);
    }else if(newnode->data>root->data){
        root->right=insert(root->right,newnode);
    }
    return root;
    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));
    // 3. Get the balance factor of this ancestor node to check whether
    //    this node became unbalanced
    int balance = getBalance(node);
    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

node *findmin(node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

node *del(node *root,int Node){
    if(root==NULL){
        return root;
    }
    if(Node<root->data){
        root->left=del(root->left,Node);
    }else if(Node>root->data){
        root->right=del(root->right,Node);
    }else{
        //case 1: with no child nodes
        if(root->left==NULL&&root->right==NULL){
            cout<<"The deleted node : "<<root->data<<endl;
            delete root;
            return NULL;
        }
        //case 2:with 1 child node
        if(root->left==NULL){
            cout<<"The deleted node : "<<root->data<<endl;
            node *temp=root->right;
            delete root;
            return temp;
        }
        if(root->right==NULL){
            cout<<"The deleted node : "<<root->data<<endl;
            node *temp=root->left;
            delete root;
            return temp;
        }
        //case 3:with 2 child nodes
        node *temp=findmin(root->right);
        root->data=temp->data;
        root->right=del(root->right,temp->data);
    }
  
    
    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // 2. Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // 3. Get the balance factor of this node (to check whether
    //    this node became unbalanced)
    int balance = getBalance(root);
    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    ///HERE
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
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
                break;
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
            default: cout<<"Invalid choice nigga"<<endl;
        }
    }
   return 0;
}
