/*
ID: yuanmax1
PROG: fact4
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int N;
int dig(int x) {
	while (x%10 == 0) {
		x/=10;
	}
	return x;
}
int main() {
    ofstream fout ("fact4.out");
    ifstream fin ("fact4.in");
    fin >> N;
    int ans = 1;
    for (int i = 2; i <= N; i++) {
    	ans = dig(ans*i%100000);
    }
    fout << ans%10 << endl;
    return 0;
}