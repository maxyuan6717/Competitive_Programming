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

struct stone {
	bool big;
	int dis;
};

int N,D;
vector<stone> stones;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> D;
		stones.clear();
		stone st;
		st.big = 1, st.dis =0;
		stones.push_back(st);
		stones.push_back(st);
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			st.big = (s[0] == 'B');
			stringstream ss(s.substr(2,s.size()-2));
			ss >> st.dis;
			stones.push_back(st);
			if (st.big) stones.push_back(st);
		}
		st.big = 1, st.dis = D;
		stones.push_back(st);
		stones.push_back(st);
		int ans = 0;
		for (int i = 2; i < stones.size(); i += 2) ans = max(ans, stones[i].dis - stones[i-2].dis);
		for (int i = 3; i < stones.size(); i += 2) ans = max(ans, stones[i].dis - stones[i-2].dis);
		cout << "Case " << t << ": " << ans << endl;
	}
    return 0;
}
