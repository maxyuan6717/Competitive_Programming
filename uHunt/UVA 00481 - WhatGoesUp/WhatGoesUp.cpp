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
    int num;
    int N = 0;
    vector<int> seq;
    ifstream fin ("test.in");
  	while (cin >> num) {
    	seq.push_back(num);
    	N++;
    }
    vector<int> tail(N,0);
    vector<int> prev(N,-1);
    int ans = 1;
    for (int i = 1; i < N; i++) {
    	if (seq[i] < seq[tail[0]]) {
    		tail[0] = i;
    		continue;
    	}
    	if (seq[i] > seq[tail[ans-1]]) {
    		prev[i] = tail[ans-1];
    		tail[ans] = i;
    		ans++;
    		continue;
    	}
    	int l = -1;
    	int r = N-1;
    	int val = seq[i];
    	while (l + 1 < r) {
    		int mid = (r+l)/2;
    		if (seq[tail[mid]] >= val) r = mid;
    		else l = mid;
    	}
    	prev[i] = tail[r-1];
    	tail[r] = i;
    }
    cout << ans << endl << "-" << endl;
    for (int i = tail[ans-1]; i >= 0; i = prev[i]) cout << seq[i] << endl;
    return 0;
}
