/*
ID: yuanmax1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int cow[2][25001];
int powr[25001];
int width;
int height;
int dist;


int main() {
    ofstream fout ("moocast.out");
    ifstream fin ("moocast.in");
    fin >> N;
    int ans = 0;
    int num = 0;
    
    for (int i = 0; i < N; i++) {
    	fin >> cow[0][i] >> cow[1][i] >> powr[i];
    	//cout << cow[0][i] << " " << cow[1][i] << " " << powr[i] << endl;
    }
    for (int i = 0; i < N; i++) {
    	for (int j = i+1; j < N; j++) {
    		width = pow(cow[0][i]-cow[0][j],2);
			height = pow(cow[1][i]-cow[1][j],2);
			dist = pow(width+height,0.5);
    		if (dist < powr[i]) {
    			num++;
    		}
    	}
    	ans += num;
    	num = 0;
    }
    
    fout << ans + 1<< endl;
    
    
    //cout << distance(0,1) << endl;
    
    
    
    return 0;
}