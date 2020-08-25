/*
ID: yuanmax1
PROG: heritage
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>

using namespace std;
string ino;
string preo;
string ans = "";
int counter = 0;

int find(char c, int s, int e) {
	for (int i = s; i <= e; i++) {
		if (ino[i] == c) return i;
	}
	return 10;
}

struct node {
	char val;
	struct node *left;
	struct node *right;
};

node *newnode (char c) {
	node *newn = new node;
	newn -> val = c;
	newn -> left = NULL;
	newn -> right = NULL;
	return newn;
}

node *make (int inos, int inoe) {
	static int index = 0;
	if (inos > inoe) return NULL;
	node *tree = newnode(preo[index++]);
	if (inos == inoe) return tree;
	int index2 = find(tree->val,inos,inoe);
	tree -> left = make(inos,index2-1);
	tree -> right = make(index2+1,inoe);
	return tree;
}

void post(node *curnode) {
	//cout << curnode -> val << endl;
	if (curnode) {
		post (curnode -> left);
		post (curnode -> right);
		//cout << curnode -> val;
		ans += curnode -> val;
	}
	else return;
	
}

int main() {
    ofstream fout ("heritage.out");
    ifstream fin ("heritage.in");
    fin >> ino >> preo;
    node *root = make(0,ino.size()-1);
    //cout << root -> val << endl;
    post(root);
    fout << ans << endl;
    
    
    return 0;
}