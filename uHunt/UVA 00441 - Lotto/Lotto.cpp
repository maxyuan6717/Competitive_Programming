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
    int k;
    cin >> k;
    while (k) {
    	int arr[k];
    	for (int i = 0; i < k; i++) {
    		cin >> arr[i];
    	}
    	for (int a = 0; a < k-5; a++) {
    		for (int b = a+1; b < k-4; b++) {
    			for (int c = b+1; c < k-3; c++) {
    				for (int d = c+1; d < k-2; d++) {
    					for (int e = d+1; e < k-1; e++) {
    						for (int f= e+1; f < k; f++) {
    							cout << arr[a] << " " << arr[b] << " " << arr[c] << " " << arr[d] << " " << arr[e] << " " << arr[f] << endl;
    						}
    					}
    				}
    			}
    		}
    	}
    	cin >> k;
    	if (k) cout << endl;
    }
    return 0;
}
