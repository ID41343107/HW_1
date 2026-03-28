#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int x) {
    if (!root) return new Node{x, nullptr, nullptr};
    if (x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* del(Node* root, int k) {
    if (!root) return nullptr;
    if (k < root->data)
        root->left = del(root->left, k);
    else if (k > root->data)
        root->right = del(root->right, k);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        Node* m = findMin(root->right);
        root->data = m->data;
        root->right = del(root->right, m->data);
    }
    return root;
}

void in(Node* root) {
    if (root) {
        in(root->left);
        cout << root->data << " ";
        in(root->right);
    }
}

int main() {
    int a[] = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    for (int n : a) {
        Node* root = nullptr;
        for (int i = 0; i < n; i++)
            root = insert(root, rand());
        cout << n << " " << height(root) / log2(n) << endl;
    }

    Node* root = nullptr;
    int b[] = {50,30,70,20,40,60,80,100,10,120,90,110};
    for (int x : b)
        root = insert(root, x);
    in(root); cout << endl;
    root = del(root, 50);
    in(root); cout << endl;
}
