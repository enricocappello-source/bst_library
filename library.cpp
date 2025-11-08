#include <iostream>
using namespace std;

struct Node {
    int val;
    int c;
    Node* right;
    Node* left;
    Node () {                       //basic constructor
        right = nullptr;
        left = nullptr;
        c = 1;
        val = 0;
    }
    Node (int n) {                  //constructor with the int value n
        right = nullptr;
        left = nullptr;
        c = 1;
        val = n;
    }
    Node (Node* a) {                //copy constructor with ptr
        right = a->right;
        left = a->left;
        c = a->c;
        val = a->val;
    }
    Node (Node &a) {                //copy constructor without ptr
        right = a.right;
        left = a.left;
        c = a.c;
        val = a.val;
    }
};

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void recursive_insert(Node* &a, int n) {
    if (a == nullptr) {
        a = new Node(n);
        return;
    }
    if(a->val == n) {
        a->c += 1;
        return;
    }else if (a->val < n) {
        recursive_insert(a->right, n);
    }else if (a->val > n) {
        recursive_insert(a->left, n);
    }
    return;
}

void insert(Node* a, int n) {
    do {
        if (a->val == n) {
            a->c += 1;
            return;
        }else if (a->val < n) {
            a = a->right;
            if (a == nullptr) {
                a = new Node(n);
                return;
            }
        }else if (a->val > n) {
            a = a->left;
            if (a == nullptr) {
                a = new Node(n);
                return;
            }
        }
    } while (true);
}

Node* recursive_bynary_search(Node* a, int n) {
    if (a == nullptr) {
        return nullptr;
    }else if (a->val == n) {
        a->c += 1;
        return a;
    }else if (a->val < n) {
        return recursive_bynary_search(a->right,n);
    }else if (a->val > n) {
        return recursive_bynary_search(a->left,n);
    }
    return nullptr;
}

bool bynary_search(Node* a, int n) {
    while (a->left == nullptr || a->right == nullptr) {
        if (a->val == n) {
            a->c += 1;
            return true;
        }else if (a->val < n) {
            a = a->right;
            return true;
        }else if (a->val > n) {
            a = a->left;
            return true;
        }
    }
    return false;
}

void in_order(Node* root) {
    if (root == nullptr) {
        return;
    }
    in_order(root->left);
    cout << root->val << ",";
    in_order(root->right);
    return;
}

void post_order(Node* root) {
    if (root == nullptr) {
        return;
    }
    post_order(root->right);
    cout << root->val << ",";
    post_order(root->left);
    return;
}

void pre_order(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
    return;
}

int high(Node* root,int h=1) {
    if (root == nullptr) {
        return 0;
    }
    int h_left = high(root->left), h_right = high(root->right);
    if (h_left >= h_right) {
        return h_left+1;
    }else {
        return h_right+1;
    }
}

void delete_a_node(Node* root, int number) {
    Node* a = recursive_bynary_search(root, number);
    if (a->left == nullptr && a->right == nullptr) {
        delete a;
        return;
    } else if (a->left != nullptr || a->right != nullptr) {
        if (a->left != nullptr) {
            Node* ptr = a;
            a->left = a;
            a->left = ptr->left;
            delete ptr;
        } else if (a->right != nullptr) {
            Node* ptr = a;
            a->right = a;
            a->right = ptr->right;
            delete ptr;
        }
        return;
    } else if (a->left != nullptr && a->right != nullptr) {
        Node* ptr = a->right;
        while (ptr->left != nullptr) {
            ptr = ptr->left;
        }
        ptr->left = a->left;
        ptr->right = a->right;
        delete a;
        return;
    }
    return;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main() {
    int choice, n;
    Node* root = nullptr;
    bool rootCreated = false;

    while (true) {
        cout << endl << "BST Menu:" << endl;
        cout << "1. Create Root" << endl;
        cout << "2. Insert Value" << endl;
        cout << "3. Search Value" << endl;
        cout << "4. In-Order Traversal" << endl;
        cout << "5. Post-Order Traversal" << endl;
        cout << "6. Pre-Order Traversal" << endl;
        cout << "7. Get Height" << endl;
        cout << "8. delete a node" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!rootCreated) {
                    cout << "Enter value for root: ";
                    cin >> n;
                    root = new Node();
                    root->val = n;
                    rootCreated = true;
                    cout << "Root created with value " << n << endl;
                } else {
                    cout << "Root already exists." << endl;
                }
                break;
            case 2:
                if (!rootCreated) {
                    cout << "Create root first." << endl;
                } else {
                    cout << "Enter value to insert: ";
                    cin >> n;
                    recursive_insert(root, n);
                    cout << "Value " << n << " inserted." << endl;
                }
                break;
            case 3:
                if (!rootCreated) {
                    cout << "Create root first." << endl;
                } else {
                    cout << "Enter value to search: ";
                    cin >> n;
                    if (recursive_bynary_search(root, n) != nullptr) {
                        cout << "Value " << n << " found." << endl;
                    } else {
                        cout << "Value " << n << " not found." << endl;
                    }
                }
                break;
            case 4:
                if (!rootCreated) {
                    cout << "Create root first." << endl;
                } else {
                    cout << "In-Order Traversal: ";
                    in_order(root);
                    cout << endl;
                }
                break;
            case 5:
                if (!rootCreated) {
                    cout << "Create root first." << endl;
                } else {
                    cout << "Post-Order Traversal: ";
                    post_order(root);
                    cout << endl;
                }
                break;
            case 6:
                if (!rootCreated) {
                    cout << "Create root first." << endl;
                } else {
                    cout << "Pre-Order Traversal: ";
                    pre_order(root);
                    cout << endl;
                }
                break;
            case 7:
                if (!rootCreated) {
                    cout << "Create root first." << endl;
                } else {
                    cout << "Height of tree: " << high(root) << endl;
                }
                break;
            case 8:
                if (!rootCreated) {
                    cout << "Create root first." << endl;
                } else {
                    cout << "Enter value to delete: ";
                    cin >> n;
                    delete_a_node(root, n);
                    cout << "The node is deleted successful" << endl;
                }
                break;
            case 9:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}
