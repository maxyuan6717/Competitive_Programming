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
	int N;
	cin >> N;
	while (N) {
		int ans = 0;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			sum += num;
			if (sum < 0) {
				sum = 0;
				continue;
			}
			ans = max(sum,ans);
		}
		if (ans == 0) cout << "Losing streak." << endl;
		else cout << "The maximum winning streak is " << ans << "." << endl;
		cin >> N;
	}
    
    return 0;
}
