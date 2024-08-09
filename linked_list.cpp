#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
}*head=NULL,*newnode,*temp;


void dis(){
    temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        if(temp->next!=NULL){
            cout<<"->"<<" ";
        }
        temp=temp->next;
    }
    cout<<"->NULL";
}
int len(){
    int length=0;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    return length;
}
void insert_at_begin(){
    newnode=new node();
    cout<<"Enter data : ";
    cin>>newnode->data;
    newnode->next=NULL;
    if(head==NULL){
        head=temp=newnode;
    }else{
        newnode->next=head;
        head=newnode;
    }
    dis();
}
void insert_at_end(){
    newnode=new node();
    cout<<"Enter data : ";
    cin>>newnode->data;
    newnode->next=NULL;
    if(head==NULL){
        head=temp=newnode;
    }else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    dis();
}
void insert_at_loc(){
    int pos,i=1,length=len();
    cout<<"Enter the position : ";
    cin>>pos;

    if(pos>length){
       cout<<"invalid position"<<endl;
    }else{
        // TRAVERSING Part
        temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        //linking part
        newnode=new node();
        cout<<"Enter data : ";
        cin>>newnode->data;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    dis();
}
void delete_at_begin(){
    if(head==NULL){
        cout<<"list is empty"<<endl;
    }
    cout<<"Deleted node is : "<<head->data<<endl;
    temp=head;
    head=head->next;
    delete temp;
    dis();
}
void delete_at_end(){
    if(head==NULL){
        cout<<"list is empty"<<endl;
    }
    node* dele;
    temp=head;
    while(temp->next!=NULL){
        dele=temp;
        temp=temp->next;
    }
    cout<<"Deleted node : "<<temp->data<<endl;
    dele->next=NULL;
    delete temp;
    dis();
}
void delete_at_loc(){
    int pos,i=1,length=len();
    cout<<"Enter the pos : ";
    cin>>pos;
    if(pos>length){
        cout<<"Invalid position"<<endl;
    }else if(head==NULL){
        cout<<"list is empty"<<endl;
    }else{
        temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        node* kill=temp->next;
        temp->next=kill->next;
        cout<<"Deleted node is : "<<kill->data<<endl;
        delete kill;
    }
    dis();
}

void reverse(){
    node* prev=NULL,*current,*nextnode;
    current=nextnode=head;
    while(nextnode!=NULL){
        nextnode=nextnode->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    head=prev;
    dis();
}
int main(){
    int choice;
    while(1){
        cout<<"\n\n1.insert at beginning\n2.insert at end\n3.insert at specific location"
        "\n4.delete at beginning\n5.delete at end\n6.delete at specific location"
        "\n7.display\n8.reverse\n9.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:insert_at_begin();break;
            case 2:insert_at_end();break;
            case 3:insert_at_loc();break;
            case 4:delete_at_begin();break;
            case 5:delete_at_end();break;
            case 6:delete_at_loc();break;
            case 7:dis();break;
            case 8:reverse();break;
            case 9:exit(0);break;
            default:cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
/*void reverse() {
    node* temp = head;
    int n = len();
    int* arr = new int[n]; // Dynamic array to store the values
    int i = 0;
    while (temp != NULL) {
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    }
    cout << "Reversed list: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    delete[] arr; // Free the dynamically allocated memory
}*/