#include<iostream>

using namespace std;
class DEqueue{
    public:
        int data;
        DEqueue* next;
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
    cout<<"->NULL"<<endl;
}

void insert_at_begin(){
    newnode=new DEqueue();
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
    newnode=new DEqueue();
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

void delete_at_begin(){
    if(head==NULL){
        cout<<"DE_queue list is empty"<<endl;
    }
    cout<<"Deleted node is : "<<head->data<<endl;
    temp=head;
    head=head->next;
    delete temp;
    dis();
}
void delete_at_end(){
    if(head==NULL){
        cout<<"DE_queue list is empty"<<endl;
    }
    DEqueue* dele;
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

int main(){
    int choice;
    while(1){
        cout<<"\n\n1.insert at front\n2.insert at rear\n3.delete at front\n4.delete at rear\n5.display\n6.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:insert_at_begin();break;
            case 2:insert_at_end();break;
            
            case 3:delete_at_begin();break;
            case 4:delete_at_end();break;
            
            case 5:dis();break;
            
            case 6:exit(0);break;
            default:cout<<"Invalid choice"<<endl;
        }
    }
}