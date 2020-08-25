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
#include <iomanip>
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,NC,NM;
bool arr[201][201];
map<string,int> indx;
map<int,string> rindx;

int main() {
    cin >> NC;
    indx.clear();
    rindx.clear();
    int caseNum = 1;
    while (NC) {
    	int cindx = 1;
    	for (int i = 0; i <= 200; i++) {
    		for (int j = 0; j <= 200; j++) {
    			arr[i][j] = 0;
    		}
    	}
    	for (int i = 0; i < NC; i++) {
			cin >> N;
			int pre = cindx;
			for (int j = 0; j < N; j++) {
				string s;
				cin >> s;
				indx[s] = cindx;
				rindx[cindx] = s;
				cindx++;
			}
			for (int j = pre; j < cindx-1; j++) {
				arr[j][j+1] = 1;
			}
    	}
    	cin >> NM;
    	for (int i = 0; i < NM; i++) {
    		string u,v;
    		cin >> u >> v;
    		int i1 = indx[u];
    		int i2 = indx[v];
    		arr[i1][i2] = 1;
    	}
    	for (int k = 1; k < cindx; k++) {
    		for (int i = 1; i < cindx; i++) {
    			for (int j = 1; j < cindx; j++) {
    				arr[i][j] |= arr[i][k] & arr[k][j];
    			}
    		}
    	}
    	int ans = 0;
    	vii ans2;
    	for (int i = 1; i < cindx; i++) {
    		for (int j = i+1; j < cindx; j++) {
    			if (!arr[i][j] && !arr[j][i]) {
    				ans++;
    				ans2.push_back(mp(i,j));
    			}
    		}
    	}
    	if (ans) cout << "Case " << caseNum++ << ", " << ans << " concurrent events:" << endl;
    	else cout << "Case " << caseNum++ << ", " << "no concurrent events." << endl;
    	if (ans > 2) ans = 2;
    	for (int i = 0; i < ans; i++) {
    		int u = ans2[i].first;
    		int v = ans2[i].second;
    		string s1 = rindx[u], s2 = rindx[v];
    		cout << "(" << s1 << "," << s2 << ")" << " ";
    	}
    	if (ans) cout << endl;
    	cin >> NC;
    }
    return 0;
}
