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

struct pole {
	long long x,y;
	int h;
	double angle;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N;
vector<pole> poles;
vector<pole> ans;

long long dist(pole a) {
	return (a.x*a.x + a.y*a.y);
}

bool comp1(pole a, pole b) {
	if (a.angle != b.angle) return a.angle < b.angle;
	return (dist(a) < dist(b));
}

bool comp2(pole a, pole b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

int main() {
	int caseNum = 1;
	while (cin >> N,N) {
		poles.clear();
		ans.clear();
		for (int i = 0; i < N; i++) {
			pole p;
			cin >> p.x >> p.y >> p.h;
			p.angle = atan2(p.y,p.x);
			poles.push_back(p);
		}
		sort(poles.begin(),poles.end(),comp1);
		int curH = poles[0].h;
		pole curP = poles[0];
		for (int i = 1; i < N; i++) {
			pole P = poles[i];
			if (P.angle == curP.angle) {
				if (P.h <= curH) ans.push_back(P);
				curH = max(curH,P.h);
			}
			else curH = P.h;
			curP = P;
		}
		cout << "Data set " << caseNum++ << ":" << endl;
		if (ans.empty()) {
			cout << "All the lights are visible." << endl;
			continue;
		}
		sort(ans.begin(),ans.end(),comp2);
		cout << "Some lights are not visible:" << endl;
		for (int i = 0; i < ans.size(); i++) {
			pole p = ans[i];
			cout << "x = " << p.x << ", y = " << p.y;
			if (i != ans.size()-1) cout << ";" << endl;
			else cout << "." << endl;
		}
	}
    return 0;
}
