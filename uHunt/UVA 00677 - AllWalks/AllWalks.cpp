#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
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
#include <iomanip>
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,len;
vector<int> adj[10];
bool vis[10];
bool works = 0;

void rec(int cur, int curLen, vector<int> seq) {
	seq.push_back(cur);
	if (curLen == len) {
		cout << "(";
		for (int i = 0; i < seq.size(); i++) {
			cout << seq[i] + 1;
			if (i != seq.size()-1) cout << ",";
		}
		cout << ")" << endl;
		works = 1;
		return;
	}
	for (int i = 0; i < adj[cur].size(); i++) {
		int v = adj[cur][i];
		if (vis[v]) continue;
		vis[v] = 1;
		rec(v,curLen+1,seq);
		vis[v] = 0;
	}
}

int main() {
	int caseNum = 0;
	do {
		if (caseNum++) cout << endl;
		cin >> N >> len;
		for (int i = 0; i < N; i++) {
			adj[i].clear();
			vis[i] = 0;
			for (int j = 0; j < N; j++) {
				int num;
				cin >> num;
				if (num) adj[i].push_back(j);
			}
		}
		works = 0;
		vector<int> v;
		vis[0] = 1;
		rec(0,0,v);
		if (!works) cout << "no walk of length " << len << endl;
	} while (cin >> N);
    return 0;
}
