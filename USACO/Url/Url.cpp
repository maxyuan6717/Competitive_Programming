#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int T,N;
	char arr[62];
	for (int i = 97; i <= 122; i++) {
	    arr[i-97] = i;
	    //cout << arr[i-97] << endl;
	}
	for (int i = 65; i <= 90; i++) {
	    arr[i-39] = i;
	    //cout << arr[i-39] << endl;
	}
	for (int i = 48; i <= 57; i++) {
	    arr[i+4] = i;
	    //cout << arr[i+52] << endl;
	}
	cin >> T;
	for (int t = 0; t < T; t++) {
	    cin >> N;
	    string ans = "";
	    while (N!=0) {
	        ans+=arr[N%62];
	        cout << N%62 << endl;
	        N/=62;
	    }
	    reverse(ans.begin(),ans.end());
	    cout << ans << endl;
	}
	return 0;
}