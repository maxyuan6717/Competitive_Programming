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

#define LARGE 100000
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M,H,b,p;
bool isExit[101];
double dis[101][101];

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M >> H;
		for (int i = 1; i <= N; i++) {
			isExit[i] = 0;
			for (int j = 1; j <= N; j++) {
				dis[i][j] = LARGE;
			}
		}
		for (int i = 0; i < M; i++) {
			int u,v,l;
			cin >> u >> v >> l;
			dis[u][v] = dis[v][u] = l;
		}
		for (int i = 0; i < H; i++) {
			int u;
			cin >> u;
			isExit[u] = 1;
		}
		cin >> b >> p;
		for (int k = 1; k <= N; k++)
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);


	}
    return 0;
}
