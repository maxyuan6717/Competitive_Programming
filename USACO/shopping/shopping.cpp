/*
ID: yuanmax1
PROG: shopping
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int count1[5];

int check() {
	for (int i = 0; i < 5; i++) {
		if (count1[i] > 5) return 0;
	}
	return 1;
}
int main() {
    ofstream fout ("shopping.out");
    ifstream fin ("shopping.in");
    int s;
    fin >> s;
    int n;
    int k,c;
    int of[100][1006] = {0};
    int goal[5] = {0};
    int pc[5] = {0};
    int pro[105] = {0};
    int pri[5] = {0};
    for (int i = 0; i < s; i++) {
    	fin >> n;
    	for (int j = 0; j < n; j++) {
    		fin >> c >> k;
    		//cout << c+5 << endl;
    		of[i][c+5] = k;
    	}
    	fin >> pro[i];
    }
    int b;
    fin >> b;
    int p;
    for (int i = 0; i < b; i++) {
    	fin >> c >> k >> p;
    	pc[i] = c;
    	goal[i] = k;
    	pri[i] = p;
    }
	//cout << of[0][12] << endl;
    for (int i = 0; i < s; i++) {
    	for (int j = 0; j < b; j++) {
    		of[i][j] = of[i][pc[j]+5];
    	}
    }
    for (int i = 0; i < b; i++) {
    	pro[s+i] = pri[i];
    	of[s+i][i] = 1;
    }

    //cout << of[0][0] << endl;
    int dp[6][6][6][6][6];
    for (int a1 = 0; a1 < 6; a1++) {
    	for (int a2 = 0; a2 < 6; a2++) {
    		for (int a3 = 0; a3 < 6; a3++) {
    			for (int a4 = 0; a4 < 6; a4++) {
 					for (int a5 = 0; a5 < 6; a5++) {
 						dp[a1][a2][a3][a4][a5] = 10000000;
 					}
 				}
 			}
 		}
 	}				
    //cout << dp[0][1][0][0][0] << endl;
    dp[0][0][0][0][0] = 0;
    int counter = 1;
    int num;
    int cur;
    for (int i = 0; i < s+b; i++) {
    	for (int a1 = 0; a1 < 6; a1++) {
    		for (int a2 = 0; a2 < 6; a2++) {
    			for (int a3 = 0; a3 < 6; a3++) {
    				for (int a4 = 0; a4 < 6; a4++) {
 						for (int a5 = 0; a5 < 6; a5++) {
 							
    						if (dp[a1][a2][a3][a4][a5] > 600000) continue;
    						//cout << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << endl;
    						counter = 1;
    						count1[0] = a1+of[i][0];
    						count1[1] = a2+of[i][1];
    						count1[2] = a3+of[i][2];
    						count1[3] = a4+of[i][3];
    						count1[4] = a5+of[i][4];
    						//cout << count1[0] << " " << count1[0] << " " << count1[0] << " " << count1[0] << " " << count1[0] << endl;
    						while (check()) {
    							num = dp[count1[0]][count1[1]][count1[2]][count1[3]][count1[4]];
    							cur = dp[a1][a2][a3][a4][a5];
    							dp[count1[0]][count1[1]][count1[2]][count1[3]][count1[4]] = min(num,cur+counter*pro[i]);
    							counter++;
    							count1[0] += of[i][0];
    							count1[1] += of[i][1];
    							count1[2] += of[i][2];
    							count1[3] += of[i][3];
    							count1[4] += of[i][4];	
    							//cout << i << endl;	
    							//cout << count1[0] << " " << count1[0] << " " << count1[0] << " " << count1[0] << " " << count1[0] << endl;		
    						}
    					}   	
   		 			}
    			}
    		}
    	}
    }
    fout << dp[goal[0]][goal[1]][goal[2]][goal[3]][goal[4]] << endl;
    return 0;
}
