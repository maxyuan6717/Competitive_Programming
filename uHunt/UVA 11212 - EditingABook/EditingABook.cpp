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
	vector<int> v;
	int d;
};

struct visited {
	bool v;
	int d;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,t;
vector<int> books;
vector<int> final;
map<vector<int>,visited> vis[2];

int bfs(vector<int> start) {
	t = 0;
	if (start == final) t = 1;
	vis[t][start].v = 1;
	queue<state> q;
	state s = {start,0};
	q.push(s);
	while (!q.empty()) {
		s = q.front();
		q.pop();
		if (s.v == final && !t) return s.d;
		vector<int> v = s.v;
		/*for (int i = 0; i < N; i++) cout << v[i] << " ";
		cout << s.d << endl;*/
		int dis = s.d;
		if (dis >= 2) continue;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				vector<int> sub (v.begin()+i, v.begin()+j);
				vector<int> temp = v;
				temp.erase(temp.begin() + i, temp.begin()+j);
				for (int p = 0; p < temp.size(); p++) {
					temp.insert(temp.begin()+p,sub.begin(),sub.end());
					if (vis[t][temp].v) {
						temp.erase(temp.begin()+p,temp.begin() + p + sub.size());
						continue;
					}
					if (t && vis[0][temp].v) {
						return dis + 1 + vis[0][temp].d;
					}
					vis[t][temp].v = 1;
					vis[t][temp].d = dis + 1;
					state add = {temp,dis+1};
					q.push(add);
					temp.erase(temp.begin()+p,temp.begin() + p + sub.size());
				}
				if (i != N-1) {
					for (int k = 0; k < sub.size(); k++) temp.push_back(sub[k]);
					if (vis[t][temp].v) continue;
					if (t && vis[0][temp].v) {
						return dis + 1 + vis[0][temp].d;
					}
					vis[t][temp].v = 1;
					vis[t][temp].d = dis + 1;
					state add = {temp,dis+1};
					q.push(add);
				}
			}
		}
	}
	return -1;
}

int main() {
	int caseNum = 1;
	while (cin >> N, N) {
		books.resize(N);
		final.resize(N);
		vis[0].clear();
		vis[1].clear();
		for (int i = 0; i < N; i++) {
			cin >> books[i];
			final[i] = i+1;
		}
		if (books == final) {
			cout << "Case " << caseNum++ << ": " << 0 << endl;
			continue;
		}
		int ans = -1;
		ans = bfs(books);
		if (ans != -1) {
			cout << "Case " << caseNum++ << ": " << ans << endl;
			continue;
		}
		ans = bfs(final);
		if (ans != -1) {
			cout << "Case " << caseNum++ << ": " << ans << endl;
			continue;
		}
		cout << "Case " << caseNum++ << ": " << 5 << endl;
	}
    return 0;
}
