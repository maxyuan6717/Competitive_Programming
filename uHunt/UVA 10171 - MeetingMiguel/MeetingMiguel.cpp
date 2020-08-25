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

#define LARGE 100000
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int arr[26][26][2];
int N;

int main() {
	cin >> N;
	int curNum = 1;
    while (N) {
    	for (int i = 0; i < 26; i++) {
    		for (int j = 0; j < 26; j++) {
    			arr[i][j][0] = LARGE;
    			arr[i][j][1] = LARGE;
    			if (i == j) {
    				arr[i][j][0] = 0;
    				arr[i][j][1] = 0;
    			}
    		}
    	}
    	for (int i = 0; i < N; i++) {
    		char age,dir,u,v;
    		int c;
    		cin >> age >> dir >> u >> v >> c;
    		int i1 = u-'A';
    		int i2 = v-'A';
    		int indx;
    		if (age == 'Y') indx = 0;
    		else indx = 1;
    		arr[i1][i2][indx] = min(arr[i1][i2][indx],c);
    		if (dir == 'B') arr[i2][i1][indx] = arr[i1][i2][indx];
    	}
    	for (int k = 0; k < 26; k++) {
    		for (int i = 0; i < 26; i++) {
    			for (int j = 0; j < 26; j++) {
    				arr[i][j][0] = min(arr[i][j][0], arr[i][k][0] + arr[k][j][0]);
    				arr[i][j][1] = min(arr[i][j][1], arr[i][k][1] + arr[k][j][1]);
    			}
    		}
    	}
    	char a,b;
    	cin >> a >> b;
    	int A = a - 'A';
    	int B = b - 'A';
    	int ans = LARGE;
    	vector<char> ans2;
    	for (int i = 0; i < 26; i++) {
    		if (arr[A][i][0] + arr[B][i][1] < ans) {
    			ans2.clear();
    			ans = arr[A][i][0] + arr[B][i][1];
    			char place = i+'A';
    			ans2.push_back(place);
    		}
    		else if (arr[A][i][0] + arr[B][i][1] == ans) {
    			char place = i+'A';
    			ans2.push_back(place);
    		}
    	}
    	if (ans == LARGE) cout << "You will never meet." << endl;
    	else {
    		sort(ans2.begin(),ans2.end());
    		cout << ans;
    		for (int i = 0; i < ans2.size(); i++) {
    			cout << " " << ans2[i];
    		}
    		cout << endl;
    	}
    	cin >> N;
    }
    return 0;
}
