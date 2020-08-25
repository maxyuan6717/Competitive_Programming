 /*
ID: yuanmax1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int R;
    fin >> R;
    int nums[R+1][R+1];
    int maxNum = 0;
    for (int i = 1; i <= R; i++) {
    	for (int j = 1; j <= i; j++) {
    		fin >> nums[i][j];
    	}	
    }
    for (int i = 2; i <= R; i++) {
    	for (int j = 1; j <= i; j++) {
    		if (j == 1) {
				nums[i][j] += nums[i-1][j];
    		}
    		else if (j == i) {
    			nums[i][j] += nums[i-1][j-1];
    		}
    		else {
    			nums[i][j] += max(nums[i-1][j], nums[i-1][j-1]);
    		}
    	}
    }
    for (int i = 1; i <=R; i++) {
    	int num = nums[R][i];
    	if (num > maxNum) maxNum = num;
    }
    fout << maxNum << endl;
    
    
    return 0;
}