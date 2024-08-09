#include<iostream>
using namespace std;
class dll{
    public: 
        dll* prev;
        int data;
        dll* next;
}*head=NULL,*newnode,*tail,*temp;
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
    newnode=new dll();
    cout<<"Enter the data : ";
    cin>>newnode->data;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=tail=newnode;
    }else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    dis();
}

void insert_at_end(){
    newnode=new dll();
    cout<<"Enter data : "; 
    cin>>newnode->data;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=tail=newnode;
    }else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    dis();
}

void insert_at_loc(){
    int loc,count=len(),i=1;
    cout<<"Enter the location : ";
    cin>>loc;
    if(head==NULL){
        head=tail=newnode;
    }else if(loc>count){
        cout<<"Invalid position"<<endl;
    }else{
        // TRAVERSING PART
        temp=head;
        while(i<loc-1){
            temp=temp->next;
            i++;
        }
        // linking part
        newnode=new dll();
        cout<<"Enter data : ";
        cin>>newnode->data;
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next->prev=newnode;
    }
    dis();
}

void insert_at_afterloc(){
    int loc,count=len(),i=1;
    cout<<"Enter the location : ";
    cin>>loc;
    if(head==NULL){
        head=tail=newnode;
    }else if(loc>count){
        cout<<"Invalid position"<<endl;
    }else{
        // TRAVERSING PART
        temp=head;
        while(i<loc){
            temp=temp->next;
            i++;
        }
        // linking part
        newnode=new dll();
        cout<<"Enter data : ";
        cin>>newnode->data;
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next->prev=newnode;
    }
    dis();
}

void delete_at_begin(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }else{
        cout<<"The deleted node : "<<head->data<<endl;
        temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
    }
    dis();
}

void delete_at_end(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }else{
        cout<<"The deleted node : "<<tail->data<<endl;
        temp=tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        dis();
    }
}

void delete_at_loc(){
    int i=1,loc,count=len();
    cout<<"Enter the location : ";
    cin>>loc;
    if(head==NULL){
        cout<<"list is empty"<<endl;
    }else if(loc>count||loc<1){
        cout<<"Invalid postition"<<endl;
    }else{
        temp=head;
        while(i<loc-1){
            temp=temp->next;
            i++;
        }
        dll* nextnode=temp->next;
        temp->next=nextnode->next;
        nextnode->next->prev=temp;
        delete nextnode;
    }
    dis();
}

void reverse(){
    temp=tail;
    while(temp!=NULL){
        cout<<temp->data;
        if(temp->prev!=NULL){
            cout<<"->"<<" ";
        }
        temp=temp->prev;
    }
    cout<<"->NULL";
}

int main(){
    int choice;
    while(1){
        cout << "\nMenu:\n"
        "1. Insert at beginning\n"
        "2. Insert at end\n"
        "3. Insert at specific location\n"
        "4. Insert after specific location\n"
        "5. Delete at beginning\n"
        "6. Delete at end\n"
        "7. Delete at specific location\n"
        "8. Display\n"
        "9. Reverse\n"
        "10. Exit\n"
        "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: insert_at_begin(); break;
            case 2: insert_at_end(); break;
            case 3: insert_at_loc(); break;
            case 4: insert_at_afterloc(); break;
            case 5: delete_at_begin(); break;
            case 6: delete_at_end(); break;
            case 7: delete_at_loc(); break;
            case 8: dis(); break;
            case 9: reverse(); break;
            case 10: exit(0); break;
            default: cout << "Invalid choice" << endl;
        }
    }
}