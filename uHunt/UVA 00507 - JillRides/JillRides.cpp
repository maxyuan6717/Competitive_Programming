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

struct ans {
	int maxNum, l, r;
};

int main() {
    int B;
    cin >> B;
    for (int r = 1; r <= B; r++) {
    	int s;
    	cin >> s;
    	int arr[s-1];
    	for (int i = 0; i < s-1; i++) {
    		cin >> arr[i];
    	}
    	int sum = 0;
    	ans a;
    	a.maxNum = 0;
    	a.l = -1;
    	a.r = -1;
    	int start = 1;
    	for (int i = 0; i < s-1; i++) {
    		sum += arr[i];
    		if (sum < 0) {
    			sum = 0;
    			start = i+2;
    			continue;
    		}
    		if (sum > a.maxNum) {
    			a.maxNum = sum;
    			a.l = start;
    			a.r = i+2;
    		}
    		else if (sum == a.maxNum) {
    			int templ = start;
    			int tempr = i+2;
    			if (tempr-templ > a.r-a.l) {
    				a.maxNum = sum;
    				a.l = templ;
    				a.r = tempr;
    			}
    			else if (tempr-templ == a.r-a.l) {
    				if (templ < a.l) {
    					a.l = templ;
    					a.r = tempr;
    				}
    			}
    		}
    	}
    	if (a.l == -1) cout << "Route " << r << " has no nice parts" << endl;
    	else cout << "The nicest part of route " << r << " is between stops " << a.l << " and " << a.r << endl;
    }

    return 0;
}
