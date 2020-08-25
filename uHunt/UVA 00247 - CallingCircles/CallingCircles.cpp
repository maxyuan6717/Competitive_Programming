#include <iostream>
#include <cstdio>
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
#include <utility>
#include <bitset>

#define LARGE (1<<31)-1

using namespace std;

int N,M;
map<string,int> indx;
map<int,string> rindx;
int arr[26][26];
int vis[26];

int main() {
    cin >> N >> M;
    int dataset = 1;
    while (N || M) {
    	indx.clear();
    	rindx.clear();
    	int curindx = 1;
    	set<string> names;
    	if (dataset != 1) cout << endl;
    	for (int i = 0; i <= N; i++) {
    		for (int j = 0; j <= N; j++) {
    			arr[i][j] = 0;
    		}
    	}
    	for (int i = 0; i < M; i++) {
    		string s1,s2;
    		cin >> s1 >> s2;
    		if (names.find(s1) == names.end()) {
    			names.insert(s1);
    			indx[s1] = curindx;
    			rindx[curindx] = s1;
    			curindx++;
    		}
    		if (names.find(s2) == names.end()) {
    			names.insert(s2);
    			indx[s2] = curindx;
    			rindx[curindx] = s2;
    			curindx++;
    		}
    		int i1 = indx[s1];
    		int i2 = indx[s2];
    		arr[i1][i2] = 1;
    	}
    	N = curindx-1;
    	for (int i = 1; i <= N; i++) arr[i][i] = 1;
    	for (int k = 1; k <= N; k++) {
    		for (int i = 1; i <= N; i++) {
    			for (int j = 1; j <= N; j++) {
    				if (arr[i][k] && arr[k][j]) arr[i][j] = 1;
    			}
    		}
    	}
    	cout << "Calling circles for data set " << dataset << ":" << endl;
    	dataset++;
    	for (int i = 1; i <= N; i++) {
    		vis[i] = 0;
    	}
    	int works = 0;
    	for(int i = 1; i <= N; i++) {
    	   if(!vis[i]) {
    		   int cnt = 0;
    	   	   for(int j = 1; j <= N; j++) {
    		   	   if((!vis[j]) && arr[i][j] && arr[j][i]) {
    			   	   vis[j] = 1;
    			   	   vis[i] = 1;
    	               if(cnt) {
    	            	   cout << ", ";
    	               }
    	               cout << rindx[j];
    	               cnt++;
    	               works = 1;
    	            }
    	        }
    	        cout << endl;
    	    }
    	}
    	cin >> N >> M;
    }
    return 0;
}
