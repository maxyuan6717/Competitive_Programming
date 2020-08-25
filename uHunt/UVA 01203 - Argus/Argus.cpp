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

struct query {
	int time,id,cur;
};

bool operator < (query a, query b) {
	if (a.cur != b.cur) return a.cur > b.cur;
	else return a.id > b.id;
}

string s;
int K;

int main() {
	cin >> s;
	priority_queue<query> pq;
	while (s != "#") {
		query q;
		cin >> q.id >> q.time;
		q.cur = q.time;
		pq.push(q);
		cin >> s;
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		query q = pq.top();
		pq.pop();
		cout << q.id << endl;
		q.cur += q.time;
		pq.push(q);
	}
    return 0;
}
