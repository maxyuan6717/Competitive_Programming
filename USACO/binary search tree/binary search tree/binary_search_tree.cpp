#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

node* root = NULL;

node* minNode(node* cur) {
    if (cur->left == NULL) return cur;
    else return minNode(cur->left);
    return cur;
}

node* maxNode(node* cur) {
    if (cur->right == NULL) return cur;
    else return maxNode(cur->right);
    return cur;
}

node* getNode(int data) {
    node* newNode = new node();
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert(node* cur, int data) {
    if (cur == NULL) {
        cur = getNode(data);
        return cur;
    }
    else if (data < cur->val) {
        cur->left = insert(cur->left,data);
        return cur;
    }
    else {
        cur->right = insert(cur->right,data);
        return cur;
    }
    return cur;
}

node* deleteNode (node* cur, int data) {
    if (cur == NULL) return cur;
    else if (data < cur-> val) cur->left = deleteNode(cur->left,data);
    else if (data > cur->val) cur->right = deleteNode(cur->right,data);
    else if (data == cur-> val) {
        if (cur->left == NULL & cur->right == NULL) {
            delete cur;
            cur = NULL;
            return cur;
        }
        else if (cur->left == NULL) {
            node* temp = cur;
            cur = cur->right;
            delete temp;
            return cur;
        }
        else if (cur->right == NULL) {
            node* temp = cur;
            cur = cur->left;
            delete temp;
            return cur;
        }
        else {
            node* temp = minNode(cur->right);
            cur->val = temp->val;
            cur->right = deleteNode(cur->right,temp->val);
        }
    }
    return cur;
}

int search (node* cur, int data) {
    if (cur == NULL) return 0;
    else if (cur->val == data) return 1;
    else if (data < cur->val) {
        return search(cur->left,data);
    }
    else return search(cur->right,data);
    return 1;
}

void preorder(node* cur) {
    if (cur == NULL) return;
    cout << cur->val << " ";
    preorder(cur->left);
    preorder(cur->right);
}

void inorder (node* cur) {
    if (cur == NULL) return;
    inorder(cur->left);
    cout << cur->val << " ";
    inorder(cur->right);
}

void postorder (node* cur) {
    if (cur == NULL) return;
    postorder(cur->left);
    postorder(cur->right);
    cout << cur->val << " ";
}

int main() {
    root = insert(root,4);
    root = insert(root,6);
    root = insert(root,7);
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,8);
    root = insert(root,3);
    root = insert(root,9);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    
    
    return 0;
}