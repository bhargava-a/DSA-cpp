#include"iostream"
using namespace std;
class stack{
    public:
        int data;
        stack* next;
}*head=NULL,*newnode;
void dis(){
    stack *temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        if(temp->next!=NULL){
            cout<<"->"<<" ";
        }
        temp=temp->next;
    }
    cout<<"->NULL"<<endl;
}

void push(){
    newnode=new stack();
    cout<<"Enter the data : ";
    cin>>newnode->data;
    if(head==NULL){
        head=newnode;
    }else{
        newnode->next=head;
        head=newnode;
    }
}

void pop(){
    if(head==NULL){
        cout<<"Stack list is empty"<<endl;
    }
    cout<<"The deleted node is : "<<head->data<<endl;
    stack* temp=head;
    head=head->next;
    delete temp;
}

void peek(){
    if(head==NULL){
        cout<<"Stack list is empty"<<endl;
    }else{
        cout<<"The top node data is : "<<head->data<<endl;
    }
}

int main(){
    int choice;
    while(1){
        cout<<"\n1.push\n2.pop\n3.peek\n4.dis\n5.exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:push();break;
            case 2:pop();break;
            case 3:peek();break;
            case 4:dis();break;
            case 5:exit(0);break;
            default:cout<<"INVALID CHOICE"<<endl;
        }
    }
}