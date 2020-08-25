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

int arr[5];

bool rec(int sum, int indx, int operation) {
	//cout << sum << " " << indx << endl;
	if (indx == 5 && sum == 23) return 1;
	if (indx == 5) return 0;
	if (operation == 1) sum += arr[indx];
	else if (operation == 2) sum -= arr[indx];
	else if (operation == 3) sum *= arr[indx];
	for (int i = 1; i <= 3; i++) {
		bool ret = rec(sum,indx + 1, i);
		if (ret) return 1;
		if (indx == 4) break;
	}
	return 0;
}

int main() {
	while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4]) {
		if (!arr[0]) break;
		bool works = 0;
		sort(arr,arr+5);
		do {
			for (int i = 1; i <= 3; i++) {
				works = rec(arr[0],1,i);
				if (works) break;
			}
			if (works) break;
		} while(next_permutation(arr,arr+5));
		if (works) cout << "Possible" << endl;
		else cout << "Impossible" << endl;
	}
    return 0;
}
