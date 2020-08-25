#include <iostream>
#include <sstream>
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

struct edge {
	int s,d,c;
};

int N,M;
vector<edge> edges;
int p[200000];

bool compare (edge a, edge b) {
	return a.c < b.c;
}

int find(int u) {
	if (p[u] == u) return u;
	else return p[u] = find(p[u]);
}

bool inSameSet(int u, int v) {
	return find(u) == find(v);
}

void unionSet(int u, int v) {
	p[find(u)] = find(v);
}

int main() {
	int caseNum = 0;
	while (cin >> N) {
		cin.ignore();
		edges.clear();
		if (caseNum) cout << endl;
		caseNum++;
		for (int i = 1; i <= N; i++) {
			p[i] = i;
		}
		int K;
		long long ans1 = 0;
		while (1) {
			int counter = 0;
			string s;
			getline(cin,s);
			stringstream ss(s);
			int arr[3];
			while (ss >> arr[counter]) {
				counter++;
			}
			if (counter == 1) {
				K = arr[0];
				break;
			}
			else {
				ans1 += arr[2];
			}
		}
		for (int i = 0; i < K; i++) {
			int x,y,z;
			cin >> x >> y >> z;
			edge e = {x,y,z};
			edges.push_back(e);
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			int x,y,z;
			cin >> x >> y >> z;
			edge e1 = {x,y,z};
			edges.push_back(e1);
		}
		sort(edges.begin(),edges.end(),compare);
		long long ans2 = 0;
		for (int i = 0; i < edges.size(); i++) {
			edge e = edges[i];
			if (inSameSet(e.s,e.d)) continue;
			unionSet(e.s,e.d);
			ans2 += e.c;
		}
		cout << ans1 << endl << ans2 << endl;
	}
    return 0;
}
