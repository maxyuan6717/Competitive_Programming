/*
ID: yuanmax1
PROG: fence
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;
int F;
int map[501][501];
int d[501] = {0};
string ans = "";
string toi(int x)
{
   stringstream ss;
   ss << x;
   return ss.str();
}
void f(int a) {
	string str;
	if (d[a]==0) {
		str = toi(a);
		reverse(str.begin(), str.end());
		ans+=str + " ";
	} 
	else {
		for (int i = 1; i < 501; i++) {
			if (map[a][i] > 0) {
				map[a][i]--;
				map[i][a]--;
				d[a]--;
				d[i]--;
				f(i);
			}
		}
		str = toi(a);
		reverse(str.begin(), str.end());
		ans+=str + " ";
	}
}
int main() {
    ofstream fout ("fence.out");
    ifstream fin ("fence.in");
    fin >> F;
    int x, y;
    for (int i = 0; i < F; i++) {
    	fin >> x >> y;
    	map[x][y]++;
    	map[y][x]++;
    	d[x]++;
    	d[y]++;
    }
    for (int i = 1; i < 501; i++) {
    	if (d[i] % 2 != 0) {
    		f(i);
    		break;
    	}
    	else if (i == 500) {
    		f(1);
    	}
    }
    //cout << ans << endl;
    reverse(ans.begin(),ans.end());
    //cout << ans << endl;
    for (int i = 0; i < ans.size(); i++) {
    	if (ans[i] != ' ') fout << ans[i];
    	else if (i!= 0) fout << endl;
    }
    fout << endl;
    
    
    return 0;
}