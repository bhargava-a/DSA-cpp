#include <iostream>
using namespace std;
#define n 5

int queue[n];
int front=-1,rear=-1;
void enqueue(){
    if(front==-1&&rear==-1){
        front++;rear++;
        cout<<"Enter data : ";
        cin>>queue[rear];
    }else if((rear+1)%n==front){
        cout<<"Queue overflow"<<endl;
    }else{
        rear=(rear+1)%n;
        cout<<"Enter the data : ";
        cin>>queue[rear];
    }
}
void dequeue(){
    if(front==-1&&rear==-1){
        cout<<"Queue is empty"<<endl;
    }else if(front==rear){
       rear=front=-1; 
    }else{
        cout<<"Dequeued element : "<<queue[front];
        front=(front+1)%n; 
    }
}
void peek(){
    if(front==-1&&rear==-1){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"front element is : "<<queue[front]<<endl;  
    }
}

void dis(){
   int i=front;
   if(front==-1&&rear==-1){
        cout<<"Queue is empty"<<endl;
    }else{
        while(i!=rear){
            cout<<queue[i]<<"\t";
            i=(i+1)%n;
        }  
        cout<<queue[rear];
    }
}
int main() {
    int choice;
    while(1){
        cout<<"\n1.enqueue\n2.dequeue\n3.peek\n6.Display queue\n7.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3:peek();break;
            case 6:dis();break;
            case 7:exit(0);break;
            default:cout<<"INVALID CHOICE"<<endl;
        }
    }
    return 0;
}
