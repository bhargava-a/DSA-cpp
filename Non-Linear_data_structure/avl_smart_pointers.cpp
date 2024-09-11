#include <iostream> // cd C++\DSA-cpp\Non-Linear_data_structure
#include <algorithm>
#include <memory>

using namespace std;
class node{
    public:
    shared_ptr<node> left;
    int data;
    shared_ptr<node> right;
    int height;
};
shared_ptr<node> root=nullptr;

// Function to create a new node
shared_ptr<node> create(){
    shared_ptr<node> newnode=make_shared<node>();
    cout<<"Enter data : ";
    cin>>newnode->data;
    newnode->left=nullptr;
    newnode->right=nullptr;
    newnode->height=1;
    return newnode;
}
// Function to height of a node
int getheight(shared_ptr<node> root){
    if(root==nullptr){
        return 0;
    }
    return root->height;
}
// Function to getbalance factor of the node
int getbalance(shared_ptr<node> root){
    if(root==nullptr){
        return 0;
    }
    return getheight(root->left)-getheight(root->right);
}
// Function for left rotation
shared_ptr<node> left_rotation(shared_ptr<node> x){
    shared_ptr<node> y=x->right;
    shared_ptr<node> T2=y->left;

    //performing rotation of nodes
    y->left=x;
    x->right=T2;

    //Updating heights of root & MID NODE nodes which are x & y;
    x->height=1 + max(getheight(x->left),getheight(x->right));
    y->height=1 + max(getheight(y->left),getheight(y->right));

    return y;
}
// Function to right rotation
shared_ptr<node> right_rotation(shared_ptr<node> y){
    shared_ptr<node> x=y->left;
    shared_ptr<node> T2=x->right;

    //Performing rotation of nodes
    x->right=y;
    y->left=T2;

    //updating the heights of ROOT NODE and MID NODE 
    y->height=1+max(getheight(y->left),getheight(y->right));
    x->height=1+max(getheight(x->left),getheight(x->right));

    return x;
}


// Function to insert a node into the Binary tree
shared_ptr<node> insert(shared_ptr<node> root,shared_ptr<node> newnode){
    if(root==nullptr){
        return newnode;
    }
    if(newnode->data < root->data){
        root->left=insert(root->left,newnode);
    }else if(newnode->data > root->data){
        root->right=insert(root->right,newnode);
    } else {
        // Duplicate data is not allowed in AVL Tree
        return root;
    }

    root->height=1+ max(getheight(root->left),getheight(root->right));
    int balance_factor=getbalance(root);

    //case 1: Left left rotation
    if(balance_factor >1&& newnode->data < root->left->data){
        return right_rotation(root);
    }

    //case 2: Right right rotation
    if(balance_factor < -1&& newnode->data >root->right->data){
        return left_rotation(root);
    }

    //case 3 : Left right rotation
    if(balance_factor >1 && newnode->data > root->left->data){
        root->left=left_rotation(root->left);
        return right_rotation(root);
    }

    // case 4 : Right Left rotation
    if(balance_factor < -1 && newnode->data < root->right->data){
        root->right=right_rotation(root->right);
        return left_rotation(root);
    }
    return root;
}

// Function to print pre-order elements
void preorder(shared_ptr<node> root){
    if(root!=nullptr){
        cout<<root->data<<"\t";
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to print in-order elements
void inorder(shared_ptr<node> root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<"\t";
        inorder(root->right);
    }
}

// Function to print post-order elements
void postorder(shared_ptr<node> root){
    if(root!=nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"\t";
    }
}

// Function to search for a node in the Binary tree
shared_ptr<node> search(shared_ptr<node> root,int key){
    if(root==nullptr||root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}

// finding the min element in right subtree
shared_ptr<node> findmin(shared_ptr<node> root){
    while(root->left!=NULL){    //while(root->right!=NULL){
        root=root->left;        //root=root->left;
    }                           //}
    return root;
}
//deleting the node 
shared_ptr<node> dele(shared_ptr<node> root,int data){
    if(root==NULL){
        return root;
    }
    if(data<root->data){
        root->left=dele(root->left,data);
    }else if(data>root->data){
        root->right=dele(root->right,data);
    }else{
        //case 1:if node does not have any child nodes
        if(root->left==nullptr&&root->right==nullptr){
            cout << "Node " << root->data << " deleted" << endl;
            //delete root;
            return nullptr;
        }
        //case 2:if node has only 1 node,either in left subtree or right subtree
        if(root->left==nullptr){
            cout<<"Node "<<root->data<<"  deleted"<<endl;
            shared_ptr<node> temp=root->right;
            //delete root;
            return temp;
        }
        if(root->right==nullptr){
            cout << "Node " << root->data << " deleted" << endl;
            shared_ptr<node> temp=root->left;
            //delete root;
            return temp;
        }
        //case 3:if node has 2 child nodes,then
        //find the inorder successor or pre-decessor of the node
        //(SMALLEST IN RIGHT SUBTREE OR BIGGEST IN LEFT SUBTREE)
        shared_ptr<node> temp =findmin(root->right);   //or node *temp =findmin(root->left);
        //changing root node value with inorder's successor
        root->data=temp->data;     
        //deleting the inorder successor
        root->right=dele(root->right,temp->data);   //or root->left=dele(root->left,temp->data);
    }
    //If the tree had only one node then return
    if(root==nullptr){
        return root;
    }
    // update height of the current node
    root->height=1+max(getheight(root->right),getheight(root->left));

    //step 3 : get the balance factor the current node
    int balance_factor=getbalance(root);

    //case 1: Left left rotation
    if(balance_factor > 1 && getbalance(root->left) >=0){
        return right_rotation(root);
    }
    //case 2: left right rotation
    if(balance_factor >1&&getbalance(root->left)<0){
        root->left=left_rotation(root->left);
        return right_rotation(root);
    }
    // case 3 :right right rotaion
    if(balance_factor <-1 && getbalance(root->right)<=0)
    return left_rotation(root);

    //case 4:right left rotation
    if(balance_factor<-1&& getbalance(root->right)>0){
        root->right=right_rotation(root->right);
        return left_rotation(root);
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
                shared_ptr<node> newnode=create();  //create a newnode 
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
                shared_ptr<node> found=nullptr;
                found=search(root,key);
                if(found!=nullptr){
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
