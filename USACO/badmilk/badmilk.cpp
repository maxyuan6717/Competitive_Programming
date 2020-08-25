/*
ID: yuanmax1
PROG: CHANGE
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
int N, M, D, S;
int p, m, t;
int num;
int arr[51][51] = {0};
int milk[51][51] = {0};
int sick[51] = {0};
int sickp[51] = {0};
int poss[51] = {0};
int max1 = 0;
int stop = 0;
int stop2 = 0;
int counter = 0;
int peo=0;

bool check(int a, int b, int c) {
	for (int i = 1; i <= c; i++) {
		if (milk[a][i] == b) {
			return false;
		}
	}
	return true;
}

int main() {
	/*ifstream hi ("10.in");
	hi >> N >> M >> D >> S;
	cout << N << " " << M << " " << D << " "  << S << endl;
	for (int i = 0; i < D; i++) {
		hi >> p >> m >> t;
		cout << p << " " << m << " " << t  << " " << endl;
	}
	for (int i = 0; i < S; i++) {
		hi >> p >> t;
		cout << p << " " << t << " " << endl;
	}*/
    //for (int x = 1; x <= 10; x++) {
    	//string str = to_string(x);
    	//ifstream fin (str+".in");
    	ifstream fin ("badmilk.in");
    	ofstream fout ("badmilk.out");
    	fin >> N >> M >> D >> S;
    	for (int i = 0; i < D; i++) {
    		fin >> p >> m >> t;
    		if (arr[p][m] == 0) {
    			arr[p][m] = t;
    		}
    		if (check(p,m,M)) {
    			for (int j = 1; j <= M; j++) {
    				if (milk[p][j] == 0) {
    					milk[p][j] = m;
    					break;
    				}
    			}
    		}
    	}
    	for (int i = 1; i <= S; i++) {
    		fin >> p >> t;
    		sick[p] = t;
    		sickp[i] = p;
    	}
    	for (int i = 1; i <= M; i++) {
    		for (int j = 1; j <= S; j++) {
    			if (check(sickp[j], i, M)) {
    				stop = 1;
    				break;
    			}
    			
    			if (arr[sickp[j]][i] >= sick[sickp[j]]) {
    				
    				stop = 1;
    				//break;
    			}
    		}
    		if (stop == 0) {
    			
    			poss[counter] = i;
    			//cout << poss[counter] << endl;
    			counter++;
    		}
    		stop = 0;
    	}
    	for (int i = 0; i < counter; i++) {
    		for (int j = 0; j < N; j++) {
    		//cout << milk[j+1][poss[i]] <<" " << str << endl;
    			if ((check(j+1,poss[i],M) == 0)) {
    				
    				peo++;
    			}
    			/*else {
    				
    				stop2 = 1;
    				break;
    			}*/
    		}
    		if (stop2 == 0) {
    			if (peo > max1) {
    				max1 = peo;
    			}
    		}
    		stop2 = 0;
    		peo = 0;
    	}
    	fout << max1 << endl;
    	/*cout << max1 << " ";
    	ifstream gin (str+".out");
    	gin >> num;
    	cout << num << endl;
    	max1 = 0;
    	stop = 0;
    	stop2 = 0;
    	counter = 0;
    	peo = 0;
    	for (int i = 0; i < 51; i++) {
			sick[i] = 0;
			sickp[i] = 0;
			poss[i] = 0;
			for (int j = 0; j < 51; j++) {
				arr[i][j] = 0;
				milk[i][j] = 0;
			}
		}
    }*/
    
    return 0;
}