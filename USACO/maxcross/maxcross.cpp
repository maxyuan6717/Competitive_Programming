/*
ID: yuanmax1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("maxcross.out");
    ifstream fin ("maxcross.in");
    int N,K,B;
    fin >> N >> K >> B;
    int ans = B;
    if (B == N) {
    	fout << K << endl;
    	return 0;
    }
    int s[100001] = {0};
    int num;
    for (int i = 0; i < B; i++) {
    	fin >> num;
    	s[num] = 1;
    }
    int counter = 0;
    int total = 0;
    int gaps[500005][2] = {0};
    for (int i = 1; i <= N; i++) {
    	if (s[i] != 1 && i != N) total++;
    	else if (s[i] != 1 && i == N) {
    		//cout << total << endl;
    		gaps[counter][1] = N;
    		gaps[counter][0] = i-total;
    		if (gaps[counter][1]-gaps[counter][0]+1 >= K) {
    			fout << 0 << endl;
    			return 0;
    		}	
    		counter++;
    		total = 0;
    	}
    	else if (total > 0) {
    		gaps[counter][1] = i-1;
    		gaps[counter][0] = i-total;
    		if (gaps[counter][1]-gaps[counter][0]+1 >= K) {
    			fout << 0 << endl;
    			return 0;
    		}	
    		counter++;
    		total = 0;
    	}
    }
    int p;
    int temp;
    int fix;
    //cout << gaps[2][0] << endl;
    for (int i = counter-1; i >= 0; i--) {
    	fix = 0;
    	temp = i-1;
    	total = (gaps[i][1]-gaps[i][0]+1);
    	p = gaps[i][0]-1;
    	//cout << i << " " << p << endl;
    	while (total < K && p >= 1) {
    		if (s[p] == 1) {
    			total++;
    			p--;
    			fix++;
    		}
    		else {
    			total+=(gaps[temp][1]-gaps[temp][0]+1);
    			p = gaps[temp][0]-1;
    			temp--;
    		}
    		//cout << i << " " << total << endl;
    		//cout << i << " " << p << endl;
    	}
    	//cout << fix << " " << total << endl;
    	if (fix < ans && total >= K) ans = fix;
    }
    fout << ans << endl;
    
    return 0;
}