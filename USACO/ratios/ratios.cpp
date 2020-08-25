/*
ID: yuanmax1
PROG: ratios
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("ratios.out");
    ifstream fin ("ratios.in");
    int t[3];
    int r[3][3];
    int s1,s2,s3;
    int num;
    fin >> t[0] >> t[1] >> t[2];
    for (int i = 0; i < 3; i++) {
    	fin >> r[i][0] >> r[i][1] >> r[i][2];
    }
    for (int i = 0; i < 100; i++) {
    	for (int j = 0; j < 100; j++) {
    		for (int k = 0; k < 100; k++) {
    			s1 = i * r[0][0] + j * r[1][0] + k*r[2][0];
    			s2 = i * r[0][1] + j * r[1][1] + k*r[2][1];
    			s3 = i * r[0][2] + j * r[1][2] + k*r[2][2];
    			if (t[0] != 0) {
    				if (s1 % t[0] == 0) {
    					num = s1 / t[0];
    					if (t[1] != 0) {
    						if (s2 % t[1] == 0 && s2 / t[1] == num) {
    							if (t[2] != 0) {
    								if (s3 % t[2] == 0 && s3 / t[2] == num && !(i == 0 && j == 0 && k ==0)) {
    									//cout << i << " " << j << " " << k << " " << num << endl;
    									fout << i << " " << j << " " << k << " " << num << endl;
    									return 0;
    								}
    							}
    							else {
    								if (s3 == 0&& !(i == 0 && j == 0 && k ==0)) {
    									//cout << i << " " << j << " " << k << " " << num << endl;
    									fout << i << " " << j << " " << k << " " << num << endl;
    									return 0;
    								}
    							}
    						}
    					}
    					else {
    						if (s2 == 0) {
    							if (t[2] != 0) {
    								if (s3 % t[2] == 0 && s3 / t[2] == num&& !(i == 0 && j == 0 && k ==0)) {
    									//cout << i << " " << j << " " << k << " " << num << endl;
    									fout << i << " " << j << " " << k << " " << num << endl;
    									return 0;
    								}
    							}
    							else {
    								if (s3 == 0&& !(i == 0 && j == 0 && k ==0)) {
    									//cout << i << " " << j << " " << k << " " << num << endl;
    									fout << i << " " << j << " " << k << " " << num << endl;
    									return 0;
    								}
    							}
    						}
    					}
    				}
    			}
    			else {
    				if (s1 == 0) {
    					if (t[1] != 0) {
    						if (s2 % t[1] == 0) {
    							num = s2/t[1];
    							if (t[2] != 0) {
    								if (s3 % t[2] == 0 && s3 / t[2] == num&& !(i == 0 && j == 0 && k ==0)) {
    									//cout << i << " " << j << " " << k << " " << num << endl;
    									fout << i << " " << j << " " << k << " " << num << endl;
    									return 0;
    								}
    							}
    							else {
    								if (s3 == 0&& !(i == 0 && j == 0 && k ==0)) {
    									//cout << i << " " << j << " " << k << " " << num << endl;
    									fout << i << " " << j << " " << k << " " << num << endl;
    									return 0;
    								}
    							}
    						}
    					}
    					else {
    						if (s2 == 0) {
    							if (t[2] != 0) {
    								if (s3 % t[2] == 0&& !(i == 0 && j == 0 && k ==0)) {
    									num = s3/t[2];
    									//cout << i << " " << j << " " << k << " " << num << endl;
    									fout << i << " " << j << " " << k << " " << num << endl;
    									return 0;
    								}
    							}
    							else {
    								if (s3 == 0&& !(i == 0 && j == 0 && k ==0)) {
    									//cout << i << " " << j << " " << k << " " << num << endl;
    									fout << i << " " << j << " " << k << " " << num << endl;
    									return 0;
    								}
    							}
    						}
    					}
    				}	
    			}
    		}
    	}
    }
    fout << "NONE" << endl;
    
    return 0;
}