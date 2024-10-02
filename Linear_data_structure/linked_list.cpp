#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class LL {
private:
    node* head, * temp, * newnode;

public:
    // Constructor (now public)
    LL() {
        head = nullptr;
    }

    // Display the linked list
    void dis() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }

    // Get the length of the list
    int len() {
        int length = 0;
        temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            length++;
        }
        return length;
    }

    // Insert a node at the beginning
    void insert_at_begin(int data) {
        newnode = new node();
        newnode->data = data;
        newnode->next = head;
        head = newnode;
        dis();
    }

    // Insert a node at the end
    void insert_at_end(int data) {
        newnode = new node();
        newnode->data = data;
        newnode->next = nullptr;
        if (head == nullptr) {
            head = newnode;
        }
        else {
            temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        dis();
    }

    // Insert a node at a specific location
    void insert_at_loc(int pos, int data) {
        int length = len();
        if (pos > length + 1 || pos < 1) {
            cout << "Invalid position" << endl;
            return;
        }

        newnode = new node();
        newnode->data = data;

        if (pos == 1) {
            newnode->next = head;
            head = newnode;
        }
        else {
            temp = head;
            int i = 1;
            while (i < pos - 1 && temp != nullptr) {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        dis();
    }

    // Delete the node at the beginning
    void delete_at_begin() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        temp = head;
        cout << "Deleted node is: " << head->data << endl;
        head = head->next;
        delete temp;
        dis();
    }

    // Delete the node at the end
    void delete_at_end() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == nullptr) {
            cout << "Deleted node is: " << head->data << endl;
            delete head;
            head = nullptr;
        }
        else {
            temp = head;
            node* prev = nullptr;
            while (temp->next != nullptr) {
                prev = temp;
                temp = temp->next;
            }
            cout << "Deleted node is: " << temp->data << endl;
            prev->next = nullptr;
            delete temp;
        }
        dis();
    }

    // Delete the node at a specific location
    void delete_at_loc(int pos) {
        int length = len();
        if (pos > length || pos < 1) {
            cout << "Invalid position" << endl;
            return;
        }
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (pos == 1) {
            delete_at_begin();
        }
        else {
            temp = head;
            int i = 1;
            while (i < pos - 1) {
                temp = temp->next;
                i++;
            }
            node* kill = temp->next;
            temp->next = kill->next;
            cout << "Deleted node is: " << kill->data << endl;
            delete kill;
            dis();
        }
    }

    // Reverse the linked list
    void rev() {
        node* prev = nullptr, * current = head, * nextnode;
        while (current != nullptr) {
            nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
        }
        head = prev;
        dis();
    }

    // Wrapper functions for public access
    void insertAtbegin(int data) { insert_at_begin(data); }
    void insertAtlast(int data) { insert_at_end(data); }
    void insertAtloc(int pos, int data) { insert_at_loc(pos, data); }
    void deleteAtbegin() { delete_at_begin(); }
    void deleteAtlast() { delete_at_end(); }
    void deleteAtloc(int pos) { delete_at_loc(pos); }
    void reverse() { rev(); }
    void display() { dis(); }
};

int main() {
    int choice;
    LL linked_list;

    while (1) {
        cout << "\n\n1. Insert at beginning\n2. Insert at end\n3. Insert at specific location"
             << "\n4. Delete at beginning\n5. Delete at end\n6. Delete at specific location"
             << "\n7. Display\n8. Reverse\n9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int x;
                cout << "Enter a value: ";
                cin >> x;
                linked_list.insertAtbegin(x);
                break;
            }
            case 2: {
                int x;
                cout << "Enter a value: ";
                cin >> x;
                linked_list.insertAtlast(x);
                break;
            }
            case 3: {
                int x, position;
                cout << "Enter the position: ";
                cin >> position;
                cout << "Enter a value: ";
                cin >> x;
                linked_list.insertAtloc(position, x);
                break;
            }
            case 4:
                linked_list.deleteAtbegin();
                break;
            case 5:
                linked_list.deleteAtlast();
                break;
            case 6: {
                int loca;
                cout << "Enter the location: ";
                cin >> loca;
                linked_list.deleteAtloc(loca);
                break;
            }
            case 7:
                linked_list.display();
                break;
            case 8:
                linked_list.reverse();
                break;
            case 9:
                exit(0);
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
