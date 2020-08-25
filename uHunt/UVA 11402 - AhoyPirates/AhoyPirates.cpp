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
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;

string str;
int sum[2200000];
int pending[2200000];
pii range[2200000];

void build(int indx, int l, int r) {
	pending[indx] = 0;
	range[indx] = mp(l,r);
	if (l == r) {
		sum[indx] = (str[l]=='1');
		return;
	}
	int lchild = 2*indx;
	int rchild = 2*indx + 1;
	int mid = (l + r)/2;
	build(lchild,l,mid);
	build(rchild,mid+1,r);
	sum[indx] = sum[lchild] + sum[rchild];
}

bool inside(int l1, int r1, int l2, int r2) {
	return (l2 >= l1 && r2 <= r1);
}

bool intersect(int l1, int r1, int l2, int r2) {
	return ((l1 <= l2 && r1 >= l2) || (l1 >= l2 && l1 <= r2));
}

int getSum(int indx, int pval) {
	if (pval == 1) return (range[indx].second-range[indx].first+1);
	if (pval == 2) return 0;
	if (pval == 3) return ((range[indx].second-range[indx].first+1)-sum[indx]);
	return 0;
}

int flipcase(int indx) {
	int pval = pending[indx];
	if (pval == 0) return 3;
	if (pval == 1) return 2;
	if (pval == 2) return 1;
	return 0;
}

void change(int indx, int pval) {
	if (pval == 0) return;
	sum[indx] = getSum(indx,pval);
	if (range[indx].second == range[indx].first)  return;
	int lchild = 2*indx;
	int rchild = 2*indx + 1;
	if (pval == 1 || pval == 2) {
		pending[lchild] = pval;
		pending[rchild] = pval;
		return;
	}
	pending[lchild] = flipcase(lchild);
	pending[rchild] = flipcase(rchild);
}

void propagate(int indx) {
	if (pending[indx] == 0) return;
	change(indx,pending[indx]);
	pending[indx] = 0;
}

int rsq(int cur, int l, int r) {
	if (inside(range[cur].first,range[cur].second,l,r)) {
		if (pending[cur] == 1) return(r-l+1); // SET
		if (pending[cur] == 2) return 0;      // CLEAR
	}
	if (inside(l,r,range[cur].first,range[cur].second)) {
		propagate(cur);
		return sum[cur];
	}
	if (intersect(l,r,range[cur].first, range[cur].second)) {
		propagate(cur);
		int lchild = 2*cur;
		int rchild = 2*cur + 1;
		int lsum = rsq(lchild,l,r);
		int rsum = rsq(rchild,l,r);
		return lsum + rsum;
	}
	return 0;
}

void update(int cur, int l, int r, int pval) {
	propagate(cur);
	if (inside(l,r,range[cur].first,range[cur].second)) {
		change(cur,pval);
		return;
	}
	if (intersect(l,r,range[cur].first,range[cur].second)) {
		int lchild = 2*cur;
		int rchild = 2*cur + 1;
		update(lchild,l,r,pval);
		update(rchild,l,r,pval);
		sum[cur] = sum[lchild] + sum[rchild];
	}
}

int main() {
	int C;
	cin >> C;
	for (int c = 1; c <= C; c++) {
		cout << "Case " << c << ":" << endl;
		int M;
		cin >> M;
		str = "";
		for (int m = 0; m < M; m++) {
			int T;
			cin >> T;
			string s;
			cin >> s;
			for (int i = 0; i < T; i++) str += s;
		}
		int N = int(str.size());
		// BUILD SEG TREE
		build(1,0,N-1);
		// PROCESS QUERIES
		int Q;
		cin >> Q;
		int qnum = 1;
		for (int q = 0; q < Q; q++) {
			char ch;
			int a,b;
			cin >> ch >> a >> b;
			if (ch == 'F') {
				update(1,a,b,1);
			}
			else if (ch == 'E') {
				update(1,a,b,2);
			}
			else if (ch == 'I') {
				update(1,a,b,3);
			}
			else if (ch == 'S') {
				cout << "Q" << qnum << ": ";
				qnum++;
				cout << rsq(1,a,b) << endl;
			}
		}
	}

    return 0;
}
