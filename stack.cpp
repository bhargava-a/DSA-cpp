#include <iostream>
using namespace std;

#define n 5

int sta[n];
int top = -1;

void push() {
    if (top == (n - 1)) {
        cout<<"Stack overflow"<<endl;
    } else {
        top++;
        cout<<"Enter the number to be inserted : ";
        cin>>sta[top];
    }
}

void pop() {
    if (top == -1) {
        cout<<"Stack underflow"<<endl;
    } else {
        cout<<"The popped element is : "<<sta[top]<<endl;
        top--;
    }
}

void ispeek() {
    if (top == -1) {
        cout<<"Stack empty"<<endl;
    } else {
        cout<<"The top element is : "<<sta[top]<<endl;
    }
}

void isem() {
    if (top == -1) {
        cout<<"Stack is empty"<<endl;
    } else {
        cout<<"Stack is not empty"<<endl;
    }
}

void isfull() {
    if (top == (n - 1)) {
        cout<<"Stack is full"<<endl;
    } else {
        cout<<"Stack is not full"<<endl;
    }
}

void display(){
    if(top==-1){
        cout<<"Cannot display because stack is empty"<<endl;
    }else{
    for(int i = top; i>=0 ; i--) {
        cout<<sta[i]<<"\t";
    }
  }
}
int main() {
    int choice;
  
    while (1) {
        cout<<"\n1. Push\n2. Pop\n3. Is Peek\n4. Is Empty\n5. Is Full\n6.display\n7.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:push(); break;
            case 2:pop(); break;
            case 3:ispeek(); break;
            case 4:isem(); break;
            case 5:isfull(); break;
            case 6:display(); break;
            case 7:exit(0);break;
            default:cout<<"INVALID CHOICE"<<endl;
        }
    }
    return 0;
}
