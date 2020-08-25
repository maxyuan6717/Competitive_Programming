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

int N;
int arr[11];
int nums[10] = {126,48,109,121,51,91,95,112,127,123};
//int nums[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};

int numOnes(int x) {
	int ret = 0;
	for (int i = 0; i < 7; i++) {
		if (x&(1<<i)) ret++;
	}
	return ret;
}

bool rec(int cur, int indx, int burnt) {
	if (indx == N) return 1;
	if (cur < 0) return 0;
	if (burnt & arr[indx]) return 0;
	if (numOnes(arr[indx]) != numOnes(nums[cur]&arr[indx])) return 0;
	return rec(cur-1,indx+1,(nums[cur]^arr[indx])|burnt);
}

int main() {
	while (cin >> N,N) {
		for (int i = 0; i < N; i++) {
			arr[i] = 0;
			for (int j = 6; j >= 0; j--) {
				char c;
				cin >> c;
				if (c == 'Y') arr[i] += pow(2,j);
			}
		}
		bool works = 0;
		for (int i = 9; i >= 0; i--) {
			int num = nums[i];
			if (numOnes(arr[0]) == numOnes(num&arr[0])) {
				//cout << i << endl;
				works = rec(i-1,1,num^arr[0]);
				if (works) break;
			}
		}
		if (works) cout << "MATCH" << endl;
		else cout << "MISMATCH" << endl;
	}
    return 0;
}
