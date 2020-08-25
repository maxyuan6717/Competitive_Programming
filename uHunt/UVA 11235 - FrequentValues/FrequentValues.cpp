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

struct node {
	int l,lfreq;
	int r,rfreq;
	int maxfreq;
};

int val[100005];
node st[1000005];
vector<int> ans;
int N,Q;

node merge(node a, node b) {
	node ret;
	ret.l = a.l;
	ret.r = b.r;
	if (a.l == a.r && a.l == b.l && a.l == b.r) {
		ret.lfreq = a.lfreq + b.lfreq;
		ret.rfreq = ret.lfreq;
		ret.maxfreq = ret.lfreq;
		ret.maxfreq = max(ret.maxfreq,max(a.maxfreq,b.maxfreq));
		return ret;
	}
	if (a.l == a.r && a.r == b.l) {
		ret.lfreq = a.lfreq + b.lfreq;
		ret.rfreq = b.rfreq;
		ret.maxfreq = max(ret.lfreq,ret.rfreq);
		ret.maxfreq = max(ret.maxfreq,max(a.maxfreq,b.maxfreq));
		return ret;
	}
	if (b.l == b.r && a.r == b.l) {
		ret.rfreq = a.rfreq + b.lfreq;
		ret.lfreq = a.lfreq;
		ret.maxfreq = max(ret.lfreq,ret.rfreq);
		ret.maxfreq = max(ret.maxfreq,max(a.maxfreq,b.maxfreq));
		return ret;
	}
	if (a.r == b.l) {
		int freq = a.rfreq + b.lfreq;
		ret.lfreq = a.lfreq;
		ret.rfreq = b.rfreq;
		ret.maxfreq = max(freq,max(ret.lfreq,ret.rfreq));
		ret.maxfreq = max(ret.maxfreq,max(a.maxfreq,b.maxfreq));
		return ret;
	}
	ret.lfreq = a.lfreq;
	ret.rfreq = b.rfreq;
	ret.maxfreq = max(ret.lfreq,ret.rfreq);
	ret.maxfreq = max(ret.maxfreq,max(a.maxfreq,b.maxfreq));
	return ret;
}

void build(int indx, int l, int r) {
	node n;
	//cout << indx << endl;
	if (l == r) {
		n.l = val[l];
		n.r = val[r];
		n.lfreq = 1;
		n.rfreq = 1;
		n.maxfreq = 1;
		st[indx] = n;
		return;
	}
	int lchild = 2*indx;
	int rchild = 2*indx + 1;
	int mid = (l+r)/2;
	build(lchild,l,mid);
	build(rchild,mid+1,r);
	n = merge(st[lchild],st[rchild]);
	st[indx] = n;
}

void RMQ(int cur, int cl, int cr, int l, int r) {
	if (l <= cl && r >= cr) {
		ans.push_back(cur);
		return;
	}
	if (cl > r || cr < l) return;
	int mid = (cl + cr)/2;
	int lchild = 2*cur;
	int rchild = 2*cur + 1;
	RMQ(lchild,cl,mid,l,r);
	RMQ(rchild,mid+1,cr,l,r);
}

int main() {
	cin >> N;
	while (N) {
		cin >> Q;
		for (int i = 0; i < N; i++) {
			cin >> val[i];
		}
		build(1,0,N-1);
		//for (int i = 1; i <= 25; i++) cout << st[i].maxfreq << " ";
		//cout << endl;
		for (int i = 0; i < Q; i++) {
			ans.clear();
			int a,b;
			cin >> a >> b;
			a--;
			b--;
			RMQ(1,0,N-1,a,b);
			node freq = st[ans[0]];
			for (int j = 1; j < ans.size(); j++) {
				freq = merge(freq,st[ans[j]]);
				//cout << freq.maxfreq << endl;
			}
			//cout << a << " " << b << " " << freq.maxfreq << endl;
			cout << freq.maxfreq << endl;
			//for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
			//cout << endl;
		}
		cin >> N;
	}
    return 0;
}
