#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

Node* searchNode(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchNode(root->left, key);
    
    return searchNode(root->right, key);
}

Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\n--- Binary Search Tree Menu ---";
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display (Inorder)\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insertNode(root, value);
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchNode(root, value))
                    cout << "Found!" << endl;
                else
                    cout << "Not Found!" << endl;
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;

            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
