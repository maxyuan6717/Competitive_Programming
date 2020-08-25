/*
ID: yuanmax1
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ifstream fin ("skidesign.in");
    ofstream fout ("skidesign.out");
    int N=0;
    fin >> N;
    int hills[N];
    for (int i = 0; i< N; i++) {
    	fin >> hills[i];
    }
    int diff1;
	int cost3 = 0;
    for (int x = 0;x < N; x++) {
		for (int y = 0; y < N-1; y++) {
			if (hills[y]>hills[y+1])
            {
                int z=hills[y];
                hills[y]=hills[y+1];
                hills[y+1]=z;             
            }			
		}		
	}
	/*for (int i = 0; i < N; i++) {
		cout << hills[i] << endl;
	}*/
	int sum1 = 0;
	
	int average1;
	for (int i = 0; i< N; i++) {
		sum1+= hills[i];
	}
	//cout << sum1 << endl;
	average1 = sum1/N;
	int num = average1;
	int ans = 10000000;
	
	for (int j = -5; j < 6; j++) { 
	average1 = num; 
	average1 += j;
	//cout << average1 << endl;
	int cost1 = 0;
	int cost2 = 0;
	for (int i = 0; i < (N-1)/2; i++) {
		diff1 = hills[N-i-1]-hills[i];
		//cout << diff << " " << i << endl;
		//cout << hills[i] << " " << hills[N-i-1] << endl;
		//if (diff1 > 17) {
			
			int low1 = average1 - 9;
			int high1 = average1 + 8;
			int low2 = average1 - 8;
			int high2 = average1 + 9;
			if (hills[i] < low1) {
				cost1 += pow(low1-hills[i],2);
			}
			if (hills[N-i-1] > high1) {
				cost1 += pow(hills[N-i-1]-high1,2);
				
			}
			if (hills[i] < low2) {
				cost2 += pow(low2-hills[i],2) ;
			
			}
			if (hills[N-i-1] > high2) {
				cost2 += pow(hills[N-i-1]-high2,2);
			}
			if (cost1 < cost2) {
				cost3 = cost1;
			}
			else {
				cost3 = cost2;
			}
			
			
		//}
		
	}
	//cout << cost1 << " " << cost2 << endl;
	//cout << cost3 << endl;
	if (cost3 < ans) {
		ans = cost3;
		}
	}
	cout << ans << endl;
	fout << ans << endl;
    return 0;
}