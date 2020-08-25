/*
ID: yuanmax1
PROG: camelot
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int R,C;
char a;
int b;
int king[2];
int knight[780][2] = {0};
int kn = 0;
int kndist[31][27][31][27];
int kndist2[31][27];
int kidist[31][27];
int movesc[8] = {2,2,-2,-2,1,1,-1,-1};
int movesr[8] = {1,-1,1,-1,2,-2,2,-2};
int ans = 999999;
int sum1 = 0;

int inboard(int y, int x) {
	if (y < R && y >= 0 && x < C && x >= 0) return 1;
	else return 0;	
}

void bfs(int y, int x, int k) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			kndist[y][x][i][j] = 10000;
		}
	}
	queue<int> qx;
	qx.push(x);
	queue<int> qy;
	qy.push(y);
	kndist[y][x][y][x] = 0;
	int tempy, tempx;
	int ny,nx;
	while (!qx.empty() && !qy.empty()) {
		ny = qy.front();
		qy.pop();
		nx = qx.front();
		qx.pop();
		for (int i = 0; i < 8; i++) {
			tempy = ny + movesc[i];
			tempx = nx + movesr[i];
			if (inboard(tempy,tempx) && kndist[y][x][tempy][tempx]== 10000) {
				kndist[y][x][tempy][tempx] = kndist[y][x][ny][nx] + 1;
				qx.push(tempx);
				qy.push(tempy);
			}	
		}
	}
}
void bfsk(int y, int x) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			kndist2[i][j] = 10000;
		}
	}
	queue<int> qx;
	qx.push(x);
	queue<int> qy;
	qy.push(y);
	kndist2[y][x] = 0;
	int tempy, tempx;
	int ny,nx;
	while (!qx.empty() && !qy.empty()) {
		ny = qy.front();
		qy.pop();
		nx = qx.front();
		qx.pop();
		for (int i = 0; i < 8; i++) {
			tempy = ny + movesc[i];
			tempx = nx + movesr[i];
			if (inboard(tempy,tempx) && kndist2[tempy][tempx]== 10000) {
				kndist2[tempy][tempx] = kndist2[ny][nx] + 1;
				qx.push(tempx);
				qy.push(tempy);
			}	
		}
	}
}

int main() {
    ofstream fout ("camelot.out");
    ifstream fin ("camelot.in");
    fin >> R >> C;
    fin >> a >> b;
    king[0] = b-1;
    king[1] = int(a)-65;
    while (fin>>a>>b) {
    	knight[kn][0] = b-1;
    	knight[kn][1] = int(a)-65;
    	kn++;
    }
    for (int i = 0; i < kn; i++) {
    	bfs(knight[i][0],knight[i][1],i);
    }
    bfsk(king[0],king[1]);
    for (int i = 0; i < R; i++) {
    	for (int j = 0; j < C; j++) {
    		kidist[i][j] = max(abs(i-king[0]),abs(j-king[1]));
    	}
    }
    int case1, case2, case3;
    for (int i = 0; i < R; i++) {
    	for (int j = 0; j < C; j++) {
    		sum1 = 0;
    		for (int k = 0; k < kn; k++) {
    			sum1 += kndist[knight[k][0]][knight[k][1]][i][j];
    		}
    		case1 = kidist[i][j] + sum1;
    		case2 = case1;
    		for (int k = 0; k < kn; k++) {
    			int temp = kndist2[i][j] + kndist[knight[k][0]][knight[k][1]][king[0]][king[1]];
    			case2 = min(case2,case1 - kndist[knight[k][0]][knight[k][1]][i][j] - kidist[i][j] + temp);
    		}
    		case3 = case1;
    		for (int k = 0; k < kn; k++) {
    			case3 = min(case3, case1 - kidist[i][j] + kidist[knight[k][0]][knight[k][1]]);
    		}
    		sum1 = min(min(case1,case2),case3);
    		if (sum1 < ans) ans = sum1;
    	}
    }
    fout << ans << endl;
    /*for (int i = 0; i < R; i++) {
    	for (int j = 0; j < C; j++) {
    		cout << kndist[knight[1][0]][knight[1][1]][i][j] << " ";
    	}
    	cout << endl;
    }*/
    
    
    return 0;
}