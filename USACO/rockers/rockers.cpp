/*
ID: yuanmax1
PROG: rockers
LANG: C++
*/
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


using namespace std;

int main() {
    ofstream fout ("rockers.out");
    ifstream fin ("rockers.in");
    int N,T,M;
    fin >> N >> T >> M;
    int songs[N];
    int total = 0;
    for (int i = 0; i < N; i++) {
    	int num;
    	fin >> num;
    	if (num <= T) {
    		songs[i] = num;
    		total++;
    	}	
	}
	
    
    return 0;
}