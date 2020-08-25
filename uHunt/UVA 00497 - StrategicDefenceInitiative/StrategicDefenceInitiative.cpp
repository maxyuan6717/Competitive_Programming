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

int binsearch (vector<int> v, vector<int> T, int l, int r, int key){
	while (r - l > 1) {
		int m = (l+r)/2;
		if (v[T[m]] >= key) r = m;
		else l = m;
	}
	return r;
}

void lis(vector<int> v) {
	vector<int> tail(N,0);
	vector<int> prev(N,-1);
	int len = 1;
	for (int i = 1; i < N; i++) {
		if (v[i] < v[tail[0]]) tail[0] = i;
		else if (v[i] > v[tail[len-1]]) {
			prev[i] = tail[len-1];
			tail[len++] = i;
		}
		else {
			int pos = binsearch(v,tail,-1,len-1,v[i]);
			if (!pos) {
				prev[i] = 0;
			}
			else {
				prev[i] = tail[pos-1];
				tail[pos] = i;
			}
		}
	}
	cout << "Max hits: " << len << endl;
	stack<int> s;
	//for (int i = 0; i < N; i++) cout << prev[i] << endl;
	for (int i = tail[len-1]; i >= 0; i = prev[i]) {
		s.push(v[i]);
	}
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
}

int main() {
	//ifstream fin ("test");
	int T;
	cin >> T;
	cin.ignore();
	string s;
	getline(cin,s);
	for (int t = 0; t < T; t++) {
		vector<int> v;
		while (getline(cin,s),s != "") {
			stringstream ss(s);
			int num;
			ss >> num;
			v.push_back(num);
		}
		N = v.size();
		lis(v);
		if (t != T-1) cout << endl;
	}
    return 0;
}
