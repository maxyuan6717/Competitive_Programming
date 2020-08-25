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

int N;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case " << t << ". ";
		cin >> N;
		vector<int> h,w;
		for (int i = 0; i < N; i++) {
			int height;
			cin >> height;
			h.push_back(height);
		}
		for (int i = 0; i < N; i++) {
			int width;
			cin >> width;
			w.push_back(width);
		}
		int dpi[N];
		int dpd[N];
		int curi = 0;
		int curd = 0;
		int lis = 0;
		int lds = 0;
		for (int i = 0; i < N; i++) {
			curi = curd = dpi[i] = dpd[i] = w[i];
			for (int j = 0; j < i; j++) {
				if (h[i] == h[j]) continue;
				if (h[i] > h[j]) dpi[i] = max(dpi[i],curi+dpi[j]);
				else dpd[i] = max(dpd[i],curd+dpd[j]);
			}
			lis = max(lis,dpi[i]);
			lds = max(lds,dpd[i]);
		}
		if (lis >= lds) cout << "Increasing (" << lis << "). Decreasing (" << lds << ")." << endl;
		else cout << "Decreasing (" << lds << "). Increasing (" << lis << ")." << endl;
	}
    
    return 0;
}
