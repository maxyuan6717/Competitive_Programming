#include <iostream>
#include <cmath>

using namespace std;

int N,ans[2];

int main() {
	while (cin >> N,N) {
		int cnt = 0;
		ans[0] = ans[1] = 0;
		int dig = log2(N) + 1;
		for (int i = 0; i < dig; i++) {
			if (N&(1<<i)) {
				ans[cnt] |= (1<<i);
				cnt = 1-cnt;
			}
		}
		cout << ans[0] << " " << ans[1] << endl;
	}
    return 0;
}
