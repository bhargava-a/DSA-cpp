#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* parent;
    node* right;
    string color;
};

node* root = NULL;
node* NIL = new node();

// Initialize the NIL node
void init_NIL() {
    NIL->color = "black";
    NIL->left = NIL;
    NIL->right = NIL;
    NIL->parent = NULL;
}

// Function to create a new node
node* create() {
    node* newnode = new node();
    cout << "Enter data: ";
    cin >> newnode->data;
    newnode->color = "red";
    newnode->left = NIL;
    newnode->right = NIL;
    newnode->parent = NULL;
    return newnode;
}

// Left rotation
void left_rotation(node*& root, node* x) {
    node* y = x->right;
    x->right = y->left;
    if (y->left != NIL) {
        y->left->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

// Right rotation
void right_rotation(node*& root, node* y) {
    node* x = y->left;
    y->left = x->right;
    if (x->right != NIL) {
        x->right->parent = y;
    }
    x->parent = y->parent;

    if (y->parent == NULL) {
        root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }

    x->right = y;
    y->parent = x;
}

// Fix Red-Black Tree after insertion
void fixInsert(node*& root, node* newnode) {
    while (newnode->parent != NULL && newnode->parent->color == "red") {
        if (newnode->parent == newnode->parent->parent->left) {
            node* uncle = newnode->parent->parent->right;

            if (uncle->color == "red") {  // Case 1: Uncle is red
                newnode->parent->color = "black";
                uncle->color = "black";
                newnode->parent->parent->color = "red";
                newnode = newnode->parent->parent;
            } else {  // Case 2 and 3: Uncle is black
                if (newnode == newnode->parent->right) {
                    newnode = newnode->parent;
                    left_rotation(root, newnode);
                }
                newnode->parent->color = "black";
                newnode->parent->parent->color = "red";
                right_rotation(root, newnode->parent->parent);
            }
        } else {  // Symmetric case: Parent is the right child
            node* uncle = newnode->parent->parent->left;
            if (uncle->color == "red") {
                newnode->parent->color = "black";
                uncle->color = "black";
                newnode->parent->parent->color = "red";
                newnode = newnode->parent->parent;
            } else {
                if (newnode == newnode->parent->left) {
                    newnode = newnode->parent;
                    right_rotation(root, newnode);
                }
                newnode->parent->color = "black";
                newnode->parent->parent->color = "red";
                left_rotation(root, newnode->parent->parent);
            }
        }
    }
    root->color = "black";
}

// Insert a node into the Red-Black Tree
node* insert(node* root, node* newnode) {
    node* y = NIL;
    node* x = root;

    while (x != NIL) {
        y = x;
        if (newnode->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    newnode->parent = y;
    if (y == NIL) {
        root = newnode;
    } else if (newnode->data < y->data) {
        y->left = newnode;
    } else {
        y->right = newnode;
    }

    fixInsert(root, newnode);
    return root;
}

// Print preorder traversal
void preorder(node* root) {
    if (root != NIL) {
        cout << root->data << "\t";
        preorder(root->left);
        preorder(root->right);
    }
}

// Print inorder traversal
void inorder(node* root) {
    if (root != NIL) {
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}

// Print postorder traversal
void postorder(node* root) {
    if (root != NIL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "\t";
    }
}

// Search for a node in the Red-Black Tree
node* search(node* root, int key) {
    if (root == NIL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Fix the Red-Black Tree after deletion
void fixDelete(node*& root, node* x) {
    while (x != root && x->color == "black") {
        if (x == x->parent->left) {
            node* sibling = x->parent->right;
            if (sibling->color == "red") {
                sibling->color = "black";
                x->parent->color = "red";
                left_rotation(root, x->parent);
                sibling = x->parent->right;
            }
            if (sibling->left->color == "black" && sibling->right->color == "black") {
                sibling->color = "red";
                x = x->parent;
            } else {
                if (sibling->right->color == "black") {
                    sibling->left->color = "black";
                    sibling->color = "red";
                    right_rotation(root, sibling);
                    sibling = x->parent->right;
                }
                sibling->color = x->parent->color;
                x->parent->color = "black";
                sibling->right->color = "black";
                left_rotation(root, x->parent);
                x = root;
            }
        } else {
            node* sibling = x->parent->left;
            if (sibling->color == "red") {
                sibling->color = "black";
                x->parent->color = "red";
                right_rotation(root, x->parent);
                sibling = x->parent->left;
            }
            if (sibling->left->color == "black" && sibling->right->color == "black") {
                sibling->color = "red";
                x = x->parent;
            } else {
                if (sibling->left->color == "black") {
                    sibling->right->color = "black";
                    sibling->color = "red";
                    left_rotation(root, sibling);
                    sibling = x->parent->left;
                }
                sibling->color = x->parent->color;
                x->parent->color = "black";
                sibling->left->color = "black";
                right_rotation(root, x->parent);
                x = root;
            }
        }
    }
    x->color = "black";
}

// Transplant subtrees during deletion
void rbTransplant(node*& root, node* u, node* v) {
    if (u->parent == NULL) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

// Find the minimum node in the right subtree
node* findmin(node* root) {
    while (root->left != NIL) {
        root = root->left;
    }
    return root;
}

// Delete a node from the Red-Black Tree
void rbDelete(node*& root, node* z) {
    node* y = z;
    string yOriginalColor = y->color;
    node* x;

    if (z->left == NIL) {
        x = z->right;
        rbTransplant(root, z, z->right);
    } else if (z->right == NIL) {
        x = z->left;
        rbTransplant(root, z, z->left);
    } else {
        y = findmin(z->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            rbTransplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rbTransplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (yOriginalColor == "black") {
        fixDelete(root, x);
    }
}

int main() {
    int ch;
    node* temp;
    init_NIL();

    do {
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Preorder\n5.Inorder\n6.Postorder\n0.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                temp = create();
                root = insert(root, temp);
                break;
            case 2:
                int key;
                cout << "Enter key to search: ";
                cin >> key;
                temp = search(root, key);
                if (temp != NIL) {
                    cout << "Element found: " << temp->data << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                temp = search(root, key);
                if (temp != NIL) {
                    rbDelete(root, temp);
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            case 4:
                cout << "Preorder traversal: \n";
                preorder(root);
                break;
            case 5:
                cout << "Inorder traversal: \n";
                inorder(root);
                break;
            case 6:
                cout << "Postorder traversal: \n";
                postorder(root);
                break;
        }
    } while (ch != 0);

    return 0;
}
