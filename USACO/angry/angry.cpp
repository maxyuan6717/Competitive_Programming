/*
ID: yuanmax1
PROG: angry
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int N;
int hay[100] = {0};
int ans = 1;
int tot = 1;
int radius = 0;

void explode(int n, int r) {
	if (n == 0) {
		if (hay[1]-hay[0] == 1) {
			explode(1,2);
		}
	}
	else if (n == (N-1)) {
		if (hay[N-1] - hay[N-2] ==
	}
	else {
	
	}
}

int main() {
    ofstream fout ("angry.out");
    ifstream fin ("angry.in");
    fin >> N;
    int num;
    for (int i = 0; i < N; i++) {
    	fin >> num;
    	hay[i] = num;
    }
    sort(hay,hay+N);
    for (int i = 0; i < N; i++) {
    	
    }
    /*for (int i = 0; i < N; i++) {
    	cout << hay[i] << endl;
    }*/
    return 0;
}