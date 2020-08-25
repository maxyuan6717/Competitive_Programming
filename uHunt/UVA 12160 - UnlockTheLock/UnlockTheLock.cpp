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
#include <iomanip>

#define LARGE (1<<31)-1
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;

int L,U,R;
int vis[10000];
vector<int> buttons;

int bfs() {
	queue<pii> q;
	vis[L] = 1;
	q.push(mp(L,0));
	while (!q.empty()) {
		int cur = q.front().first;
		int moves = q.front().second;
		q.pop();
		if (cur == U) return moves;
		for (int i = 0; i < R; i++) {
			int butVal = buttons[i];
			int newVal = (cur+butVal)%10000;
			if (vis[newVal]) continue;
			vis[newVal] = 1;
			q.push(mp(newVal,moves+1));
		}
	}
	return -1;
}

int main() {
	cin >> L >> U >> R;
	int caseNum = 1;
	while (L || U || R) {
		buttons.clear();
		for (int i = 0; i < R; i++) {
			int num;
			cin >> num;
			buttons.push_back(num);
		}
		for (int i = 0; i <= 9999; i++) {
			vis[i] = 0;
		}
		int ans = bfs();
		cout << "Case " << caseNum++ << ": ";
		if (ans == -1) cout << "Permanently Locked" << endl;
		else cout << ans << endl;
		cin >> L >> U >> R;
	}
    
    return 0;
}
