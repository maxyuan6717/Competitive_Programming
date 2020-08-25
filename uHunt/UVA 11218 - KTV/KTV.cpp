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

struct combo {
	int used,score;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

combo combos[81];
int N;
int full = (1<<9) - 1;

int main() {
	int caseNum = 1;
	while (cin >> N, N) {
		for (int i = 0; i < N; i++) {
			int a,b,c;
			cin >> a >> b >> c >> combos[i].score;
			a--,b--,c--;
			combos[i].used = (1<<a) | (1<<b) | (1<<c);
			//cout << combos[i].used << endl;
		}
		int ans = -1;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				for (int k = j+1; k < N; k++) {
					combo a = combos[i], b = combos[j], c = combos[k];
					if (a.used + b.used + c.used == full) ans = max(ans,a.score+b.score+c.score);
				}
			}
		}
		cout << "Case " << caseNum++ << ": " << ans << endl;
	}
    return 0;
}
