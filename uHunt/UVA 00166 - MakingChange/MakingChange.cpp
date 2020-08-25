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

#define LARGE 1000000
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int num[6],amt,shop[10001],you[10001];
int val[6] = {5,10,20,50,100,200};
double d;

int main() {
	for (int i = 0; i <= 10000; i++) shop[i] = you[i] = LARGE;
	shop[0] = you[0] = 0;
	for (int i = 0; i < 6; i++) {
		int v = val[i];
		for (int j = v; j <= 10000; j++) {
			shop[j] = min(shop[j],shop[j-v] + 1);
		}
	}
	while (cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4] >> num[5]) {
		for (int i = 1; i <= 10000; i++) you[i] = LARGE;
		if (!num[0] && !num[1] && !num[2] && !num[3] && !num[4] && !num[5]) break;
		cin >> d;
		amt = d*10000;
		amt/=100;
		int ans = LARGE;
		int total = 0;
		vector<int> coins;
		coins.clear();
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < num[i]; j++) {
				coins.push_back(val[i]);
				total += val[i];
			}
		}
		for (int i = 0; i < coins.size(); i++) {
			int c = coins[i];
			for (int j = total; j >= c; j--) {
				you[j] = min(you[j],you[j-c] + 1);
			}
		}
		for (int i = amt; i <= total; i++) {
			ans = min(ans,you[i]+shop[i-amt]);
		}
		printf("%3d\n",ans);
	}
    return 0;
}
