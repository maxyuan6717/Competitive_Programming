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

int N;
map<string,int> indx;
map<int,string> rindx;
vector<int> adj[100];
int indeg[100];

void topologicalSort() {
	priority_queue<int,vector<int>,greater<int> > zero;
	for (int i = 0; i < N; i++) {
		if (indeg[i] == 0) zero.push(i);
	}
	while (!zero.empty()) {
		int b = zero.top();
		zero.pop();
		for (int i = 0; i < adj[b].size(); i++) {
			int nb = adj[b][i];
			indeg[nb]--;
			if (indeg[nb] == 0) zero.push(nb);
		}
		cout << " " << rindx[b];
	}
}

int main() {
	int caseNum = 1;
	while (cin >> N) {
		indx.clear();
		rindx.clear();
		for (int i = 0; i < N; i++) {
			indeg[i] = 0;
			adj[i].clear();
		}
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			indx[s] = i;
			rindx[i] = s;
		}
		int M;
		cin >> M;
		for (int i = 0; i < M; i++) {
			string s1,s2;
			cin >> s1 >> s2;
			int i1 = indx[s1];
			int i2 = indx[s2];
			indeg[i2]++;
			adj[i1].push_back(i2);
		}
		cout << "Case #" << caseNum << ": Dilbert should drink beverages in this order:";
		caseNum++;
		topologicalSort();
		cout << "." << endl << endl;
	}
    
    return 0;
}
