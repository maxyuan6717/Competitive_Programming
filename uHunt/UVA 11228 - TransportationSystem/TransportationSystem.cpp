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
#define mp make_pair

using namespace std;

struct city {
	int x, y;
};

typedef pair<double,int> pii;

vector<city> cities;
double dis[1000][1000];

double dist(city a, city b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N,r;
		cin >> N >> r;
		cities.clear();
		for (int i = 0; i < N; i++) {
			city c;
			cin >> c.x >> c.y;
			cities.push_back(c);
		}
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < i; j++) {
				dis[i][j] = dist(cities[i],cities[j]);
				dis[j][i] = dis[i][j];
			}
		}
		int ans1 = 1;
		double ans2 = 0,ans3 = 0;
		priority_queue<pii,vector<pii>,greater<pii> > pq;
		double key[N];
		int p[N];
		bool used[N];
		double dis2[N][N];
		for (int i = 0; i < N; i++) {
			key[i] = 100000000;
			p[i] = -1;
			used[i] = 0;
			for (int j = 0; j < N; j++) dis2[i][j] = 0;
		}
		pq.push(mp(0,0));
		key[0] = 0;
		while (!pq.empty()) {
			int v = pq.top().second;
			pq.pop();
			used[v] = 1;
			for (int i = 0; i < N; i++) {
				int newv = i;
				double newc = dis[v][newv];
				if (!used[newv] && newc < key[newv]) {
					key[newv] = newc;
					pq.push(mp(newc,newv));
					p[newv] = v;
					dis2[v][newv] = newc;
				}
			}
		}
		for (int i = 1; i < N; i++) {
			double d = dis2[p[i]][i];
			if (d > r) ans1++,ans3 += d;
			else ans2+=d;
		}
		cout << "Case #" << t << ": " << ans1 << " " << round(ans2) << " " << round(ans3) << endl;
	}
    return 0;
}
