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

typedef pair<int,int> pii;
typedef vector<pii> vii;

vii adj[10001];

int main() {
	int M,N;
	while (cin >> M >> N) {
		for (int i = 0; i <= 10000; i++) adj[i].clear();
		for (int m = 1; m <= M; m++) {
			int num;
			cin >> num;
			int indx[N+1];
			int val[N+1];
			for (int i = 0; i < num; i++) {
				cin >> indx[i];
			}
			for (int i = 0; i < num; i++) {
				cin >> val[i];
				adj[indx[i]].push_back(mp(val[i],m));
			}
		}
		cout << N << " " << M << endl;
		for (int n = 1; n <= N; n++) {
			cout << adj[n].size();
			int indx[M+1];
			int val[M+1];
			for (int i = 0; i < adj[n].size(); i++) {
				indx[i] = adj[n][i].second;
				val[i] = adj[n][i].first;
				cout << " " << indx[i];
			}
			cout << endl;
			for (int i = 0; i < adj[n].size(); i++) {
				cout << val[i];
				if (i != adj[n].size()-1) cout << " ";
			}
			cout << endl;
		}
	}
    return 0;
}
