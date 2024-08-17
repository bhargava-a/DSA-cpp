#include "iostream"
using namespace std;

#define n 5
int que[n];
int front =-1,rear=-1;

void en()
{
    if(rear==(n-1)){
        cout<<"\nQueue is full"<<endl;
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        cout<<"\nEnter the value to enqueue : ";
        cin>>que[rear];
    }
    else{
        rear++;
        cout<<"\nEnter the value to enqueue : ";
        cin>>que[rear];
    }
}

void de()
{
    if(front==-1&&rear==-1){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"\nThe deleted element is : "<<que[front];
        front++;
    }
}

void peek(){
     if(front==-1&&rear==-1){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"\nThe front element is : "<<que[front];
    }
}

void isempty(){
     if(front==-1&&rear==-1){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"The Queue is not empty"<<endl;
    }
}

void isem(){
     if(front==-1&&rear==-1){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"\nThe Queue is not empty";
    }
}

void isfull(){
     if(rear==n-1){
        cout<<"Queue is full"<<endl;
    }
    else{
        cout<<"The Queue is not full"<<endl;
    }
}

void display(){
    if(front==-1&&rear==-1){
        cout<<"Queue is empty"<<endl;
    }
    else{
    int i=front;
    int j=rear;
    while(i<=j){
        cout<<que[i]<<"\t";
        i++;
    }
  }cout<<endl;
}

int main()
{
    cout<<"~~~~~Hello,Welcome to queue operations~~~~~"<<endl;
    int choice;
    cout<<"\nWhat operation do you want to do today"<<endl;
    while(1)
    {
        cout<<"\n1.enqueue\n2.dequeue\n3.peek\n4.isempty\n5.isfull\n6.display"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice){
            case 1:en();break;
            case 2:de();break;
            case 3:peek();break;
            case 4:isem();break;
            case 5:isfull();break;
            case 6:display();break;
            default :cout<<"INVALID CHOICE"<<endl;
        }
        
    }
return 0;
}