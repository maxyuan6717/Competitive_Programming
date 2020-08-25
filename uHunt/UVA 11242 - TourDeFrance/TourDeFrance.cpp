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
	int F,R;
	while (cin >> F,F) {
		cin >> R;
		double front[F],rear[R];
		for (int i = 0; i < F; i++) {
			cin >> front[i];
		}
		for (int i = 0; i < R; i++) {
			cin >> rear[i];
		}
		vector<double> ratios;
		for (int i = 0; i < F; i++) {
			for (int j = 0; j < R; j++) {
				ratios.push_back(rear[j]/front[i]);
			}
		}
		sort(ratios.begin(),ratios.end());
		double ans = 0;
		for (int i = 0; i < ratios.size()-1; i++) {
			//cout << ratios[i] << " " << ratios[i+1] << endl;
			ans = max(ans,ratios[i+1]/ratios[i]);
		}
		cout << setprecision(2) << fixed;
		cout << ans << endl;
	}
    return 0;
}
