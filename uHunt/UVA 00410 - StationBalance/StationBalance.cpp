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
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int C,S;
double arr[10];

int main() {
	int caseNum = 1;
	while (cin >> C >> S) {
		printf("Set #%d\n",caseNum++);
		int i;
		double avg = 0, imbalance = 0;
		for (i = 0; i < S; i++) {
			cin >> arr[i];
			avg += arr[i];
		}
		while (i < 2*C) arr[i++] = 0;
		sort(arr,arr+(2*C));
		avg/=C;
		for (int i = 0; i < C; i++) {
			imbalance += abs(arr[i] + arr[2*C-i-1] - avg);
			printf(" %d:",i);
			if (arr[i]) cout << " " << arr[i];
			if (arr[2*C-i-1]) cout << " " << arr[2*C-i-1];
			cout << endl;
		}
		printf("IMBALANCE = %.5f\n\n",imbalance);
	}
    return 0;
}
