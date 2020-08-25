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
    ofstream fout ("haybales.out");
    ifstream fin ("haybales.in");
    int N, Q;
    int hay[100001];
    //int que[2][100000] = {0};
    int num;
    int b;
    int e;
    int ans = 0;
    fin >> N >> Q;
   	for (int i = 1; i <= N; i++) {
   		fin >> hay[i];
   	}
   	sort(hay, hay+N+1);
   	int min;
   	int max;
   	int mid = 0;
   	int bn;
   	int en;
   	for (int i = 0; i < Q; i++) {
   		min = 0; 
   		max = N;
   		fin >> b >> e;
   		while (min!=max) {
   			//cout << min << " " << max << " " << mid << endl; 
   			mid = (min + max + 1)/2;
   			if (hay[mid] <= e) {
   				min = mid;
   			}
   			else {
   				max = mid -1;
   			}
   		}
   		en = min;
   		min = 0; 
   		max = N;
   		while (min!= max) {
   			//cout << min << " " << max << " " << mid << endl; 
   			mid = (min + max+1)/2;
   			if (hay[mid] <= b-1) {
   				min = mid;
   			}
   			else {
   				max = mid -1;
   			}
   			
   		}
   		bn = min;
   		//cout << en << " " << bn << endl;
   		ans = en-bn;
   		fout << ans << endl;
   		ans = 0;
   	}
   	
   	
    
    
    return 0;
}