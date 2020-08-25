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

struct state {
	int a,b;
	vector<string> seq;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int A,B,N;
string steps[6] = {"fill A","fill B","empty A","empty B","pour A B","pour B A"};
map<pii,bool> used;

vector<string> bfs() {
	state start;
	start.a = 0, start.b = 0, start.seq.clear();
	pii p = mp(0,0);
	used[p] = 1;
	queue<state> q;
	q.push(start);
	while (!q.empty()) {
		state s = q.front();
		q.pop();
		if (s.b == N) return s.seq;
		for (int i = 0; i < 6; i++) {
			state v = s;
			if (i == 0) {
				v.a = A;
			}
			else if (i == 1) {
				v.b = B;
			}
			else if (i == 2) {
				v.a = 0;
			}
			else if (i == 3) {
				v.b = 0;
			}
			else if (i == 4) {
				int add = min(v.a,B-v.b);
				v.a -= add;
				v.b += add;
			}
			else if (i == 5) {
				int add = min(v.b,A-v.a);
				v.a += add;
				v.b -= add;
			}
			p = mp(v.a,v.b);
			if (used[p]) continue;
			used[p] = 1;
			v.seq.push_back(steps[i]);
			q.push(v);
		}
	}
	vector<string> v;
	return v;
}

int main() {
	while (cin >> A >> B >> N) {
		used.clear();
		vector<string> ans = bfs();
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
		cout << "success" << endl;
	}
    return 0;
}
