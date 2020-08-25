/*
ID: yuanmax1
PROG: fence9
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <list>
#include <stack>
using namespace std;

int main() {
    ofstream fout ("fence9.out");
    ifstream fin ("fence9.in");
    float n,m,p;
    fin >> n >> m >> p;
    int ans = 0;
    float slopel,sloper;
    if (n == 0) slopel = 0;
    else slopel = m/n;
    if (n-p == 0) sloper = 0;
    else sloper = m/(n-p);
    float b = 0-(sloper*p);
    //cout << slopel << " " << sloper << endl;
    int r,l;
    float r2;
    for (int i = 1; i < m; i++) {
    	if (slopel == 0) l = 0;
    	else l = i/slopel;
    	if (sloper == 0) r = p;
    	else {
    		r = (i-b)/sloper;
    		r2 = (i-b)/sloper;
    	}	
    	//cout << r2 << endl;
    	ans += r-l;
    	if (r2 == r || sloper == 0) ans--;
    	//cout << i << " " << l << " " << r << endl;
    	
    }
    fout << ans << endl;
    
    return 0;
}