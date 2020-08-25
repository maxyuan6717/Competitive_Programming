#include <iostream>
#include <fstream>
#include <sstream>
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

vector<string> dictionary;
vector<int> adj[200];
map<string,int> mindx;
int start,dest;
int vis[200];

int strdif(string a, string b) {
	int ret = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) ret++;
	}
	return ret;
}

int bfs() {
	queue<pii> q;
	vis[start] = 1;
	q.push(mp(start,0));
	while (!q.empty()) {
		pii p = q.front();
		q.pop();
		int u = p.first;
		int c = p.second;
		if (u == dest) return c;
		vis[u] = 1;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (vis[v]) continue;
			q.push(mp(v,c+1));
		}
	}
	return -1;
}

int main() {
	int T;
	//ifstream fin("test");
	cin >> T;
	cin.ignore();
	string e;
	getline(cin,e);
	for (int t = 0; t < T; t++) {
		dictionary.clear();
		mindx.clear();
		string s;
		getline(cin,s);
		int indx = 0;
		while (s != "*") {
			dictionary.push_back(s);
			mindx[s] = indx;
			adj[indx].clear();
			indx++;
			getline(cin,s);
		}
		for (int i = 0; i < indx; i++) {
			for (int j = i+1; j < indx; j++) {
				string s1 = dictionary[i];
				string s2 = dictionary[j];
				if (s1.size() != s2.size()) continue;
				if (strdif(s1,s2) == 1) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		getline(cin,s);
		stringstream ss;
		while (s != "") {
			ss << s;
			string s1,s2;
			ss >> s1 >> s2;
			cout << s1 << " " << s2 << " ";
			start = mindx[s1];
			dest = mindx[s2];
			for (int i = 0; i < indx; i++) vis[i] = 0;
			cout << bfs() << endl;
			ss.clear();
			getline(cin,s);
		}
		if (t != T-1) cout << endl;
	}
    
    return 0;
}
