/*
ID: yuanmax1
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
string toBinary(int a) {
  string res;
  do {
  	res.push_back( '0' + (a & 1) ); 	
  }while (a >>= 1);
  reverse( res.begin(), res.end() );
  return res;
}
int check(string a, string b) {
	int difference = 0;
	if (a.size() > b.size()) {
		while (a.size() > b.size()) {
			b = "0" + b;
		}
	}
	else if (a.size() < b.size()) {
		while (a.size() < b.size()) {
			a = "0" + a;
		}
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			difference++;
		}
	}
	return difference;
	
}
int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    int N, B, D;
    fin >> N >> B >> D;
    int ans[N];
    int counter = 0;
    int start = 1;
    int add = 1;
    for (int i = 0; i < N; i++) {
    	ans[i] = 0;
    }
    for (int i = 0; i < pow(2,B); i++) {
    	if (start == 1) {
    		ans[0] = i;
    		start = 0;
    		counter++;
    	}
    	else {
    		for (int j = 0; j < counter; j++) {
    			if (check(toBinary(i),toBinary(ans[j])) < D) {
    				add = 0;
    			}
    		}
    		if (add == 1) {
    			ans[counter] = i;
    			counter++;
    		}
    		add = 1;
    		if (counter == N) {
    			break;
    		}
    	}
    }
   		fout << "0" << " ";
   		for (int i = 1; i < N; i++) {
   			if (i%10 != 0 && i!= N-1 && i%10 != 9) {
   				fout << ans[i] << " ";
   			}
   			else if (i%10 == 9) {
   				fout << ans[i] << endl;
   			}
   			else if (i%10 == 0) {
   				fout << ans[i] << " ";
   			}
   			else {
   				fout << ans[N-1] << endl;
   			}
   		}
   			
   		
   	
   	/*else {
   		for (int i = 0; i < N-1; i++) {
   			cout << ans[i] << " ";
   		}
   		cout << ans[N-1] << endl;
   	}*/
   	
    return 0;
}