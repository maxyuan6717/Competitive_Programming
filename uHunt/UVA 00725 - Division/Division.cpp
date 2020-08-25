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

int main() {
	int N;
	cin >> N;
	while (N) {
		bool left[10];
		bool one = 0;
		for (int i = 0; i < 10; i++) left[i] = 1;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {
					for (int l = 0; l < 10; l++) {
						for (int m = 0; m < 10; m++) {
							if (i == j || i == k || i == l || i == m) continue;
							if (j == k || j == l || j == m) continue;
							if (k == l || k == m) continue;
							if (l == m) continue;
							left[i] = 0,left[j] = 0,left[k] = 0,left[l] = 0,left[m] = 0;
							int num1 = m + l*10 + k*100 + j*1000 + i*10000;
							int num2 = N*num1;
							if (num2 >= 100000) continue;
							//cout << num1 << " " << num2 << endl;
							bool works = 1;
							for (int n = 0; n < 5; n++) {
								int pwer = pow(10,n);
								int mod = (num2/pwer)%10;
								if (!left[mod]) {
									works = 0;
								}
								else left[mod] = 0;
							}
							if (works) {
								one = 1;
								if (num2 < 10000) cout << "0" << num2;
								else cout << num2;
								cout << " / ";
								if (num1 < 10000) cout << "0" << num1;
								else cout << num1;
								cout << " = " << N << endl;
							}
							for (int a = 0; a < 10; a++) left[a] = 1;
						}
					}
				}
			}
		}
		if (!one) cout << "There are no solutions for " << N << "." << endl;
		cin >> N;
		if (N) cout << endl;
	}
    return 0;
}
