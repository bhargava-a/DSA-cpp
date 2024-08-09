#include <stdio.h>

#define n 5

int sta[n];
int top = -1;

void push() {
    if (top == (n - 1)) {
        printf("Stack overflow\n");
    } else {
        top++;
        printf("Enter the number to be inserted : ");
        scanf("%d", &sta[top]);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("The popped element is : %d\n", sta[top]);
        top--;
    }
}

void ispeek() {
    if (top == -1) {
        printf("Stack empty\n");
    } else {
        printf("The top element is : %d\n", sta[top]);
    }
}

void isem() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
}

void isfull() {
    if (top == (n - 1)) {
        printf("Stack is full\n");
    } else {
        printf("Stack is not full\n");
    }
}

void display(){
    if(top==-1){
        printf("Cannot display because stack is empty\n");
    }else{
    for(int i = top; i>=0 ; i--) {
        printf("%d\t",sta[i]);
    }
  }
}
int main() {
    int choice;
  
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Is Peek\n4. Is Empty\n5. Is Full\n6.display\n7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:push(); break;
            case 2:pop(); break;
            case 3:ispeek(); break;
            case 4:isem(); break;
            case 5:isfull(); break;
            case 6:display(); break;
            case 7:exit(0);break;
            default:printf("INVALID CHOICE\n");
        }
    }
    return 0;
}
