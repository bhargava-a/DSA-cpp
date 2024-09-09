#include<iostream>
#include<memory>
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
