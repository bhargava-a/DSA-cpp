#include "stdio.h"

#define n 5
int que[n];
int front =-1,rear=-1;

void en()
{
    if(rear==(n-1)){
        printf("\nQueue is full\n");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        printf("\nEnter the value to enqueue : ");
        scanf("%d",&que[rear]);
    }
    else{
        rear++;
        printf("\nEnter the value to enqueue : ");
        scanf("%d",&que[rear]);
    }
}

void de()
{
    if(front==-1&&rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("\nThe deleted element is : %d\n",que[front]);
        front++;
    }
}

void peek(){
     if(front==-1&&rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("\nThe front element is : %d\n",que[front]);
    }
}

void isempty(){
     if(front==-1&&rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("The Queue is not empty\n");
    }
}

void isem(){
     if(front==-1&&rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("\nThe Queue is not empty");
    }
}

void isfull(){
     if(rear==n-1){
        printf("Queue is full\n");
    }
    else{
        printf("The Queue is not full\n");
    }
}

void display(){
    if(front==-1&&rear==-1){
        printf("Queue is empty\n");
    }
    else{
    int i=front;
    int j=rear;
    while(i<=j){
        printf("%d\t",que[i]);
        i++;
    }
  }printf("\n");
}

int main()
{
    printf("~~~~~Hello,Welcome to queue operations~~~~~\n");
    int choice;
    printf("\nWhat operation do you want to do today\n");
    while(1)
    {
        printf("\n1.enqueue\n2.dequeue\n3.peek\n4.isempty\n5.isfull\n6.display\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:en();break;
            case 2:de();break;
            case 3:peek();break;
            case 4:isem();break;
            case 5:isfull();break;
            case 6:display();break;
            default :printf("INVALID CHOICE\n");
        }
        
    }
return 0;
}