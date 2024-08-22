>>#include <iostream>
using namespace std;
#define n 5

int queue[n];
int front = -1, rear = -1;

void Enqueue_at_beginning() {
    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        cout << "Queue is full" << endl;
    } else if (front == -1) { // Initially empty
        front = rear = 0;
        cout << "Enter the data: ";
        cin >> queue[front];
    } else if (front == 0) {
        front = n - 1;
        cout << "Enter the data: ";
        cin >> queue[front];
    } else {
        front--;
        cout << "Enter the data: ";
        cin >> queue[front];
    }
}

void Enqueue_at_End() {
    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        cout << "Queue is full" << endl;
    } else if (rear == -1) { // Initially empty
        front = rear = 0;
        cout << "Enter the data: ";
        cin >> queue[rear];
    } else if (rear == n - 1) {
        rear = 0;
        cout << "Enter the data: ";
        cin >> queue[rear];
    } else {
        rear++;
        cout << "Enter the data: ";
        cin >> queue[rear];
    }
}

void Dequeue_at_beginning() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    } else if (front == rear) {
        cout << "Deleted element: " << queue[front] << endl;
        front = rear = -1;
    } else if (front == n - 1) {
        cout << "Deleted element: " << queue[front] << endl;
        front = 0;
    } else {
        cout << "Deleted element: " << queue[front] << endl;
        front++;
    }
}

void Dequeue_at_End() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    } else if (front == rear) {
        cout << "Deleted element: " << queue[rear] << endl;
        front = rear = -1;
    } else if (rear == 0) {
        cout << "Deleted element: " << queue[rear] << endl;
        rear = n - 1;
    } else {
        cout << "Deleted element: " << queue[rear] << endl;
        rear--;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }

    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << "\t";
        }
    } else {
        for (int i = front; i < n; i++) {
            cout << queue[i] << "\t";
        }
        for (int i = 0; i <= rear; i++) {
            cout << queue[i] << "\t";
        }
    }
    cout << endl;
}

int main() {
    int choice;
    while (1) {
        cout << "\n1. Enqueue at beginning \n2. Enqueue at End\n3. Dequeue at beginning\n4. Dequeue at End\n5. Display queue\n6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: Enqueue_at_beginning(); break;
            case 2: Enqueue_at_End(); break;
            case 3: Dequeue_at_beginning(); break;
            case 4: Dequeue_at_End(); break;
            case 5: display(); break;
            case 6: exit(0); break;
            default: cout << "INVALID CHOICE" << endl;
        }
    }
    return 0;
}
