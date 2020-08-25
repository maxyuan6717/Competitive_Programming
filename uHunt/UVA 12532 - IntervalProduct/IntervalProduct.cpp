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

typedef pair<int,bool> pib;

int N,K;
int ft[100001];
int seq[100001];

int LSOne(int x) {
	return (x&(-x));
}

int getSum(int indx) {
	int ret = 0;
	indx++;
	while (indx > 0) {
		ret += ft[indx];
		indx -= LSOne(indx);
	}
	return ret;
}

void update(int indx, int val) {
	indx++;
	while (indx <= N) {
		ft[indx] += val;
		indx += LSOne(indx);
	}
}

void build() {
	for (int i = 0; i < N; i++) {
		update(i,seq[i]);
	}
}
int main() {
    while (cin >> N >> K) {
    	for (int i = 0; i <= N; i++) ft[i] = 0;
    	for (int i = 0; i < N; i++) {
    		int num;
    		cin >> num;
    		if (num > 0) seq[i] = 0;
    		else if (num < 0) seq[i] = 1;
    		else seq[i] = -1000000;
    	}
    	build();
    	for (int i = 0; i < K; i++) {
    		char c;
    		int a,b;
    		cin >> c >> a >> b;
    		if (c == 'C') {
    			a--;
    			int change;
    			if (b > 0) change = 0;
    			else if (b < 0) change = 1;
    			else change = -1000000;
    			if (change != seq[a]) {
    				int temp = seq[a];
    				seq[a] = change;
    				update(a,change-temp);
    			}
    		}
    		else {
    			a--;
    			b--;
    			int num = getSum(b)-getSum(a-1);
    			if (num%2 == 1 && num >= 0) cout << "-";
    			else if (num%2 == 0 && num >= 0) cout << "+";
    			else cout << "0";
    		}
    	}
    	cout << endl;
    }
    return 0;
}
