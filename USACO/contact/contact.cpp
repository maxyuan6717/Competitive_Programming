/*
ID: yuanmax1
PROG: contact
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>


using namespace std;
int ans[51];
int A, B, N;
string str = "";
string s;
int counter = 0;
 
int key[12] = {2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
int dec(string b){
    int num = 0;
    while(b.length() != 12){
    	b = "0" + b;
    }	
    for(int i = 0; i < b.length(); i++){
        if(b[i] == '1') {
        	num += key[i];
        }	
    }    
    return num;
}
string bin(int x, int y){
    char binary[12];
    memset(binary, '0', sizeof(binary));
    while(x > 0){
        for(int i = 0; i < 12; i++){
            if(x / key[i] > 0){
                binary[i] = '1';
                x %= key[i];
                break;
            }
        }
    }
    string s = binary;
    return s.substr(12 - y, y);
}
 
int main() {
    ofstream fout ("contact.out");
    ifstream fin ("contact.in");
    
    fin >> A >> B >> N;
    while (fin>>s) {
    	//fin >> s;
    	str += s;
    }
    
    int p[4096];
	vector<vector<string> > ans(200001);
    memset(p, 0, sizeof(p));
    for(int j = A; j <= B; j++){
        if(j > str.size()){
        	break;
        }	
        for(int i = 0; i < str.length() - j + 1; i++){
            p[dec(str.substr(i, j))]++;
        }
        for(int i = 0; i < 4096; i++){
            ans[p[i]].push_back(bin(i, j));
        }
        memset(p, 0, sizeof(p));
    }
    for(int i = ans.size() - 1; i > 0; i--){
        if(ans[i].size() == 0) {
        	continue;
        }	
        N--;
        if(N == -1) {
        	break;
        }	
        fout << i << endl;
        for(int j = 0; j < ans[i].size(); j++){
            fout << ans[i][j];
            if((j + 1) % 6 == 0 || j == ans[i].size() - 1){
                fout << endl;
            }
            else fout << " ";
        }
    }
    return 0;
}