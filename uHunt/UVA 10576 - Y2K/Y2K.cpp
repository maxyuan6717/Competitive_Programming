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

int main() {
	int s,d;
	while (scanf("%d %d",&s,&d)==2) {
		int a[2] = {s,-d};
		long long sum[12];
		long long ans = 0;
		for (int i = 0; i < 1<<12; i++) {
			sum[0] = a[(i&1)>0];
			for (int j = 1; j < 12; j++) sum[j] = sum[j-1] + a[(i&(1<<j))>0];
			if (sum[4] > 0) continue;
			bool works = 1;
			for (int j = 5; j < 12; j++) {
				if (sum[j]-sum[j-5] > 0) {
					works = 0;
					break;
				}
			}
			if (!works) continue;
			ans = max(ans,sum[11]);
		}
		if (ans) printf("%lld\n",ans);
		else printf("Deficit\n");
	}
    return 0;
}
