/*
 ID: yuanmax1
 PROG: adjacency list
 LANG: C++
 */
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

#define LARGE 9999999

using namespace std;

struct node {
    int val;
    node* next;
    node* pre;
};

node* root = NULL;

node* getNode(int data) {
    node* newNode = new node();
    newNode->val = data;
    newNode->next = NULL;
    newNode->pre = NULL;
    return newNode;
}

node* insert(node* root, int data) {
    if (root == NULL) {
        root = getNode(data);
        return root;
    }
    else {
        node* temp = root;
        root = getNode(data);
        root->next = temp;
        temp->pre = root;
        return root;
    }
    
    return root;
}

node* deleteNode(node* cur, int data) {
    
    return cur;
}

int main() {
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,3);
    
    return 0;
}