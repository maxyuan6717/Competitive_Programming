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
#include <bitset>

#define LARGE (1<<31)-1

using namespace std;

int parent[10001];
int ranks[10001];
int owe[10001];
int sum[10001];

int findroot(int x) {
	if (parent[x] != x) {
		parent[x] = findroot(parent[x]);
	}
	return parent[x];
}

void Union(int x, int y) {
	int xroot = findroot(x);
	int yroot = findroot(y);
	if (xroot == yroot) return;
	if (ranks[xroot] < ranks[yroot]) {
		parent[xroot] = yroot;
	}
	else {
		parent[yroot] = xroot;
	}
}

string ansstr[2] = {"POSSIBLE","IMPOSSIBLE"};

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
    	int n,m;
    	cin >> n >> m;
    	set<int> friends;
    	for (int i = 0; i < n; i++) {
    		parent[i] =i;
    		ranks[i] = 0;
    		sum[i] = 0;
    	}
    	for (int i = 0; i < n; i++) {
    		cin >> owe[i];
    	}
    	for (int i = 0; i < m; i++) {
    		int f1,f2;
    		cin >> f1 >> f2;
    		Union(f1,f2);
    	}
    	for (int i = 0; i < n; i++) {
    		sum[findroot(i)] += owe[i];
    	}
    	int ans = 0;
    	for (int i = 0; i < n; i++) {
    		if (sum[i]) {
    			ans = 1;
    			break;
    		}
    	}
    	cout << ansstr[ans] << endl;
    }
    return 0;
}
