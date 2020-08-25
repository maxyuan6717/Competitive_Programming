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

struct gas {
	double dis,cost;
};

double dist,cap,mpg,origCost;
int N;
double ans = LARGE;
gas stations[53];

void rec(int cur, double curCost, double curGas) {
	double gasNeeded = (stations[cur+1].dis - stations[cur].dis)/mpg;
	if (cur == N) {
		if (curGas < gasNeeded) {
			curCost += round((cap-curGas) * stations[cur].cost) + 200.0;
		}
		ans = min(ans,curCost);
		return;
	}
	if (curGas < gasNeeded) {
		curCost += round((cap-curGas) * stations[cur].cost) + 200.0;
		rec(cur+1,curCost,cap-gasNeeded);
	}
	else if (curGas > cap/2 && curGas >= gasNeeded) {
		rec(cur+1,curCost,curGas-gasNeeded);
	}
	else {
		rec(cur+1,curCost,curGas-gasNeeded);
		curCost += round((cap-curGas) * stations[cur].cost) + 200.0;
		rec(cur+1,curCost,cap-gasNeeded);
	}

}

int main() {
	int caseNum = 1;
	while (scanf("%lf",&dist), dist != -1) {
		scanf("%lf %lf %lf %d",&cap,&mpg,&origCost,&N);
		stations[0].dis = 0, stations[0].cost = origCost;
		stations[N+1].dis = dist, stations[N+1].cost = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%lf %lf",&stations[i].dis,&stations[i].cost);
		}
		ans = LARGE;
		rec(1,origCost*100.0,cap-(stations[1].dis/mpg));
		printf("Data Set #%d\n",caseNum++);
		//cout << ans << endl;
		printf("minimum cost = $%.2lf\n", ans / 100.0);
	}
    return 0;
}
