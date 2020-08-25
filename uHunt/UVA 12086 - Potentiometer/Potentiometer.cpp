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

#define LARGE (1<<31)-1

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int counter = 1;
	while (N) {
		if (counter != 1) cout << endl;
		cout << "Case " << counter << ":" << endl;
		int st[2*N];
		for (int i = 0; i < N; i++) cin >> st[N+i];
		for (int i = N-1; i > 0; --i) {
			st[i] = st[2*i] + st[2*i+1];
		}
		string s;
		int p1,p2;
		cin >> s;
		while (s != "END") {
			cin >> p1 >> p2;
			char c = s[0];
			if (c == 'M') {
				p1--;
				int ans = 0;
				for (p1 += N, p2 += N; p1 < p2; p1 >>= 1, p2 >>= 1) {
					if (p1&1) ans += st[p1++];
					if (p2&1) ans += st[--p2];
				}
				cout << ans << endl;
			}
			else if (c == 'S') {
				p1--;
				for (st[p1+=N] = p2; p1 > 1; p1 >>= 1) st[p1>>1] = st[p1] + st[p1^1];
			}
			cin >> s;
		}
		cin >> N;
		counter++;
	}
    return 0;
}
