#include <iostream>
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
double arr[21][21][21];
int p[21][21][21];

int main() {
	int N;
    while (cin >> N) {
    	memset(arr,0,sizeof(arr));
    	for (int i = 1; i <= N; i++) {
    		for (int j = 1; j <= N; j++) {
    			if(i == j) {
    				arr[i][j][1] = 1;
    				p[i][j][1] = i;
    				continue;
    			}
    			cin >> arr[i][j][1];
    			p[i][j][1] = i;
    		}
    	}
    	for (int l = 2; l <= N; l++) {
			for (int k = 1; k <= N; k++) {
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= N; j++) {
						double temp = arr[i][k][l-1] * arr[k][j][1];
						if (temp > arr[i][j][l]) {
							arr[i][j][l] = temp;
							p[i][j][l] = k;
						}
					}
				}
			}
    	}
    	bool works = 0;
    	for (int l = 2; l <= N; l++) {
    		if (works) break;
    		for (int i = 1; i <= N; i++) {
    			if (arr[i][i][l] <= 1.01) continue;
    			stack<int> ans;
    			ans.push(p[i][i][l]);
    			for (int j = l-1; j > 0; j--) ans.push(p[i][ans.top()][j]);
    			int first = ans.top();
    			while (!ans.empty()) {
    				cout << ans.top() << " ";
    				ans.pop();
    			}
    			cout << first << endl;
    			works = 1;
    			break;
    		}
    	}
    	if (!works) cout << "no arbitrage sequence exists" << endl;
    }
    return 0;
}
