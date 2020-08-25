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

map<string,string> parent;
map<string,long long> friends;
map<string,long long> ranks;

string findroot(string s) {
	if (parent[s] != s) {
		parent[s] = findroot(parent[s]);
	}
	return parent[s];
}

void Union(string s1, string s2) {
	string s1root = findroot(s1);
	string s2root = findroot(s2);
	friends[s1root] += (friends[s1root] == 0);
	friends[s2root] += (friends[s2root] == 0);
	if (s1root == s2root) {
		cout << friends[s1root] << endl;
		return;
	}
	if (ranks[s1root] < ranks[s2root]) {
		parent[s1root] = s2root;
		friends[s2root] += friends[s1root];
		cout << friends[s2root] << endl;
	}
	else {
		parent[s2root] = s1root;
		friends[s1root] += friends[s2root];
		cout << friends[s1root] << endl;
	}
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
    	int F;
    	cin >> F;
    	parent.clear();
    	friends.clear();
    	ranks.clear();
    	for (int i = 0; i < F; i++) {
    		string s1, s2;
    		cin >> s1 >> s2;
    		if (parent[s1] == "") parent[s1] = s1;
    		if (parent[s2] == "") parent[s2] = s2;
    		Union(s1,s2);
    	}
    }
    return 0;
}
