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
    ofstream fout ("cowsignal.out");
    ifstream fin ("cowsignal.in");
    int M, N, K;
    fin >> M >> N >> K;
    string str;
    for (int i = 0; i < M; i++) {
    	fin >> str;
    	for (int y = 0; y < K; y++) {
    	for (int j = 0; j < N; j++) {
    		for (int x = 0; x < K; x++) {
    			fout << str[j];
    		}
    	}
    	fout << endl;
    	}
    }
    return 0;
}