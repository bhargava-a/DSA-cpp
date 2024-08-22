#include"iostream"
using namespace std;
class queue{
    public:
        int data;
        queue* next;
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

void enq(){
    newnode=new queue();
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

void deq(){
    cout<<"The deleted front node : "<<head->data<<endl;
    temp=head;
    head=head->next;
    delete temp;
    dis();
}

void peek(){
    if(head==NULL){
        cout<<"Queue list is empty"<<endl;
    }else{
        cout<<"The front node data is : "<<head->data<<endl;
    }
}

int main(){
    int choice;
    while(1){
        cout<<"\n1.Enqueue\n2.Dequeue\n3.peek\n4.dis\n5.exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:enq();break;
            case 2:deq();break;
            case 3:peek();break;
            case 4:dis();break;
            case 5:exit(0);break;
            default:cout<<"INVALID CHOICE"<<endl;
        }
    }
}