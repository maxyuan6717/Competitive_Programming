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
#include <utility>
#include <bitset>

#define LARGE (1<<31)-1

using namespace std;

string toBin (string sHex) {
	string ret = "";
	for (int i = 0; i < sHex.length (); ++i) {
		switch (sHex [i]) {
			case '0': ret += "0000"; break;
			case '1': ret += "0001"; break;
			case '2': ret += "0010"; break;
			case '3': ret += "0011"; break;
			case '4': ret += "0100"; break;
			case '5': ret += "0101"; break;
			case '6': ret += "0110"; break;
			case '7': ret += "0111"; break;
			case '8': ret += "1000"; break;
			case '9': ret += "1001"; break;
			case 'a': ret += "1010"; break;
			case 'b': ret += "1011"; break;
			case 'c': ret += "1100"; break;
			case 'd': ret += "1101"; break;
			case 'e': ret += "1110"; break;
			case 'f': ret += "1111"; break;
		}
	}
	return ret;
}

int H,W;
int arr[201][201];
int colored[201][201];
int caseNum = 1;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
char ans[6] = {'W','A','K','J','S','D'};
vector<char> ansstr;
map<int,int> wcounter;
map<int,set<int> > wcc;
int holes = 0;

bool inbounds(int r, int c) {
	return (r >= 0 && r < H && c >= 0 && c < W);
}

void flood2(int cr, int cc, int color) {
	colored[cr][cc] = color;
	for (int i = 0; i < 4; i++) {
		int nr = cr+dr[i];
		int nc = cc+dc[i];
		if (!inbounds(nr,nc)) continue;
		if (arr[nr][nc] || colored[nr][nc]) continue;
		flood2(nr,nc,color);
	}
}

void flood1(int cr, int cc, int color){
	colored[cr][cc] = color;
	for (int i = 0; i < 4; i++) {
		int nr = cr + dr[i];
		int nc = cc + dc[i];
		if (!inbounds(nr,nc)) continue;
		if (colored[nr][nc]) continue;
		if (!arr[nr][nc]){
			holes++;
			flood2(nr,nc,-1);
		}
		flood1(nr,nc,color);
	}
}

int main() {
	ifstream fin("test");
    cin >> H >> W;
    while (H || W) {
    	ansstr.clear();
    	for (int i = 0; i < H; i++) {
    		string s;
    		cin >> s;
    		string bin = toBin(s);
    		for (int j = 0; j < bin.size(); j++) {
    			arr[i][j] = (bin[j] == '1');
    			colored[i][j] = 0;
    			//cout << arr[i][j];
    		}
    		//cout << endl;
    	}
    	W *= 4;
    	for (int i = 0; i < H; i++) {
    		if (!arr[i][0] && !colored[i][0]) {
    			flood2(i,0,-1);
    		}
    		if (!arr[i][W-1] && !colored[i][W-1]) {
    			flood2(i,W-1,-1);
    		}
    	}
    	for (int i = 0; i < W; i++) {
    		if (!arr[0][i] && !colored[0][i]) {
    			flood2(0,i,-1);
    		}
    		if (!arr[H-1][i] && !colored[H-1][i]) {
    			flood2(H-1,i,-1);
    		}
    	}
    	int curColor = 1;
    	for (int i = 0; i < H; i++) {
    		for (int j = 0; j < W; j++) {
    			if (!arr[i][j] || colored[i][j]) continue;
    			holes = 0;
    			flood1(i,j,curColor);
    			ansstr.push_back(ans[holes]);
    			curColor++;
    		}
    	}
    	sort(ansstr.begin(),ansstr.end());
    	cout << "Case " << caseNum << ": ";
    	for (int i = 0; i < ansstr.size(); i++) {
    		cout << ansstr[i];
    	}
    	cout << endl;
    	caseNum++;
    	cin >> H >> W;
    }
    return 0;
}
