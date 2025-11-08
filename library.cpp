#include <iostream>
using namespace std;

struct Node {
    int val;
    int c;
    Node* right;
    Node* left;
    int lvl;
    Node () {
        right = nullptr;
        left = nullptr;
        c = 0;
        val = 0;
        lvl = 1;
    }
    Node (int n, Node* root) {
        right = nullptr;
        left = nullptr;
        c = 0;
        val = n;
        lvl = root->lvl+1;
    }
    Node (Node* a) {
        right = nullptr;
        left = nullptr;
        c = 1;
        val = a->val;
        lvl = a->lvl+1;
    }
    Node (Node &a) {
        right = a.right;
        left = a.left;
        c = 1;
        val = a.val;
        lvl = a.lvl+1;
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
            a = new Node(n, a);
            return;
        }
    }else if (a->val > n) {
        a = a->left;
        if (a == nullptr) {
            a = new Node(n, a);
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
                a = new Node(n, a);
                return;
            }
        }else if (a->val > n) {
            a = a->left;
            if (a == nullptr) {
                a = new Node(n, a);
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

void in_order(Node* root) {
    if (root->lvl == 1) {
        cout << root->val << ",";
    } 
    if (root->left == nullptr) {
        cout << root->val << ",";
        return;
    }
    in_order(root->left);
    if (root->right == nullptr) {
        cout << root->val << ",";
        return;
    }
    in_order(root->right);
    return;
}

void post_order(Node* root) {
    if (root->lvl == 1) {
        cout << root->val << ",";
    } 
    if (root->right == nullptr) {
        cout << root->val << ",";
        return;
    }
    post_order(root->right);
    if (root->left == nullptr) {
        cout << root->val << ",";
        return;
    }
    post_order(root->left);
    return;
}

void preorder() {

}

int high(Node* root) {
    return root->lvl;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main() {
    int n;
    cout << "write a number you want in the root: ";
    cin >> n;
    Node* root = new Node(n, root);
    return 0;
}