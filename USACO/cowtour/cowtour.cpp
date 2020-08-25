/*
ID: yuanmax1
PROG: cowtour
LANG: C++
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int N;
int pas[151][2];
int path[151][151];
double dis[151][151];
double far[151];
double ans;
#define LARGE 999999.0

double dist(int a, int b) {
	return sqrt(pow(pas[a][0]-pas[b][0],2) + pow(pas[a][1]-pas[b][1],2));
}
void fw() {
	for (int i = 0; i < N; i++) {
		dis[i][i] = 0.0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			 for (int k = 0; k < N; k++) {
			 	if (dis[i][k] + dis[k][j] < dis[i][j]) {
			 		dis[i][j] = dis[i][k] + dis[k][j];
			 		dis[j][i] = dis[i][j];
			 	}
			 }
		}
	}
}

int main() {
    ofstream fout ("cowtour.out");
    ifstream fin ("cowtour.in");
    string str;
    int num;
    fin >> N;
    for (int i = 0; i < N; i++) {
    	fin >> pas[i][0] >> pas[i][1];
    }
    for (int i = 0; i < N; i++) {
    	fin >> str;
    	//cout << str << endl;
    	for (int j = 0; j < N; j++) {
    		//cout << str[j] << endl;
    		num = str[j]-48;
    		path[i][j] = num;
    		if (num == 1) {
    			dis[i][j] = dist(i,j);
    			dis[j][i] = dis[i][j];
    		}
    		else {
    			dis[i][j] = LARGE;
    			dis[j][i] = dis[i][j];
    		}
    		//cout << dis[i][j] << " ";
    	}
    	//cout << endl;
    }
    fw();
    ans = LARGE;
    for (int i = 0; i < N; i++) {
    	far[i] = 0.0;
    	for (int j = 0; j < N; j++) {
    		if (dis[i][j] < LARGE) {
    			far[i] = max(far[i],dis[i][j]);
    		}
    	}
    }
    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < N; j++) {
    		if (dis[i][j] >= LARGE) {
    			double temp = dist(i,j);
    			double tempd = 0.0;
    			for (int k = 0; k < N; k++) {
    				if (dis[k][i] < LARGE) {
    					tempd = max(tempd, max(far[k], dis[k][i]+temp+far[j]));
    				}
    				if (dis[k][j] < LARGE) {
    					tempd = max(tempd, max(far[k], dis[k][j]+temp+far[i]));
    				}
    			}
    			ans = min(ans, tempd);
    		}
    	}
    }
    /*for (int i = 0; i < N; i++) {
    	for (int j = 0; j < N; j++) {
    		cout << dis[i][j] << " ";
    	}
    	cout << endl;
    }*/
    fout << fixed << setprecision(6) << ans << endl;
    
    
    return 0;
}