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

struct cfs {
	int v,start,dur;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

vector<cfs> systems[10000];
int t;

int backtrack(int cnt, int start, int time, int cur) {
	if (cur == start && cnt) return 9999;
	for (int i = 0; i < systems[cur].size(); i++) {
		cfs c = systems[cur][i];
		if (time >= c.start && time <= c.start + c.dur) return backtrack(cnt+1,start,time,c.v);
	}
	return cur;
}

int main() {
	int T,start,dur;
	int src,dest;
	scanf("%d",&T);
	printf("CALL FORWARDING OUTPUT\n");
	for (t = 1; t <= T; t++) {
		printf("SYSTEM %d\n",t);
		for (int i = 1; i < 10000; i++) systems[i].clear();
		while (scanf("%d",&src),src) {
			scanf("%d %d %d",&start,&dur,&dest);
			cfs c = {dest,start,dur};
			systems[src].push_back(c);
		}
		int time;
		int call;
		while (scanf("%d", &time), time != 9000) {
			scanf("%d",&call);
			printf("AT %04d CALL TO %04d RINGS %04d\n",time,call,backtrack(0,call,time,call));
		}
	}
	printf("END OF OUTPUT\n");
    return 0;
}
