#include<iostream>

using namespace std;
class node{
    public:
        string srn,name;
        int age,marks;
        node* next;
}*head=NULL,*newnode,*temp;

void enter(){
    cout<<"Enter student srn : ";
    cin>>newnode->srn;
    cout<<"Enter student name : ";
    cin>>newnode->name;
    cout<<"Enter student age : ";
    cin>>newnode->age;
    cout<<"Enter student marks : ";
    cin>>newnode->marks;
}

void dis() {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    temp = head;
    
    // Display the first student separately
    cout<<endl;
    cout<<"~~~~~~~~~STUDENT DETAILS~~~~~~~~~"<<endl;
    cout << "Student srn : " << temp->srn << endl;
    cout << "Student name : " << temp->name << endl;
    cout << "Student age : " << temp->age << endl;
    cout << "Student marks : " << temp->marks << endl;

    // Move to the next student
    temp = temp->next;
    
    // Display the rest of the students in a chain format
    while (temp != NULL) {
        cout << "\t|" << endl;
        cout << "\tV" << endl;
        cout << "Student srn : " << temp->srn << endl;
        cout << "Student name : " << temp->name << endl;
        cout << "Student age : " << temp->age << endl;
        cout << "Student marks : " << temp->marks << endl;
        temp = temp->next;
    }
    cout << "\t|" << endl;
    cout << "\tV" << endl;
    cout << "       NULL" << endl;
}

void dele_dis(node* item){
    cout<<"Student srn : "<<item->srn<<endl;
    cout<<"Student name : "<<item->name<<endl;
    cout<<"Student age : "<<item->age<<endl;
    cout<<"Student marks : "<<item->marks<<endl;      
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
    enter();
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
    enter();
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
        enter();
        newnode->next=temp->next;
        temp->next=newnode;
    }
    dis();
}

void delete_at_begin(){
    if(head==NULL){
        cout<<"list is empty"<<endl;
    }
    cout<<"Deleted node is : ";
    dele_dis(head);
    temp=head;
    head=head->next;
    delete temp;
    
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
    cout<<"Deleted node : ";
    dele_dis(temp);
    dele->next=NULL;
    delete temp;
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
        cout<<"Deleted node is : ";
        dele_dis(kill);
        delete kill;
    }
}

int main(){
    int choice;
    while(1){
        cout<<"\n\n1.insert at beginning"
              "\n2.insert at end"
              "\n3.insert at specific location"
              "\n4.delete at beginning"
              "\n5.delete at end"
              "\n6.delete at specific location"
              "\n7.display"
              "\n8.Exit"<<endl;
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
            case 8:exit(0);break;
            default:cout<<"Invalid choice"<<endl;
        }
    }
}
