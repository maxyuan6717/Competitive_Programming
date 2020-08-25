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

bool isPrime[301];
vector<int> primes;
int cnt[301];
bool vis[65][3][1001][15];

void genPrimes(int n) {
	memset(isPrime,true,sizeof(isPrime));
	for (int p = 2; p*p <= n; p++) {
		if (isPrime[p]) {
			for (int i = p*2; i <= n; i+=p) {
				isPrime[i] = 0;
			}
		}
	}
	for (int p = 2; p <= n; p++) if (isPrime[p]) primes.push_back(p);
}

int N,M;
vector<int> seq,ans;

bool lex(int a, int b) {
	string s1 = to_string(a);
	string s2 = to_string(b);
	return (strcmp(s1.c_str(),s2.c_str()) < 0);
}

int rec(int indx, int sum, int len) {
	if (vis[indx][cnt[primes[indx]]][sum][len]) return 0;
	if (len == M && sum == N) {
		ans = seq;
		return 1;
	}
	if (len == M) return 0;
	for (int i = indx; i < primes.size(); i++) {
		int p = primes[i];
		if (sum + p > N || !cnt[p]) continue;
		seq.push_back(p);
		cnt[p]--;
		if (rec(i,sum+p,len+1)) return 1;
		cnt[p]++;
		seq.pop_back();
	}
	vis[indx][cnt[primes[indx]]][sum][len] = 1;
	return  0;
}

int main() {
	genPrimes(300);
	sort(primes.begin(),primes.end(),lex);
	int caseNum = 1;
	while (cin >> N >> M, N || M) {
		memset(vis,0,sizeof(vis));
		seq.clear();
		ans.clear();
		for (int i = 0; i < primes.size(); i++) {
			cnt[primes[i]] = 2;
		}
		cnt[2]--;
		cout << "CASE " << caseNum++ << ":" << endl;
		if (!rec(0,0,0)) {
			cout << "No Solution." << endl;
			continue;
		}
		for (int i = 0; i < M; i++) {
			cout << ans[i];
			if (i != M-1) cout << "+";
		}
		cout << endl;
	}
    return 0;
}
