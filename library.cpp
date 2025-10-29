#include <iostream>
using namespace std;

struct Node {
    int val;
    int c;
    Node* right;
    Node* left;
    Node () {
        right = nullptr;
        left = nullptr;
        c = 0;
        val = 0;
    }
    Node (int n) {
        right = nullptr;
        left = nullptr;
        c = 0;
        val = n;
    }
    Node (Node* a) {
        right = nullptr;
        left = nullptr;
        c = 1;
        val = a->val;
    }
    Node (Node &a) {
        right = a.right;
        left = a.left;
        c = 1;
        val = a.val;
    }
};

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void recursive_insert(Node* a, int n) {
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
    recursive_insert(a,n);
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

bool recursive_bynary_search(Node* a, int n) {
    if (a == nullptr) {
        return false;
    }else if (a->val == n) {
        a->c += 1;
        return true;
    }else if (a->val < n) {
        a = a->right;
    }else if (a->val > n) {
        a = a->left;
    }
    return recursive_bynary_search(a,n);
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

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main() {
    int n;
    cout << "write a number you want in the root: ";
    cin >> n;
    Node* root = new Node(n);
    return 0;
}