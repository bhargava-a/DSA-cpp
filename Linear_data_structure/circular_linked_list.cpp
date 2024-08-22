#include<iostream>
using namespace std;
class cll{
    public: 
        int data;
        cll* next;
}*tail=NULL,*newnode;
void dis(){
    cll *temp=tail->next;
    while(temp->next!=tail->next){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
int len(){
    int length=0;
    cll *temp=tail->next;
    while(temp->next!=tail->next){
        length++;
        temp=temp->next;
    }
    return length;
}

void insert_at_begin(){
    newnode=new cll();
    cout<<"Enter the data : ";
    cin>>newnode->data;
    if(tail==NULL){
        tail=newnode;
        tail->next=tail;
    }else{
        newnode->next=tail->next;
        tail->next=newnode;
    }
    dis();
}

void insert_at_end(){
    newnode=new cll();
    cout<<"Enter the data : ";
    cin>>newnode->data;
    if(tail==NULL){
        tail=newnode;
        tail->next=tail;
    }else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    dis();
}

void insert_at_loc(){
    int pos,count=len(),i=1;
    cout<<"Enter position : ";
    cin>>pos;
    if(pos>count){
        cout<<"INVALID LOCATION"<<endl;
    }else if(pos==1){
        insert_at_begin();
    }{
        newnode=new cll();
        cout<<"Enter the data : ";
        cin>>newnode->data;

        cll *temp=tail->next;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    dis();
}

void delete_at_begin(){
    cll* temp=tail->next;
    if(tail==NULL){
        cout<<"List is Empty";
    }else if(temp->next==temp){
        tail=NULL;
        delete temp;
    }else{
        tail->next=temp->next;
        cout<<"The deleted node is : "<<temp->data<<endl;
        delete temp;
    }
    dis();
}

void delete_at_end(){
    cll  *temp=tail->next,*dele;
    if(tail==NULL){
        cout<<"List is empty"<<endl;
    }else if(temp->next==temp){
        tail=NULL;
        delete temp;
    }else{
        while(temp->next!=tail->next){
            dele=temp;
            temp=temp->next;
        }
        cout<<"The deleted node : "<<temp->data<<endl;
        dele->next=tail->next;
        tail=dele;
        delete temp;
    }
}

void delete_at_loc(){
    cll  *temp=tail->next,*kill;
    int loc,i=1,count=len();
    if(tail==NULL){
        cout<<"list is empty"<<endl;
    }
    cout<<"Enter location : ";
    cin>>loc;
    if(loc>count){
        cout<<"Invalid location "<<endl;
    }else if(loc==1){
        delete_at_begin();
    }else{
        while(i<loc-1){
            temp=temp->next;
            i++;
        }
        kill=temp->next;
        cout<<"The deleted node is : "<<kill->data;
        temp->next=kill->next;
        delete kill;
    }
    dis();
}

void reverse(){
    if(tail==NULL){
        cout<<"List is empty"<<endl;
    }else{
        cll *prev,*current,*nextnode;
        current=tail->next;
        nextnode=current->next;    ////tail->next->next;
        while(current!=tail){
            prev=current;
            current=nextnode;
            nextnode=current->next;
            current->next=prev;
        }
        nextnode->next=tail;
        tail=nextnode;
    }
    dis();
}

int main(){
    int choice;
    while(1){
        cout << "\nMenu:\n"
        "1. Insert at beginning\n"
        "2. Insert at end\n"
        "3. Insert at specific location\n"
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