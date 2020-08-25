/*
ID: yuanmax1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ofstream fout ("cowdance.out");
    ifstream fin ("cowdance.in");
    int N, mt;
    fin >> N >> mt;
    int c[N];
    int counter = 0;
    int num;
    int last = 0;
    for (int i = 0; i < N; i++) {
    	fin >> c[i];
    }
    priority_queue<int,vector<int>,greater<int> > q;
    for (int i = 1; i < N; i++) {
    	q = priority_queue<int,vector<int>,greater<int> >();
		counter = 0;
    	while (q.size() != i) {
    		q.push(c[counter]);
    		counter++;
    	}
    	while (counter < N) {
    		num = q.top();
    		q.pop();
    		q.push(c[counter] + num);
    		counter++;
    	}
    	while (q.size() > 1) q.pop();
    	last = q.top();
    	if (last <= mt) {
    		fout << i << endl;
    		return 0;
    	}	
    	
    }
    fout << N << endl;
    
    return 0;
}