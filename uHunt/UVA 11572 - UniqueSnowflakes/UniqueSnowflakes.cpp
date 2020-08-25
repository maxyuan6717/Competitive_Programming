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
	int C;
	cin >> C;
	for (int c = 0; c < C; c++) {
		int N;
		cin >> N;
		map<int,int> lindx;
		lindx.clear();
		int ans = 0;
		int temp = 0;
		int cutoff = 0;
		for (int i = 1; i <= N; i++) {
			int id;
			cin >> id;
			int indx = lindx[id];
			if (indx != 0) {
				cutoff = max(cutoff,indx);
				temp = i-cutoff-1;
			}
			temp++;
			lindx[id] = i;
			ans = max(ans,temp);
		}
		cout << ans << endl;
	}
    
    return 0;
}
